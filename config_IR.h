/*  
  OpenMQTTGateway  - ESP8266 or Arduino program for home automation 

   Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal  and a MQTT broker 
   Send and receiving command by MQTT
 
   This files enables to set your parameter for the infrared gateway 
  
    Copyright: (c)Florian ROBERT
  
    This file is part of OpenMQTTGateway.
    
    OpenMQTTGateway is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenMQTTGateway is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*-------------------IR topics & parameters----------------------*/
//IR MQTT Subjects
#define subjectGTWIRtoMQTT  Base_Topic Gateway_Name "/IRtoMQTT"
#define subjectIRtoMQTT  Base_Topic Gateway_Name "/IRtoMQTT"
#define subjectMQTTtoIR  Base_Topic Gateway_Name "/commands/MQTTtoIR"
#define subjectIRtoMQTTprotocol  Base_Topic Gateway_Name "/IRtoMQTT/protocol"
#define subjectIRtoMQTTbits  Base_Topic Gateway_Name "/IRtoMQTT/bits"
#define subjectIRtoMQTTRaw  Base_Topic Gateway_Name "/IRtoMQTT/raw"
// subject monitored to listen traffic processed by other gateways to store data and avoid ntuple
#define subjectMultiGTWIR "+/+/IRtoMQTT"
#define IRbitsKey "IRBITS_" // bits  will be defined if a subject contains IRbitsKey followed by a value of 2 digits
#define IRRptKey "RPT_" // repeats  will be defined if a subject contains IRRptKey followed by a value of 1 digit
#define repeatIRwMQTT false // do we repeat a received signal by using mqtt
#define RawDirectForward false // direct repeat of IR signal with raw data
#define RawFrequency 38 // raw frequency sending
//#define DumpMode true // uncomment so as to see big dumps of IR codes

#define pubIRunknownPrtcl false // key to avoid mqtt publication of unknown IR protocol (set to true if you want to publish unknown protocol)
#define PanasonicAddress      0x4004     // Panasonic address (Pre data) 

#ifdef ESP8266 //IR supported protocols on ESP8266, all supported per default
  #define IR_GC
  #define IR_Raw
  #define IR_COOLIX
  #define IR_Whynter
  #define IR_LG
  #define IR_Sony
  #define IR_DISH
  #define IR_RC5
  #define IR_RC6
  #define IR_Sharp
  #define IR_SAMSUNG
  #define IR_PANASONIC
  #define IR_RCMM
  #define IR_MITSUBISHI
  #define IR_GICABLE
  #define IR_MITSUBISHI2
  #define IR_LASERTAG
  #define IR_CARRIER_AC
  #define IR_MIDEA
  #define IR_NIKAI
  #define IR_SHERWOOD
  #define IR_DENON
  #define IR_AIWA_RC_T501
  #define IR_JVC
#elif ESP32
  #define IR_Raw
  #define IR_COOLIX
  #define IR_Whynter
  #define IR_Sony
  #define IR_LG
  #define IR_DISH
  #define IR_RC5
  #define IR_Sharp
  #define IR_SAMSUNG
  #define IR_PANASONIC
#else //IR supported protocols on arduino uncomment if you want to send with this protocol, NEC protocol is available per default
  //#define IR_COOLIX
  //#define IR_Whynter
  //#define IR_LG
  //#define IR_Sony
  //#define IR_DISH
  //#define IR_RC5
  //#define IR_Sharp
  //#define IR_SAMSUNG
  //#define IR_Raw
  //#define IR_PANASONIC
#endif

/*-------------------PIN DEFINITIONS----------------------*/
#ifdef ESP8266
  #define IR_RECEIVER_PIN 2
  #define IR_EMITTER_PIN 14 // replace by 0 if you use IR LOLIN controller shield
#elif ESP32
  #define IR_RECEIVER_PIN 27
  #define IR_EMITTER_PIN 14
#else
  #define IR_RECEIVER_PIN 0 // 0 = D2 on arduino
  #define IR_EMITTER_PIN 9
#endif
