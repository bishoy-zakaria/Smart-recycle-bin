/*
 * Mechatronics_Project.c
 *
 * Created: 5/25/2021 7:06:36 PM
 * Author : Bishoy Zakaria Yakoob
 * Project: Smart recycle pin
 */ 

#include "LCD.h"
#include "Relay.h"
#include "Sensor.h"
#include "Steper_Motor.h"

/* ***************** Function of the application ****************** */
void system_init(void);
void Metal_Material(void);
void Plastic_Material(void);
void Paper_Material(void);
/* ***************** Global variables ********************** */ 
extern volatile uint32 count0;
extern volatile uint32 Timer0_Compare_Match ;
/* **************** System information *************** */
#define Plastic_Material_Distance 170 // mm
#define Paper_Material_Distance   170 // mm
/* **************** application ********************** */
int main(void)
{   // this step is very necessary for the optimizer
	count0 =count0;
	Timer0_Compare_Match= Timer0_Compare_Match;
	/* *************** Local Variables ******************* */ 
	uint8 metal   = 0;
	uint8 plastic = 0;
	uint8 paper   = 0;
	/***************** System initialization ************** */
	system_init();
	
	while(1)
	{
		_delay_ms(500);
		metal   = Digital_Sensor_Read(Ind_Sensor);
		plastic = Digital_Sensor_Read(Cap_Sensor1);
		paper   = Digital_Sensor_Read(Cap_Sensor2);
		
		if(metal)
		 Metal_Material();
		else if(plastic)
		 Plastic_Material();
		else if(paper)
		 Paper_Material();
		else
		{
		 Relay_Switch (Relay1 , Relay_High); // open the outer door
		}
	}
}

void system_init(void)
{
	/* ************ close all doors *********************** */
	Relay_Stop();
	/************** LCD initialization ******************** */
	LCD_Init();
	LCD_GoTo(0,2);
	LCD_WriteString("SMART RECYCLE");
	LCD_GoTo(1,7);
	LCD_WriteString("BIN");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("ALI RAGAAB");
	LCD_GoTo(1,0);
	LCD_WriteString("TEAM LEADER");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("BISHOY ZAKARIA");
	LCD_GoTo(1,0);
	LCD_WriteString("EMBEDDED LEADER");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("SAMIR SULTAN");
	LCD_GoTo(1,0);
	LCD_WriteString("PCB DESIGNER");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("MENA NABIL");
	LCD_GoTo(1,0);
	LCD_WriteString("PNUMATIC LEADER");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("AMAL NADY");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("MAHMOUD RAGAAB");
	_delay_ms(1000);
	LCD_Clear();
	
	LCD_WriteString("ABDELKHALEK");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Initializing...");
	/************** Steper initialization *******************/
	Steper_Init();
	/************** Sensor initialization ******************/
	Sensor_Init();
	/* ************ open all doors *********************** */
	Relay_Switch (Relay1 , Relay_High); // open the outer door
	LCD_Clear();
	LCD_WriteString("READY");
}
void Metal_Material(void)
{
	LCD_Clear();
	LCD_WriteString("METAL");
	_delay_ms(500);
	Relay_Switch (Relay1 , Relay_High); // Close the outer door
	_delay_ms(1000);
	Relay_Switch (Relay2 , Relay_Low); // open the inner door
	_delay_ms(3000);
	Relay_Switch (Relay2 , Relay_High); // Close the inner door
	LCD_Clear();
	Relay_Switch (Relay1 , Relay_Low); // Open the outer door
	LCD_WriteString("READY");
}
void Plastic_Material(void)
{
	LCD_Clear();
	LCD_WriteString("PLASTIC");
	_delay_ms(500);
	Relay_Switch (Relay1 , Relay_Low); // Close the outer door
	Relay_Switch (Relay2 , Relay_Low); // Close the inner door
	_delay_ms(1000);
	Steper_Go(Plastic_Material_Distance , Move_FW);
	_delay_ms(1000);
	Relay_Switch (Relay2 , Relay_High); // open the inner door
	_delay_ms(3000);
	Relay_Switch (Relay2 , Relay_Low); // Close the inner door
	Steper_Go(Plastic_Material_Distance , Move_RE);
	LCD_Clear();
	_delay_ms(1000);
	Relay_Switch (Relay1 , Relay_High); // Open the outer door
	LCD_WriteString("READY");
}
void Paper_Material(void)
{
	LCD_Clear();
	LCD_WriteString("PAPER");
	_delay_ms(500);
	Relay_Switch (Relay1 , Relay_Low); // Close the outer door
	Relay_Switch (Relay2 , Relay_Low); // Close the inner door
	_delay_ms(1000);
	Steper_Go(Paper_Material_Distance , Move_RE);
	_delay_ms(1000);
	Relay_Switch (Relay2 , Relay_High); // open the inner door
	_delay_ms(3000);
	Relay_Switch (Relay2 , Relay_Low); // Close the inner door
	Steper_Go(Paper_Material_Distance , Move_FW);
	LCD_Clear();
	_delay_ms(1000);
	Relay_Switch (Relay1 , Relay_High); // Open the outer door
	LCD_WriteString("READY");
}