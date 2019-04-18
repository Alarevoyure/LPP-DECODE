/******************************************************************************************
* Copyright 2019 Paul BLOCK
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************************/

/******************************************************************************************
*
* File:        LPPDecode.h
* Author:      Paul BLOCK
* Compagny:    Loegaux
* Website:     http://www.loegaux.fr
* E-mail:      contact@loegaux.fr
* 
******************************************************************************************/

#ifndef LPP_DECODE_V10_H
#define LPP_DECODE_V10_H

#include <Arduino.h>

/*
********************************************************************************************
* FUNCTION PORTOTYPES
********************************************************************************************
*/

int LPP_Digital(int testCanal, int GPIO);
float LPP_Analog(int testCanal);
float LPP_Analog1(int testCanal);
static void LPP_Decode();


#else
#error "LPP_DECODE_V10_H not defined"
#endif
