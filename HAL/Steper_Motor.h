/*
 * Steper_Motor.h
 *
 * Created: 4/25/2021 2:28:20 AM
 *  Author: lenovo
 */ 


#ifndef STEPER_MOTOR_H_
#define STEPER_MOTOR_H_

#include "Steper_Motor_CFG.h"
#include "DIO.h"
#define F_CPU    CPU_Freq
#include <util/delay.h>

#define Move_FW    1
#define Move_RE    2

void Steper_Init(void);
void Steper_Pulse(void);
void Steper_Go(uint32 Linear,uint8 Dir);



#endif /* STEPER_MOTOR_H_ */