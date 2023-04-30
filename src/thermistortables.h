/**
 * File with informations about thermistor tables
 * Modifications by Guilherme Ferreira Neto <guilhermefneto@gmail.com>
 * 
 * Based on Marlin 3D Printer Firmware
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

#ifndef THERMISTORTABLES_H_
#define THERMISTORTABLES_H_

//=======================================================================================
//Macros
//=======================================================================================
#define OV(N) int16_t((N)*(OVERSAMPLENR)) //Macro to change samples num at tables files

#define _TT_NAME(_N) temptable_ ## _N //Macro to add correct table variable name 
#define TT_NAME(_N) _TT_NAME(_N)

#define COUNT(a) (sizeof(a)/sizeof(*a)) //Macro to count size of thermistor table

//=======================================================================================
//Define Number of Sensor at for tables includes
//=======================================================================================
#if TYPE_TEMP_SENSOR_1 <0 
    #error "Sensor 1 - Table of temperature sensor not supported."
#elif TYPE_TEMP_SENSOR_1 == 0
    #define SENSOR_1_THERMISTOR_NOT_DEFINED
#elif TYPE_TEMP_SENSOR_1 > 0
  #define THERMISTOR_SENSOR_1 TYPE_TEMP_SENSOR_1
#endif

#if TYPE_TEMP_SENSOR_2 <0 
    #error "Sensor 2 - Table of temperature sensor not supported."
#elif TYPE_TEMP_SENSOR_2 == 0
    #define SENSOR_2_THERMISTOR_NOT_DEFINED
#elif TYPE_TEMP_SENSOR_2 > 0
  #define THERMISTOR_SENSOR_2 TYPE_TEMP_SENSOR_2
#endif

#if TYPE_TEMP_SENSOR_3 <0 
    #error "Sensor 3 - Table of temperature sensor not supported."
#elif TYPE_TEMP_SENSOR_3 == 0
    #define SENSOR_3_THERMISTOR_NOT_DEFINED
#elif TYPE_TEMP_SENSOR_3 > 0
  #define THERMISTOR_SENSOR_3 TYPE_TEMP_SENSOR_3
#endif

#if TYPE_TEMP_SENSOR_4 <0 
    #error "Sensor 4 - Table of temperature sensor not supported."
#elif TYPE_TEMP_SENSOR_4 == 0
    #define SENSOR_4_THERMISTOR_NOT_DEFINED
#elif TYPE_TEMP_SENSOR_4 > 0
  #define THERMISTOR_SENSOR_4 TYPE_TEMP_SENSOR_4
#endif

#if TYPE_TEMP_SENSOR_5 <0 
    #error "Sensor 5 - Table of temperature sensor not supported."
#elif TYPE_TEMP_SENSOR_5 == 0
    #define SENSOR_5_THERMISTOR_NOT_DEFINED
#elif TYPE_TEMP_SENSOR_5 > 0
  #define THERMISTOR_SENSOR_5 TEMP_SENSOR_5
#endif

//=======================================================================================
//Include Thermistor tables
//=======================================================================================
#define ANY_THERMISTOR_IS(n) (THERMISTOR_SENSOR_1 == n || THERMISTOR_SENSOR_2 == n || THERMISTOR_SENSOR_3 == n || THERMISTOR_SENSOR_4 == n || THERMISTOR_SENSOR_5 == n)

#if ANY_THERMISTOR_IS(1) // 100k bed thermistor
  #include "tables/thermistortable_1.h"
#endif
#if ANY_THERMISTOR_IS(2) // 200k bed thermistor
  #include "tables/thermistortable_2.h"
#endif
#if ANY_THERMISTOR_IS(3) // mendel-parts
  #include "tables/thermistortable_3.h"
#endif
#if ANY_THERMISTOR_IS(4) // 10k thermistor
  #include "tables/thermistortable_4.h"
#endif
#if ANY_THERMISTOR_IS(5) // 100k ParCan thermistor (104GT-2)
  #include "tables/thermistortable_5.h"
#endif
#if ANY_THERMISTOR_IS(501) // 100k Zonestar thermistor
  #include "tables/thermistortable_501.h"
#endif
#if ANY_THERMISTOR_IS(6) // 100k Epcos thermistor
  #include "tables/thermistortable_6.h"
#endif
#if ANY_THERMISTOR_IS(7) // 100k Honeywell 135-104LAG-J01
  #include "tables/thermistortable_7.h"
#endif
#if ANY_THERMISTOR_IS(71) // 100k Honeywell 135-104LAF-J01
  #include "tables/thermistortable_71.h"
#endif
#if ANY_THERMISTOR_IS(8) // 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
  #include "tables/thermistortable_8.h"
#endif
#if ANY_THERMISTOR_IS(9) // 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
  #include "tables/thermistortable_9.h"
#endif
#if ANY_THERMISTOR_IS(10) // 100k RS thermistor 198-961 (4.7k pullup)
  #include "tables/thermistortable_10.h"
#endif
#if ANY_THERMISTOR_IS(11) // QU-BD silicone bed QWG-104F-3950 thermistor
  #include "tables/thermistortable_11.h"
#endif
#if ANY_THERMISTOR_IS(13) // Hisens thermistor B25/50 =3950 +/-1%
  #include "tables/thermistortable_13.h"
#endif
#if ANY_THERMISTOR_IS(15) // JGAurora A5 thermistor calibration
  #include "tables/thermistortable_15.h"
#endif
#if ANY_THERMISTOR_IS(20) // PT100 with INA826 amp on Ultimaker v2.0 electronics
  #include "tables/thermistortable_20.h"
#endif
#if ANY_THERMISTOR_IS(51) // 100k EPCOS (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "tables/thermistortable_51.h"
#endif
#if ANY_THERMISTOR_IS(52) // 200k ATC Semitec 204GT-2 (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "tables/thermistortable_52.h"
#endif
#if ANY_THERMISTOR_IS(55) // 100k ATC Semitec 104GT-2 (Used on ParCan) (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "tables/thermistortable_55.h"
#endif
#if ANY_THERMISTOR_IS(60) // Maker's Tool Works Kapton Bed Thermistor
  #include "tables/thermistortable_60.h"
#endif
#if ANY_THERMISTOR_IS(66) // DyzeDesign 500°C Thermistor
  #include "tables/thermistortable_66.h"
#endif
#if ANY_THERMISTOR_IS(12) // 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibrated for Makibox hot bed)
  #include "tables/thermistortable_12.h"
#endif
#if ANY_THERMISTOR_IS(70) // bqh2 stock thermistor
  #include "tables/thermistortable_70.h"
#endif
#if ANY_THERMISTOR_IS(75) // Many of the generic silicon heat pads use the MGB18-104F39050L32 Thermistor
  #include "tables/thermistortable_75.h"
#endif
#if ANY_THERMISTOR_IS(110) // Pt100 with 1k0 pullup
  #include "tables/thermistortable_110.h"
#endif
#if ANY_THERMISTOR_IS(147) // Pt100 with 4k7 pullup
  #include "tables/thermistortable_147.h"
#endif
#if ANY_THERMISTOR_IS(1010) // Pt1000 with 1k0 pullup
  #include "tables/thermistortable_1010.h"
#endif
#if ANY_THERMISTOR_IS(1047) // Pt1000 with 4k7 pullup
  #include "tables/thermistortable_1047.h"
#endif
#if ANY_THERMISTOR_IS(998) // User-defined table 1
  #include "tables/thermistortable_998.h"
#endif
#if ANY_THERMISTOR_IS(999) // User-defined table 2
  #include "tables/thermistortable_999.h"
#endif

//=======================================================================================
//Link thermistor tables to sensors
//=======================================================================================
#if THERMISTOR_SENSOR_1
  #define SENSOR_1_TEMPTABLE TT_NAME(THERMISTOR_SENSOR_1)
  #define SENSOR_1_TEMPTABLE_LEN COUNT(SENSOR_1_TEMPTABLE)
#elif defined(SENSOR_1_THERMISTOR_NOT_DEFINED)
  #error "Sensor 1 - Table of thermistor not specified."
#else
  #define SENSOR_1_TEMPTABLE NULL
  #define SENSOR_1_TEMPTABLE_LEN 0
#endif

#if THERMISTOR_SENSOR_2
  #define SENSOR_2_TEMPTABLE TT_NAME(THERMISTOR_SENSOR_2)
  #define SENSOR_2_TEMPTABLE_LEN COUNT(SENSOR_2_TEMPTABLE)
#elif defined(SENSOR_2_THERMISTOR_NOT_DEFINED)
  #error "Sensor 2 - Table of thermistor not specified."
#else
  #define SENSOR_2_TEMPTABLE NULL
  #define SENSOR_2_TEMPTABLE_LEN 0
#endif

#if THERMISTOR_SENSOR_3
  #define SENSOR_3_TEMPTABLE TT_NAME(THERMISTOR_SENSOR_3)
  #define SENSOR_3_TEMPTABLE_LEN COUNT(SENSOR_3_TEMPTABLE)
#elif defined(SENSOR_3_THERMISTOR_NOT_DEFINED)
  #error "Sensor 3 - Table of thermistor not specified."
#else
  #define SENSOR_3_TEMPTABLE NULL
  #define SENSOR_3_TEMPTABLE_LEN 0
#endif

#if THERMISTOR_SENSOR_4
  #define SENSOR_4_TEMPTABLE TT_NAME(THERMISTOR_SENSOR_4)
  #define SENSOR_4_TEMPTABLE_LEN COUNT(SENSOR_4_TEMPTABLE)
#elif defined(SENSOR_4_THERMISTOR_NOT_DEFINED)
  #error "Sensor 4 - Table of thermistor not specified."
#else
  #define SENSOR_4_TEMPTABLE NULL
  #define SENSOR_4_TEMPTABLE_LEN 0
#endif

#if THERMISTOR_SENSOR_5
  #define SENSOR_5_TEMPTABLE TT_NAME(THERMISTOR_SENSOR_5)
  #define SENSOR_5_TEMPTABLE_LEN COUNT(SENSOR_5_TEMPTABLE)
#elif defined(SENSOR_5_THERMISTOR_NOT_DEFINED)
  #error "Sensor 5 - Table of thermistor not specified."
#else
  #define SENSOR_5_TEMPTABLE NULL
  #define SENSOR_5_TEMPTABLE_LEN 0
#endif

#endif //THERMISTORTABLES_H_
