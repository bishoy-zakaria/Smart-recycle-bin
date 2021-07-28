/*
 * Relay.c
 *
 * Created: 4/25/2021 6:33:14 PM
 *  Author: lenovo
 */ 

#include "Relay.h"

void Relay_Switch (uint8 Relay , uint8 Val )
{
	if(Relay == Relay1)
	{   DIO_SetPinDir(Relay_Port , Relay1_Pin , DIO_PIN_OUTPUT);
		if (Val == Relay_High)
		DIO_WritePin(Relay_Port , Relay1_Pin , DIO_PIN_HIGH);
		else
		DIO_WritePin(Relay_Port , Relay1_Pin , DIO_PIN_LOW);
	}
	else if(Relay == Relay2)
	{   DIO_SetPinDir(Relay_Port , Relay2_Pin , DIO_PIN_OUTPUT);
		if (Val == Relay_High)
		DIO_WritePin(Relay_Port , Relay2_Pin , DIO_PIN_HIGH);
		else
		DIO_WritePin(Relay_Port , Relay2_Pin , DIO_PIN_LOW);
	}
	else if(Relay == Relay3)
	{   DIO_SetPinDir(Relay_Port , Relay3_Pin , DIO_PIN_OUTPUT);
		if (Val == Relay_High)
		DIO_WritePin(Relay_Port , Relay3_Pin , DIO_PIN_HIGH);
		else
		DIO_WritePin(Relay_Port , Relay3_Pin , DIO_PIN_LOW);
	}
	else if(Relay == Relay4)
	{   DIO_SetPinDir(Relay_Port , Relay4_Pin , DIO_PIN_OUTPUT);
		if (Val == Relay_High)
		DIO_WritePin(Relay_Port , Relay4_Pin , DIO_PIN_HIGH);
		else
		DIO_WritePin(Relay_Port , Relay4_Pin , DIO_PIN_LOW);
	}
}

void Relay_Stop(void)
{
	DIO_WritePin(Relay_Port , Relay1_Pin , DIO_PIN_LOW);
	DIO_WritePin(Relay_Port , Relay2_Pin , DIO_PIN_LOW);
	DIO_WritePin(Relay_Port , Relay3_Pin , DIO_PIN_LOW);
	DIO_WritePin(Relay_Port , Relay4_Pin , DIO_PIN_LOW);
}