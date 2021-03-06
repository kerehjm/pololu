/* 
* ProximitySensor.cpp
*
* Created: 16/05/2020 11:26:19
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include <util/delay.h>
#include "iTimer.hpp"
#include "iSensor.hpp"
#include "iPin.hpp"
#include "proximitySensor.hpp"

// default constructor
ProximitySensor::ProximitySensor(iPin *pin, iPin * power, iTimer<uint16_t> * timer)
{
    this->sensor = sensor;
    this->power = power;
    this->timer = timer;
} //ProximitySensor

// default destructor
ProximitySensor::~ProximitySensor()
{
} //~ProximitySensor

SensorData ProximitySensor::read()
{
    charge();
    _delay_us(10);
    discharge();
    uint16_t readings[1];

    SensorData data(1, readings);
    return data;
}

void ProximitySensor::charge()
{
    sensor->set();
}

void ProximitySensor::discharge()
{
    sensor->reset();
}
