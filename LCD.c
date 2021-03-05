#include "LCD.h"

static uint8_t RS;
static uint8_t RW;
static uint8_t EN;
static uint8_t D4;
static uint8_t D5;
static uint8_t D6;
static uint8_t D7;

uint8_t D0_data;
uint8_t D1_data;
uint8_t D2_data;
uint8_t D3_data;
uint8_t D4_data;
uint8_t D5_data;
uint8_t D6_data;
uint8_t D7_data;


/***************************************To be called from void main()**********************************/
/********************This funtion is used to setup pins for LCD and MicroController********************/

void LCD_Setup(GPIO_PORT RS_pin , GPIO_PORT RW_pin , GPIO_PORT EN_pin , GPIO_PORT D4_pin ,    //
			   GPIO_PORT D5_pin , GPIO_PORT D6_pin , GPIO_PORT D7_pin  )
{
	RS = RS_pin;
	RW = RW_pin;
	EN = EN_pin;
	D4 = D4_pin;
	D5 = D5_pin;
	D6 = D6_pin;
	D7 = D7_pin;
	
	delay(10);
	LCD_Init();
}


/***************************************To be called from void main()**********************************/
/********************************This funtion is used to initialize LCD Modes**************************/

void LCD_Init()
{
	delay(5);									/* LCD power ON Initialization time delay  */
	Cmd_Write(0x02);							/* 4bit mode                               */
	Cmd_Write(0x28);							/* Initialization of 16X2 LCD in 4bit mode */
	Cmd_Write(0x0c);							/* Display ON cursorn OFF				   */
	Cmd_Write(0x06);					 		/* Auto Increament cursor  				   */
	Cmd_Write(0x01);			 				/* Clear  display 						   */
	Cmd_Write(0x80);							/* Cursor at home possition   			   */
}


/***************************************To be called from void main()**********************************/
/**************************This funtion is used to Set the Cursor at desired possition*****************/

void LCD_SetCursor(uint8_t row , uint8_t pos)
{
	if(row == 0)
	{
		Cmd_Write((pos & 0x0f) | 0x80);
	}
	
	else if(row == 1)
	{
		Cmd_Write((pos & 0x0f) | 0xc0);
	}
	
	else
	{
		;
	}
}


/***************************************To be called from void main()**********************************/
/*********************************This funtion is used to Clear LCD Screen*****************************/

void LCD_Clear()
{
	Cmd_Write(0x01);
}


/***************************************To be called from void main()**********************************/
/****************************This funtion is used to take string input from main()*********************/

void LCD_Write(char* lcd_data)
{
	uint8_t str_len = 0;
	
	for(str_len = 0 ; lcd_data[str_len] != '\0' ; str_len++)
	{
		Data_Write(lcd_data[str_len]);
	}
}


/****************************This funtion is used to write data to LCD********************************/

static void Data_Write(uint8_t data)
{
	upper_nibble(data);
	
	DigitalWrite(RS , HIGH);				/* Data Write mode    */
	DigitalWrite(RW , LOW);					/* Write operation	  */
	
	enable_toggle_signal();
	
	lower_nibble(data);
	
	enable_toggle_signal();
	
	delay(2);
}


/****************************This funtion is used to write data to LCD********************************/

static void Cmd_Write(uint8_t cmd)
{
	upper_nibble(cmd);
	
	DigitalWrite(RS , LOW);				/* Command Write mode    */
	DigitalWrite(RW , LOW);				/* Write operation       */
	
	enable_toggle_signal();
	
	lower_nibble(cmd);
	
	enable_toggle_signal();
	
	delay(2);
}

/********************This funtion is used to send upper 4 BIT data/command to LCD*********************/

static void upper_nibble(uint8_t UpperNibble_data)
{
	D4_data = ((UpperNibble_data & 0x10) >> 4);        /* Extracring 4th Bit data from character byte */
	D5_data = ((UpperNibble_data & 0x20) >> 5);        /* Extracring 5th Bit data from character byte */
	D6_data = ((UpperNibble_data & 0x40) >> 6);        /* Extracring 6th Bit data from character byte */
	D7_data = ((UpperNibble_data & 0x80) >> 7);        /* Extracring 7th Bit data from character byte */
	
	DigitalWrite(D4 , D4_data);
	DigitalWrite(D5 , D5_data);
	DigitalWrite(D6 , D6_data);
	DigitalWrite(D7 , D7_data);
}


/********************This funtion is used to send lower 4 BIT data/command to LCD*********************/

void lower_nibble(uint8_t LowerNibble_data)
{
	D0_data = ((LowerNibble_data & 0x01) >> 0);        /* Extracring 0th Bit data from character byte */
	D1_data = ((LowerNibble_data & 0x02) >> 1);        /* Extracring 1st Bit data from character byte */
	D2_data = ((LowerNibble_data & 0x04) >> 2);        /* Extracring 2nd Bit data from character byte */
	D3_data = ((LowerNibble_data & 0x08) >> 3);        /* Extracring 3rd Bit data from character byte */
	
	DigitalWrite(D4 , D0_data);
	DigitalWrite(D5 , D1_data);
	DigitalWrite(D6 , D2_data);
	DigitalWrite(D7 , D3_data);
}


/********************This funtion is used to provide pulse signal to Enable pin **********************/

static void enable_toggle_signal()
{
	DigitalWrite(EN , HIGH);
	delay(5);
	DigitalWrite(EN , LOW);
	delay(3);
}


/********************This funtion is used to provide pulse signal to Enable pin **********************/

static void delay(uint8_t count)
{
	uint8_t i = 0;
	uint8_t j = 0;
	for(i=0 ; i<count ; i++)
	{
		for(j=0 ; j<100 ; j++);
	}
}

