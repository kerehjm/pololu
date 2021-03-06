/* 
* iPin.h
*
* Created: 18/05/2020 20:08:49
* Author: Mathew.Kuloba
*/


#ifndef __IPIN_H__
#define __IPIN_H__

enum class ePinId
{
    PB0_LCD_RW,
    PB1_LCD_DB4,
    PB2_BUZZER,
    PB3_MOTOR2_DIRECTION,
    PB4_LCD_DB5,
    PB5_LCD_DB6,
    PB6_XTAL1,
    PB7_XTAL2,
    PC0_SENSOR0,
    PC1_SENSOR1,
    PC2_SENSOR2,
    PC3_SENSOR3,
    PC4_SENSOR4,
    PC5_SENSOR_POWER,
    PC6_RESET,
    PD0_UART0_RXD,
    PD1_UART0_TXD,
    PD1_RED_LED,
    PD2_LCD_RS,
    PD3_MOTOR2_SPEED,
    PD4_LCD_ENABLE,
    PD5_MOTOR1_SPEED,
    PD6_MOTOR1_DIRECTION,
    PD7_LCD_DB7,
    PD7_GREEN_LED
}; //ePinId

enum class ePinState: volatile uint8_t
{
    LOW,
    HIGH
};
enum class ePinDir: volatile uint8_t
{
    INPUT,
    OUTPUT
};

class iPin
{
//functions
public:
    static iPin * create(ePinId pinId, ePinDir pinDir, ePinState pinState);
    virtual ~iPin(){}
    virtual void set() = 0;
    virtual void reset() = 0;
    virtual void toggle() = 0;
    virtual void output() = 0;
    virtual void input() = 0;
    virtual bool isSet() = 0;

}; //iPin

#endif //__IPIN_H__
