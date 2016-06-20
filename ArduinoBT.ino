/*
* - Toufik Zarouali
*   Bluetooth connection
*/

#include "Timer.h"


//Timer t;


#define LED   13;                                     // select the pin for the LED
#define RESET  7;                                    // BT module uses pin 7 for reset


void initBT()
{
  Serial.println("SET CONTROL BAUD 115200,8n1");
  Serial.println("SET BT NAME GKEEP");
  Serial.println("SET BT CLASS 001f00");                                                // No spaces allowed in the name; names can be up to 256 charcters.
  Serial.println("SET BT IDENT BT:47 f000 4.0.0 Bluegiga iWRAP");        // example
  Serial.println("SET BT LAP 9e8b33");
  Serial.println("SET BT PAGEMODE 4 2000 1");
  Serial.println("SET BT POWER 3 3 3");
  Serial.println("SET BT ROLE 0 f 7d00");
  Serial.println("SET BT SNIFF 0 20 1 8");
  Serial.println("SET BT MTU 667");
  Serial.println("SET BT SSP 3 0");                                                 // 00 == DTR bitmask; 1 == return to command mode when DTR dropped
  Serial.println("SET BT SNIFF 190 20 1 8 3");                             // And now the tricky configuration commands.                                                  // Change these only if you know what you're doing.
  Serial.println("SET BT CLASS 240428");                                                 // See the IWRAP manual for details.
  Serial.println("SET BT PAGEMODE 4 000 1");      // 3 == IWRAP visible and answers
  Serial.println("SET BT ROLE 0 f 7d00");          // 0 == allows master-slave switch when calling;
  Serial.println("SET CONTROL ESCAPE - 00 1");     // - == character to escape from comand mode to data mode;
  Serial.println("SET CONTROL CONFIG 0000 0000 0000 1100");
  Serial.println("SET BT AUTH * 0000");
  Serial.println("SET BT LAP 9e8b33");
  Serial.println("SET CONTROL READY 00");
  Serial.println("SET PROFILE SPP Bluetooth Serial Port");
  Serial.println("INQUIRY 8 LINK MD3484F00713");
  Serial.println("CALL E4:04:39:21:B9:C7 5 RFCOMM");
}

void setup() {
  pinMode(LED,OUTPUT);                            // declare the LED and BT RESET pins as output
  pinMode(RESET,OUTPUT);
  Serial.begin(115200);                           // connect to the serial port
  digitalWrite(RESET, HIGH);
  delay(10);
  digitalWrite(RESET, LOW);
  delay(2000);
  initBt();

t.every(1000, sendData);
}

void loop () {
  digitalWrite(LED, LOW);
}



void sendData()
{
 Serial.Println("HEllo");
}
