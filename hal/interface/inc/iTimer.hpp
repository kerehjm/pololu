/* 
* iTimer.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMER_H__
#define __ITIMER_H__

class iTimer
{
//functions
public:
    virtual ~iTimer(){}
    virtual void start(uint8_t count) = 0;
    virtual void stop() = 0;
    virtual void reload(uint8_t count) = 0;
    virtual uint8_t getCount() = 0;
}; //iTimer

#endif //__ITIMER_H__
