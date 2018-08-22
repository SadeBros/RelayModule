#include "Relay.h"                              //  To have Relay instance.

#ifndef RELAYMODULE_H
#define RELAYMODULE_H

class RelayModule {

private:
    uint8_t channelNumber;                      //  Specifies the number of channels on the card. (4 Channel Relay Module)
    uint8_t logicType;                          //  Specifies the logic type of Relay Module.
                                                //  If a relay on this card is activated with digitalWrite(pin, LOW), Relay Module is working with LOW logic.
    Relay* Relays = new Relay[channelNumber];   //  "Relays" consists of relays which are created in Relay Module constructor.
    
public:
    
    RelayModule(uint8_t channelNumber, uint8_t logicType):
        channelNumber(channelNumber),
        logicType(logicType)
    {
        for(int i=0; i<channelNumber; i++)
            Relays[i] = *( new Relay() );       //   A new relay is created in HEAP memory and it is assigned to the Relays[i].
    };

    void    setChannelNumber(uint8_t number)    { channelNumber = number;   }
    uint8_t getChannelNumber() const            { return channelNumber;     }
    
    
    void    setLogicType(uint8_t type)          { logicType = type;     }
    uint8_t getLogicType() const                { return logicType;     }
    
    
    
    bool active(uint8_t relayNumber);           //  Activates the specified relay in the "Relays" array.
    bool activeAll();                           //  Activates all the relays in the "Relays" array.
    
    bool deactive(uint8_t relayNumber);         //  Deactivates the specified relay in the "Relays" array.
    bool deactiveAll();                         //  Deactivates all the relays in the "Relays" array.
    
    uint8_t getStatus(int relayNumber = -1);    //  Returns the status of relays as integer.
                                                //                                  Relay4  Relay3  Relay2  Relay1
                                                //  As an example,                     1       0       1      0    specifies that Relay4 and Relay2 is active.
                                                //  At Base 2,                   1x(2^3) + 0x(2^2) + 1x(2^1) + 0x(2^0)
                                                //  15 = 8 + 4 + 2 + 1      All relays are active.
                                                //  6  = 0 + 4 + 2 + 0      Relay 2 and 3 are active.
                                                //  7  = 0 + 4 + 2 + 1      Relay 2, 3 and 4 are active.
    
    Relay& operator[] (int index);              //  Relays is a 0-based index array. To reach first relay in this array, we would use RelayModule.Relays[0]
                                                //  We can also reach first relay in this array by using RelayModule[1] instead of RelayModule.Relays[0].
};


#endif /* RelayModule */
