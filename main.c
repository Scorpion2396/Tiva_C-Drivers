#include<stdio.h>
#include "TM4C123GH6PM.h"
#include "GPIOdriver.h"
#include "LCD.h"

void main()
{
	char volt[] = "voltage";
	char volt_val[10];
	float val = 2.56 ;
	
	sprintf(volt_val,"%0.2f",val);
	
	LCD_Setup(PF4 , PD7 , PD6 , PC7 , PC6 , PC5 , PC4);
	
	while(1)
	{
		LCD_Init();
		LCD_Write(volt);
		LCD_SetCursor(1,0);
		LCD_Write(volt_val);
	}
}
