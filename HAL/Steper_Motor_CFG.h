/*
 * Steper_Motor_CFG.h
 *
 * Created: 4/25/2021 2:28:46 AM
 *  Author: lenovo
 */ 


#ifndef STEPER_MOTOR_CFG_H_
#define STEPER_MOTOR_CFG_H_


#define Micro_Step         400  //Pulse per revolution 
#define pitch_Lenth        2    // mm 

#define Frequency          1500 //HZ
#define CPU_Freq        16000000 //HZ

#define Out_Port            DIO_PORTD
#define Direction_Pin       DIO_PIN1
#define Pulse_source        DIO_PIN5

#define Limit_Switch_Pin    DIO_PIN2
#define Reference              300 //mm
#define Max                  600 //mm

#endif /* STEPER_MOTOR_CFG_H_ */