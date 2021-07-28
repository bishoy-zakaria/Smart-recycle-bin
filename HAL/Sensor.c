/*
 * Sensor.c
 *
 * Created: 4/25/2021 6:58:21 PM
 *  Author: lenovo
 */ 
#include "Sensor.h"

void Sensor_Init(void)
{
	DIO_SetPinDir(Sensor_Port , Ind_Sensor_Pin  , DIO_PIN_INPUT);
	DIO_SetPinDir(Sensor_Port , Cap_Sensor1_Pin , DIO_PIN_INPUT);
	DIO_SetPinDir(Sensor_Port , Cap_Sensor2_Pin , DIO_PIN_INPUT);
}

uint8 Digital_Sensor_Read(uint8 sensor)
{
	uint8 val=0;
	if (sensor == Ind_Sensor)
	DIO_ReadPin (Sensor_Port ,Ind_Sensor_Pin, &val);
	else if (sensor == Cap_Sensor1)
	DIO_ReadPin (Sensor_Port ,Cap_Sensor1_Pin, &val);
	else if (sensor == Cap_Sensor2)
	DIO_ReadPin (Sensor_Port ,Cap_Sensor2_Pin, &val);
	return val;
}