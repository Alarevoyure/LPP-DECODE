
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
******************************************************************************************/
int LPP_Digital(int testCanal, int GPIO)
{
int Control=0;
int Canal;
int Valeur;

  Canal = LMIC.frame[LMIC.dataBeg];
  Valeur = LMIC.frame[LMIC.dataBeg + 2];

  //Serial.print("LPP_Digital : "); Serial.print(Canal); Serial.print(" Valeur : ");  	// For debug only

  if (testCanal == Canal) {
     //Serial.print(Valeur); 								// For debug only						
     if (Valeur == 0) {
          digitalWrite(GPIO, LOW); 
          //Serial.print(" 0 sur GPIO : "); Serial.println(GPIO); 			// For debug only
          Control = 1;
     }
     if (Valeur == 0x64) { 
          digitalWrite(GPIO, HIGH);
          //Serial.print(" 1 sur GPIO : "); Serial.println(GPIO);   			// For debug only
          Control = 1;
     }
  }
  return Control;
}

/********************************************************************************************
* Description : this function reads on an analog Cayenne channel and returns the value sent
*
* Arguments   : testCanal    The Cayenne chanel to read
*               
*********************************************************************************************/
float LPP_Analog(int testCanal)
{
int Control=0;
int Canal;
float Valeur1;
float Valeur2;

  Canal = LMIC.frame[LMIC.dataBeg];
  Valeur1 = LMIC.frame[LMIC.dataBeg + 2];
  Valeur2 = (LMIC.frame[LMIC.dataBeg + 1]*256 + Valeur1)/100;

  //Serial.print("LPP_Analog : "); Serial.print(Canal); Serial.print(" Valeur : "); Serial.println(Valeur2);  	// For debug only

  if (testCanal == Canal) {
	return Valeur2;
  } 

}

/*/////****************************************************************************************
* Description : 
*
* Arguments   : 
***********************************************************************************************/
static void LPP_Decode(unsigned char *Round_Key)
{
	
}

