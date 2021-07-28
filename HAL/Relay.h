/*
 * Relay.h
 *
 * Created: 4/25/2021 6:32:54 PM
 *  Author: lenovo
 */ 


#ifndef RELAY_H_
#define RELAY_H_

#include "DIO.h"
#include "Relay_CFG.h"

#define Relay1      1
#define Relay2      2
#define Relay3      3
#define Relay4      4

#define Relay_High   1
#define Relay_Low    0

void Relay_Switch (uint8 Relay , uint8 Val );

void Relay_Stop(void);

#endif /* RELAY_H_ */