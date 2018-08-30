#include <RelayModule.h>
#include <Relay.h>
RelayModule module(4, LOW);     //  We have a global RelayModule instance in order to use it inside different functions. It has 4 relays and it is working with LOW logic.

void setup() {
  Serial.begin(9600);           //  BAUD rate is set to 9600.

  module[1].setPinNumber(5).setPinMode(OUTPUT);   //  1st relay (IN1) is connected to the Arduino's Digital5 pin. The green wire on the photo.
  module[2].setPinNumber(4).setPinMode(OUTPUT);   //  2nd relay (IN2) is connected to the Arduino's Digital4 pin. The brown wire on the photo.
  module[3].setPinNumber(3).setPinMode(OUTPUT);   //  3rd relay (IN3) is connected to the Arduino's Digital3 pin. The yellow wire on the photo.
  module[4].setPinNumber(2).setPinMode(OUTPUT);   //  4th relay (IN4) is connected to the Arduino's Digital2 pin. The orange wire on the photo.

  module.deactivateAll();         //  In the beginning, it is a good habit to tell the system what will it do. Assume that, here, we turned all the lights off.
}

void loop() {

  for (int relayNumber = 1; relayNumber <= module.getChannelNumber(); relayNumber++)
  {
    module.activate( relayNumber );
    ExplainRelayModuleStatus( module.getStatus() );
    ExplainEachRelayStatus();
    delay(1000);
    module.deactivate( relayNumber );
  }
}

//  module.getStatus() returns an integer which specifies the status of relays.
//  This integer number is produced by the multiplication of relay number order with 2.
//  Let's say, Relay1 and Relay3 is active.
//  Relay4  Relay3  Relay2  Relay1    ( This is the relay number order. )
//  0       1       0       1         ( Relay1 and Relay3 are active. 1 stand for active, 0 for deactive. )
//  0       1       0       1         ( If we write this binary number in decimal base, we get 5. (0101)binary = (5)decimal )

//  If we want to know which relay is actived and which is not, we must mask the given relay status number.
//  If I logically and relayModuleStatus with RelayMask, I may say which one is active or not.
int Relay4Mask = 8;   //  (1000)binary  = (8)decimal
int Relay3Mask = 4;   //  (0100)binary  = (4)decimal
int Relay2Mask = 2;   //  (0010)binary  = (2)decimal
int Relay1Mask = 1;   //  (0001)binary  = (1)decimal
void ExplainRelayModuleStatus(int relayModuleStatus )
{
  if( relayModuleStatus & Relay4Mask )  Serial.println("Relay4 is active");
  if( relayModuleStatus & Relay3Mask )  Serial.println("Relay3 is active");
  if( relayModuleStatus & Relay2Mask )  Serial.println("Relay2 is active");
  if( relayModuleStatus & Relay1Mask )  Serial.println("Relay1 is active");
}

//  Instead of getting the status of relay module as integer and mask it to decide which relay is active and which is not,
//    you can simply learn the status of each relay by " module[ relayNumber ].getStatus() ".   ( relayNumber should NOT be ZERO. )
void ExplainEachRelayStatus()
{
    for(int relayNumber=1; relayNumber <= module.getChannelNumber(); relayNumber++) //  relayNumber MUST start from 0 (zero).
      if( module[ relayNumber ].getStatus() )
        Serial.println("Relay " + String(relayNumber) + " is active.");
}
