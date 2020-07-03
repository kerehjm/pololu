/* 
* Pin.h
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/


#ifndef __PIN_H__
#define __PIN_H__

enum ePinState: volatile uint8_t
{
    LOW,
    HIGH
};
enum ePinDir: volatile uint8_t
{
    INPUT,
    OUTPUT
};

class Pin : public iPin
{
//variables
public:
protected:
private:
    ePinId pin;

//functions
public:
    Pin();
	Pin(ePinId pinId);
	~Pin();
    void set();
    void reset();
    void toggle();
    void output();
    void input();
    bool is_pin_set();
    void setDir(ePinDir dir);
    void setState(ePinState state);
protected:
private:

}; //Pin

#endif //__PIN_H__
