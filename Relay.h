#include "stdlib.h"
#include "Arduino.h"

#ifndef RELAY_H
#define RELAY_H

class Relay{
private:
    uint8_t pin;
    uint8_t status;
public:
    
    Relay():status(0){};
    
    
    //Sets the pin number for relay.
    Relay& setPinNumber(uint8_t pin);
    //Returns the pin number.
    uint8_t getPinNumber();
    
    
    //Sets the pin mode as INPUT, INPUT_PULLUP or OUTPUT.
    Relay& setPinMode(uint8_t mode);
    //Writes digital HIGH or digital LOW.
    Relay& write(uint8_t val);
    
    
    //Sets the status of the relay.
    Relay& setStatus(bool status);
    //Returns the status of the relay.
    uint8_t getStatus();
    
};

#endif /* RELAY_H */
