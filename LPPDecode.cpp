
/******************************************************************************************
*
* File:        LPPDecode.cpp
* Author:      Paul BLOCK
* Compagny:    Loegaux
* Website:     http://www.loegaux.fr
* E-mail:      contact@loegaux.fr
*
******************************************************************************************/
#include "Arduino.h" 
#include <lmic.h>
#include "LPPDecode.h"

/******************************************************************************************
* Description : this function reads on a Cayenne channel and controls a GPIO
*
* Arguments   : testCanal    The Cayenne chanel use to change state
*               GPIO         The GPIO to control
*
* Returns 1 if the function has been enabled
* Returns 0 if the information is not for the good channel
******************************************************************************************/
int LPP_Digital(int testCanal, int GPIO)
{
int Control=0;
int Canal;
int Valeur;

  Canal = LMIC.frame[LMIC.dataBeg];
  if (testCanal == Canal) {
     Valeur = LMIC.frame[LMIC.dataBeg + 2];
     if (Valeur == 0) {
          digitalWrite(GPIO, LOW); 
          Control = 1;
     }
     if (Valeur == 0x64) { 
          digitalWrite(GPIO, HIGH);
          Control = 1;
     }
  }
  return Control;
}

/********************************************************************************************
* Description : this function reads on an analog Cayenne channel and returns the value sent
*
* Arguments   : testCanal    The Cayenne chanel to read
*               Value        The variable to modify, from 0 to 655,35  
* 
* Returns 1 if the function has been enabled
* Returns 0 if the information is not for the good channel           
*********************************************************************************************/
int LPP_Analog(int testCanal, float & Value)
{
int Control=0;
int Canal;
float Valeur1;
float Valeur2;

  Canal = LMIC.frame[LMIC.dataBeg];
  if (testCanal == Canal) {
      Valeur1 = LMIC.frame[LMIC.dataBeg + 2];
      Valeur2 = (LMIC.frame[LMIC.dataBeg + 1]*256 + Valeur1)/100;
      Value = Valeur2;
      Control=1;
  } 
  return Control;
}

/********************************************************************************************
* Description : this function reads on an analog Cayenne channel and returns the value sent
*
* Arguments   : testCanal    The Cayenne chanel to read
*               Value        The variable to modify, from -327,67 to 327,67  
* 
* Returns 1 if the function has been enabled
* Returns 0 if the information is not for the good channel         
*********************************************************************************************/
int LPP_Analog1(int testCanal, float & Value)
{
int Control=0;
int Canal;
float Valeur1;
float Valeur2;

  Canal = LMIC.frame[LMIC.dataBeg];
  if (testCanal == Canal) {
     Valeur1 = LMIC.frame[LMIC.dataBeg + 2];
     Valeur2 = (LMIC.frame[LMIC.dataBeg + 1]*256 + Valeur1)/100;
     if (Valeur2>327.67) {
        Valeur2 = Valeur2-655.36;
     }
     Value = Valeur2;
     Control=1;
  } 
  return Control;
}

/*/////****************************************************************************************
* Description : 
*
* Arguments   : 
***********************************************************************************************/
static void LPP_Decode(unsigned char *Round_Key)
{
	
}

