#include "Relay.h"                 //To know functions declarations of Relay Class.

//Sets the pin number for relay.
Relay& Relay::setPinNumber(uint8_t pin)
{
    this->pin = pin;
    return (*this);
}

//Returns the pin number.
uint8_t Relay::getPinNumber()
{
    return pin;
}



//Sets the pin mode as INPUT, INPUT_PULLUP or OUTPUT.
Relay& Relay::setPinMode(uint8_t mode)
{
    if      ( mode == INPUT )           pinMode(pin, INPUT);
    else if ( mode == INPUT_PULLUP )    pinMode(pin, INPUT_PULLUP);
    else if ( mode == OUTPUT )          pinMode(pin, OUTPUT);
    
    return (*this);
}



//Writes digital HIGH or digital LOW.
Relay& Relay::write(uint8_t val)
{
    ( val == HIGH )? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
    
    return (*this);
}




//Sets the status of the relay.
Relay& Relay::setStatus(bool status)
{
    this->status = status;
    return (*this);
}

//Returns the status of the relay.
uint8_t Relay::getStatus()
{
    return status;
}
