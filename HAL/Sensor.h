/*
 * Sensor.h
 *
 * Created: 4/25/2021 6:58:05 PM
 *  Author: lenovo
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include "DIO.h"
#include "Sensor_CFG.h"

#define Ind_Sensor   1
#define Cap_Sensor1  2
#define Cap_Sensor2  3  

void Sensor_Init(void);
uint8 Digital_Sensor_Read(uint8);

#endif /* SENSOR_H_ */