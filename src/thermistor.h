/**
 * File with thermistor sensor object header
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
#ifndef THERMISTOR_H
#define THERMISTOR_H

#include <arduino.h>

//=======================================================================================
//Define name of sensors
//=======================================================================================
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 1
#define TEMP_SENSOR_3 2
#define TEMP_SENSOR_4 3
#define TEMP_SENSOR_5 4


class Thermistor
{
private:    
	int _pin; //ver
    uint8_t _sensor; //ver
public:
	Thermistor(int pin, int sensorNumber); //ver nomes variaveis 
	~Thermistor();

	float readTemp();
};

#endif