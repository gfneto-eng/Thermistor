/**
 * File with thermistor sensor object class
 * Modifications by Guilherme Ferreira Neto <guilhermefneto@gmail.com>
 * 
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "thermistor.h"
#include "sensorsConfig.h"
#include "thermistortables.h"
          
//=======================================================================================
//Macros
//=======================================================================================
#define ARRAY_5(v1, v2, v3, v4, v5, ...)     { v1, v2, v3, v4, v5 }// Macros for initializing arrays
#define ARRAY_4(v1, v2, v3, v4, ...)         { v1, v2, v3, v4 }
#define ARRAY_3(v1, v2, v3, ...)             { v1, v2, v3 }
#define ARRAY_2(v1, v2, ...)                 { v1, v2 }
#define ARRAY_1(v1, ...)                     { v1 }

#define _ARRAY_N(N, ...) ARRAY_ ##N(__VA_ARGS__)
#define ARRAY_N(N, ...) _ARRAY_N(N, __VA_ARGS__)

#define ARRAY_BY_QTY_SENSORS(...) ARRAY_N(SENSORS_QTY, __VA_ARGS__)

#define PGM_RD_W(x)   (short)pgm_read_word(&x)// Macros for read temperature tables at memory

//=======================================================================================
//Goblal Variables
//=======================================================================================
static void *heater_ttbl_map[] = ARRAY_BY_QTY_SENSORS((void *)SENSOR_1_TEMPTABLE, (void *)SENSOR_2_TEMPTABLE, (void *)SENSOR_3_TEMPTABLE, (void *)SENSOR_4_TEMPTABLE, (void *)SENSOR_5_TEMPTABLE);
static uint8_t heater_ttbllen_map[] = ARRAY_BY_QTY_SENSORS(SENSOR_1_TEMPTABLE_LEN, SENSOR_2_TEMPTABLE_LEN, SENSOR_3_TEMPTABLE_LEN, SENSOR_4_TEMPTABLE_LEN, SENSOR_5_TEMPTABLE_LEN);

//=======================================================================================
//Public Functions
//=======================================================================================
Thermistor::Thermistor(int pin, int sensorNumber)
{
    _pin = pin;
    _sensor = sensorNumber;
    pinMode(pin, INPUT);
}

Thermistor::~Thermistor()
{
    //nothing to do here
}

float Thermistor::readTemp()
{
    float celsius = 0;
    int raw  =  0;

    for(int j=1;j<=OVERSAMPLENR;j++){
        raw += analogRead(_pin);
    }
   
    if(heater_ttbl_map[_sensor] != NULL)
    {
        uint8_t i;
        short (*tt)[][2] = (short (*)[][2])(heater_ttbl_map[_sensor]);

        for (i=1; i<heater_ttbllen_map[_sensor]; i++)
        {
            if (PGM_RD_W((*tt)[i][0]) > raw)
                {
                    celsius = PGM_RD_W((*tt)[i-1][1]) + 
                    (raw - PGM_RD_W((*tt)[i-1][0])) * 
                    (float)(PGM_RD_W((*tt)[i][1]) - PGM_RD_W((*tt)[i-1][1])) /
                    (float)(PGM_RD_W((*tt)[i][0]) - PGM_RD_W((*tt)[i-1][0]));
                    break;
                }
        }  

        // Overflow: Set to last value in the table
        if (i == heater_ttbllen_map[_sensor]) celsius = PGM_RD_W((*tt)[i-1][1]);
    }
    return celsius;
}