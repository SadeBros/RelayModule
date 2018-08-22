#include "RelayModule.h"            //To know function declarations of RelayModule Class.

//Activates specified relay in the "Relays" and sets the relay's status as 1.
//If RelayModule is working with LOW logic, we can activate a relay with digitalWrite(pin, LOW).
//So, we can send the logicType(in above case LOW) to the write function to make the relay active.
bool RelayModule::active(uint8_t relayNumber)
{
    Relays[ relayNumber-1 ].write(logicType).setStatus(1);
    
    return Relays[ relayNumber-1 ].getStatus();
}

//Activates all the relays on the Relay Module.
bool RelayModule::activeAll()
{
    for(uint8_t i=1; i <= channelNumber; i++)
        if ( ! active(i) ) return false;
    
    return true;
}



//Deactivates specified relay in the "Relays" and sets the relay's status as 0.
//If RelayModule is working with LOW logic, we can deactivate a relay with digitalWrite(pin, HIGH).
//So, we can send "the reverse of logicType(in above case HIGH)" to the write function to make the relay deactive.
bool RelayModule::deactive(uint8_t relayNumber)
{
    
    uint8_t close;
    
    (logicType == HIGH)? close=LOW : close=HIGH;
    
    Relays[relayNumber-1].write(close).setStatus(0);
    
    return ( Relays[ relayNumber-1 ].getStatus() ) ? false : true;      //  If relay's status is 0, then operation is successfull.
}

//Deactivates all the relays on the Relay Module.
bool RelayModule::deactiveAll()
{
    for(uint8_t i=1; i<=channelNumber; i++)
        if ( ! deactive(i) ) return false;
    
    return true;
}



//Returns the status of relays as integer.
//                                Relay4  Relay3  Relay2  Relay1
//As an example,                     1       0       1      0    specifies that Relay4 and Relay2 is active.
//  At Base 2,                   1x(2^3) + 0x(2^2) + 1x(2^1) + 0x(2^0)
//  15 = 8 + 4 + 2 + 1      All relays are active.
//  6  = 0 + 4 + 2 + 0      Relay 2 and 3 are active.
//  7  = 0 + 4 + 2 + 1      Relay 2, 3 and 4 are active.
//  4  = 0 + 4 + 0 + 0      Relay 3 is active.
//  1  = 0 + 0 + 0 + 1      Relay 1 is active.
uint8_t RelayModule::getStatus(int relayNumber)
{
    if ( relayNumber != -1 )    return Relays[ relayNumber ].getStatus();
        
    uint8_t status = 0;
    
    for(uint8_t i=0, digitValue = 1; i<channelNumber; i++, digitValue *= 2)
        status += (Relays[i].getStatus() * digitValue);
    
    return status;
}



//Relays is a 0-based index array. To reach first relay in this array, we would use RelayModule.Relays[0]
//We can also reach first relay in this array by using RelayModule[1] instead of RelayModule.Relays[0].
Relay& RelayModule::operator[](int index)
{
    return Relays[index-1];
}
