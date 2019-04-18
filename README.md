# LPP-DECODE
 This program is used to decode Cayenne messages using addAnalogOutput and addDigitalOutput
 
 For use with Arduino in this environment - Arduino + TTN + Cayenne.
 If you use Cayenne with TTN, you can use channels to send data from cayenne to your nodes.
 
 For sending Digital information you use addDigitalOutput - for example : lpp.addDigitalOutput(80,LED);
 For sending Analog information you use addAnalogOutput - for example : lpp.addAnalogOutput(81,0);
 
 LPP-DECODE may be use to decode message from Cayenne.
 
 LPP-DECODE offers 3 functions to read the data sent by Cayenne.
 
--- >  int LPP_Digital(int testCanal, int GPIO)
Description : this function reads on a Cayenne channel and controls a GPIO

 Arguments   : testCanal    The Cayenne chanel use to change state
               GPIO         The GPIO to control

 Returns 1 if the function has been enabled

--- >  float LPP_Analog(int testCanal)
 Description : this function reads on an analog Cayenne channel and returns the value sent

 Arguments   : testCanal    The Cayenne chanel to read
               
 Returns the value of the analog output. Min 0, max 655.35
 
 --- >  float LPP_Analog1(int testCanal)
 Description : this function reads on an analog Cayenne channel and returns the value sent

 Arguments   : testCanal    The Cayenne chanel to read
               
 Returns the value of the analog output. Min -327,69, max 327,67
 
 For example :
   
       case EV_TXCOMPLETE:
          // use this event to keep track of actual transmissions
          Serial.print("---------------->   Event EV_TXCOMPLETE, time: ");
          Serial.println(millis() / 1000);
          if (LMIC.txrxFlags & TXRX_ACK)
              Serial.println(F("-------------->>> Received ack"));
          if(LMIC.dataLen) { // data received in rx slot after tx
              Serial.print(F("Received ")); Serial.print(LMIC.dataLen); Serial.println(F(" bytes of payload"));
              if (LMIC.dataLen == 4) {
                LPP_Digital(11, 25);  // Read chanel 11 and write on GPIO 25.
                Serial.print("Valeur sur canal 81 : "); Serial.println(LPP_Analog(81));  //Read Value on chanel 81
              }
          }
          os_setTimedCallback(&sendjob, os_getTime() + sec2osticks(TimeToWait), do_send);
          break;
          
 For using this function in arduino, just do the following :
  - Create a directory in your arduino/librairies with name : LPP-Decode
  - Copy the two file in this directory
  - In you projet, add #include "LPPDecode.h"
  
