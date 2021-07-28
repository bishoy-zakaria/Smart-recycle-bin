/*
 * Steper_Motor.c
 *
 * Created: 4/25/2021 2:29:09 AM
 *  Author: Bishoy
 */ 

#include "Steper_Motor.h"
#include "Timer.h"
volatile float32 delay =0;
volatile uint32 Num_Pulse=0;
void Steper_Init(void)
{
	DIO_SetPinDir(Out_Port ,Limit_Switch_Pin , DIO_PIN_INPUT);
	uint8 limit_Val=0;
	Steper_Go(Max  , Move_FW);
	while(1)
	{
	   DIO_ReadPin (Out_Port ,Limit_Switch_Pin, &limit_Val);
	   if(limit_Val == 1)
	   {
		   timer1_stop();
		   break;
	   }
	}
	Steper_Go(Reference , Move_RE);
}

void Steper_Pulse(void)
{
	        float32 Max_Top=0;
	        Max_Top =((((16000000/1024)/(Frequency)) - 1) * 2) - 1 ;
			DIO_SetPinDir(Out_Port , Pulse_source , DIO_PIN_OUTPUT);
			timer1_init();
			PWM1_ICR_Value(10, Max_Top);                  
			timer1_start();
		
}
void Steper_Go(uint32 linear , uint8 MotorDir) // mm
{
	uint32 Num_Rev =0;
	uint32 Num_Pulse=0;
	float32 Tick_Time_ms =0;
	Num_Rev = linear / pitch_Lenth;
	Num_Pulse = Num_Rev * Micro_Step; 
	Tick_Time_ms = 100000/Frequency ;
	delay = (Tick_Time_ms/100)* Num_Pulse ;
	DIO_SetPinDir(Out_Port ,Direction_Pin , DIO_PIN_OUTPUT);
	if (MotorDir == Move_FW)
	DIO_WritePin(Out_Port , Direction_Pin, DIO_PIN_HIGH);
	else if (MotorDir == Move_RE)
	DIO_WritePin(Out_Port , Direction_Pin, DIO_PIN_LOW);
	
	Steper_Pulse();
	
	timer0_init();
	timer0_delay( delay );   //10000 ---- 4000 /// 20000 ---- 8000/// 30000----12000
	timer0_Set_CallBack(timer1_stop);
	timer0_start();
	
}