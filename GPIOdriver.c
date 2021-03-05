#include "GPIOdriver.h"

__IO uint16_t Port_IO_flag = 0U;
__IO uint16_t GPIO_Init_flag = 0U;

void GPIO_Init()
{

	SYSCTL->RCGCGPIO = 0x2F;
	
//    GPIOA->LOCK = 0x4C4F434B;
    GPIOB->LOCK = 0x4C4F434B;
    GPIOC->LOCK = 0x4C4F434B;
    GPIOD->LOCK = 0x4C4F434B;
//    GPIOE->LOCK = 0x4C4F434B;
    GPIOF->LOCK = 0x4C4F434B;
    
//    GPIOA->CR = 0xff;
    GPIOB->CR = 0xff;
    GPIOC->CR = 0xff;
    GPIOD->CR = 0xff;
//    GPIOE->CR = 0xff;
    GPIOF->CR = 0xff;
    
    GPIO_Init_flag = 1;
    
}

void DigitalWrite(GPIO_PORT port_x , GPIO_HI_LO value)
{
	if(GPIO_Init_flag == 0)
	{
		GPIO_Init();
	}
	
		
	switch(port_x)
	{
		
		case PF2:
			if((Port_IO_flag & (1<<0)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<2);
				GPIOF->DIR   |=  (1<<2);
	    		GPIOF->DEN   |=  (1<<2);
	    		Port_IO_flag |= (1<<0);
	    	}	 
			
			if(value == HIGH)   	
    			GPIOF->DATA  |=  (1<<2);
    		
    		else
    			GPIOF->DATA  &=  ~(1<<2);
    			
    		break;
			
		case PF3:
			if((Port_IO_flag & (1<<1)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<3);
				GPIOF->DIR   |=  (1<<3);
	    		GPIOF->DEN   |=  (1<<3);
	    		Port_IO_flag |= (1<<1);
	    	}
			if(value == HIGH)			
    			GPIOF->DATA  |=  (1<<3);
    			
    		else
    			GPIOF->DATA  &=  ~(1<<3);
    		
    		break;
    		
		case PB3:
			if((Port_IO_flag & (1<<2)) == 0)
			{
				GPIOB->AFSEL &= ~(1<<3);
				GPIOB->DIR   |=  (1<<3);
	    		GPIOB->DEN   |=  (1<<3);
				Port_IO_flag |= (1<<2);
	    	}
	    	if(value == HIGH)
    			GPIOB->DATA  |=  (1<<3);
    			
    		else
    			GPIOB->DATA  &=  ~(1<<3);
    		
    		break;
    		
		case PC4:
			if((Port_IO_flag & (1<<3)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<4);
				GPIOC->DIR   |=  (1<<4);
	    		GPIOC->DEN   |=  (1<<4);
	    		Port_IO_flag |= (1<<3);
	    	}	
	    	
	    	if(value == HIGH)
    			GPIOC->DATA  |=  (1<<4);
    			
    		else
    			GPIOC->DATA  &=  ~(1<<4);
    			
    		break;
    		
		case PC5:
			if((Port_IO_flag & (1<<4)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<5);
				GPIOC->DIR   |=  (1<<5);
	    		GPIOC->DEN   |=  (1<<5);
	    		Port_IO_flag |= (1<<4);
	    	}	
	    	
	    	if(value == HIGH)
    			GPIOC->DATA  |=  (1<<5);
    			
    		else
    			GPIOC->DATA  &=  ~(1<<5);
    			
    		break;
    		
		case PC6:
			if((Port_IO_flag & (1<<5)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<6);
				GPIOC->DIR   |=  (1<<6);
	    		GPIOC->DEN   |=  (1<<6);
	    		Port_IO_flag |= (1<<5);
	    	}	
	    	if(value == HIGH)
    			GPIOC->DATA  |=  (1<<6);
    			
    		else
    			GPIOC->DATA  &=  ~(1<<6);
    			
    		break;
    		
		case PC7:
			if((Port_IO_flag & (1<<6)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<7);
				GPIOC->DIR   |=  (1<<7);
	    		GPIOC->DEN   |=  (1<<7);
	    		Port_IO_flag |= (1<<6);
	    	}
			
			if(value == HIGH)	
    			GPIOC->DATA  |=  (1<<7);
    			
    		else
    			GPIOC->DATA  &=  ~(1<<7);
    			
    		break;
    		
		case PD6:
			if((Port_IO_flag & (1<<7)) == 0)
			{
				GPIOD->AFSEL &= ~(1<<6);
				GPIOD->DIR   |=  (1<<6);
	    		GPIOD->DEN   |=  (1<<6);
	    		Port_IO_flag |= (1<<7);
	    	}
			
			if(value == HIGH)	
    			Port_IO_flag |= (1<<7);
    			
    		else
    			Port_IO_flag &= ~(1<<7);
    			
    		break;
    		
		case PD7:
			if((Port_IO_flag & (1<<8)) == 0)
			{
				GPIOD->AFSEL &= ~(1<<7);
				GPIOD->DIR   |=  (1<<7);
	    		GPIOD->DEN   |=  (1<<7);
	    		Port_IO_flag |= (1<<8);
	    	}	
	    	
	    	if(value == HIGH)
    			GPIOD->DATA  |=  (1<<7);
    			
    		else
    			GPIOD->DATA  &=  ~(1<<7);
    			
    		break;
    		
		case PF4:
			if((Port_IO_flag & (1<<9)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<4);
				GPIOF->DIR   |=  (1<<4);
	    		GPIOF->DEN   |=  (1<<4);
	    		Port_IO_flag |= (1<<9);
	    	}	
	    	
	    	if(value == HIGH)
    			GPIOF->DATA  |=  (1<<4);
    			
    		else
    			GPIOF->DATA  &=  ~(1<<4);
    			
    		break;
    			
	}
}

int DigitalRead(GPIO_PORT port_x , GPIO_PU_PD state)
{
	__IO uint8_t Input = 0;
	__IO uint8_t Input_0 = 0;
	__IO uint8_t Input_1 = 0;
	__IO uint8_t Input_2 = 0;
	__IO uint8_t Input_3 = 0;
	__IO uint8_t Input_4 = 0;
	__IO uint8_t Input_5 = 0;
	__IO uint8_t Input_6 = 0;
	__IO uint8_t Input_7 = 0;
	__IO uint8_t Input_8 = 0;
	__IO uint8_t Input_9 = 0;
	
	if(GPIO_Init_flag == 0)
		GPIO_Init();
	
	switch(port_x)
	{
		
		case PF2:
			if((Port_IO_flag & (1<<0)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<2);
				GPIOF->DIR   &= ~(1<<2);
	    		GPIOF->DEN   |=  (1<<2);
	    		Port_IO_flag |= (1<<0);
	    	}
			
			if( state == PU )
				GPIOF->PUR   |=  (1<<2);
			
			else
				GPIOF->PDR   |=  (1<<2); 
				 	
    		Input_0 = GPIOF->DATA;      
	        Input_0 &= (1<<2);
	        Input_0 = (Input_0>>2);
	        Input = Input_0;
    		break;
    		
			
		case PF3:
			if((Port_IO_flag & (1<<1)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<3);
				GPIOF->DIR   &= ~(1<<3);
	    		GPIOF->DEN   |=  (1<<3);
	    		Port_IO_flag |= (1<<1);
	    	}
			
			if( state == PU )
				GPIOF->PUR   |=  (1<<3);
			
			else
				GPIOF->PDR   |=  (1<<3); 
				 	
    		Input_1 = GPIOF->DATA;      
	        Input_1 &= (1<<3);
	        Input_1 = (Input_1>>3);
	        Input = Input_1;
    		break;
    		
		case PB3:
			if((Port_IO_flag & (1<<2)) == 0)
			{
				GPIOB->AFSEL &= ~(1<<3);
				GPIOB->DIR   &= ~(1<<3);
	    		GPIOB->DEN   |=  (1<<3);
				Port_IO_flag |= (1<<2);
	    	}
			
			if( state == PU )
				GPIOB->PUR   |=  (1<<3);
			
			else
				GPIOB->PDR   |=  (1<<3); 
				 	
    		Input_2 = GPIOB->DATA;      
	        Input_2 &= (1<<3);
	        Input_2 = (Input_2>>3);
	        Input = Input_2;
    		break;
    		
		case PC4:
			if((Port_IO_flag & (1<<3)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<4);
				GPIOC->DIR   &= ~(1<<4);
	    		GPIOC->DEN   |=  (1<<4);
	    		Port_IO_flag |= (1<<3);
	    	}
			
			if( state == PU )
				GPIOC->PUR   |=  (1<<4);
			
			else
				GPIOC->PDR   |=  (1<<4); 
				 	
    		Input_3 = GPIOC->DATA;      
	        Input_3 &= (1<<4);
	        Input_3 = (Input_3>>4);
	        Input = Input_3;
    		break;
    		
		case PC5:
			if((Port_IO_flag & (1<<4)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<5);
				GPIOC->DIR   &= ~(1<<5);
	    		GPIOC->DEN   |=  (1<<5);
	    		Port_IO_flag |= (1<<4);
	    	}
			
			if( state == PU )
				GPIOC->PUR   |=  (1<<5);
			
			else
				GPIOC->PDR   |=  (1<<5); 
				 	
    		Input_4 = GPIOC->DATA;      
	        Input_4 &= (1<<5);
	        Input_4 = (Input_4>>5);
	        Input = Input_4;
    		break;
    		
		case PC6:
			if((Port_IO_flag & (1<<5)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<6);
				GPIOC->DIR   &= ~(1<<6);
	    		GPIOC->DEN   |=  (1<<6);
	    		Port_IO_flag |= (1<<5);
	    	}
			
			if( state == PU )
				GPIOC->PUR   |=  (1<<6);
			
			else
				GPIOC->PDR   |=  (1<<6); 
				 	
    		Input_5 = GPIOC->DATA;      
	        Input_5 &= (1<<6);
	        Input_5 = (Input_5>>6);
	        Input = Input_5;
    		break;
    		
		case PC7:
			if((Port_IO_flag & (1<<6)) == 0)
			{
				GPIOC->AFSEL &= ~(1<<7);
				GPIOC->DIR   &= ~(1<<7);
	    		GPIOC->DEN   |=  (1<<7);
	    		Port_IO_flag |= (1<<6);
	    	}
			
			if( state == PU )
				GPIOC->PUR   |=  (1<<7);
			
			else
				GPIOC->PDR   |=  (1<<7); 
				 	
    		Input_6 = GPIOC->DATA;      
	        Input_6 &= (1<<7);
	        Input_6 = (Input_6>>7);
	        Input = Input_6;
    		break;
    		
		case PD6:
			if((Port_IO_flag & (1<<7)) == 0)
			{
				GPIOD->AFSEL &= ~(1<<6);
				GPIOD->DIR   &= ~(1<<6);
	    		GPIOD->DEN   |=  (1<<6);
	    		Port_IO_flag |= (1<<7);
	    	}
			
			if( state == PU )
				GPIOD->PUR   |=  (1<<6);
			
			else
				GPIOD->PDR   |=  (1<<6); 
				 	
    		Input_7 = GPIOD->DATA;      
	        Input_7 &= (1<<6);
	        Input_7 = (Input_7>>6);
	        Input = Input_7;
    		break;
    		
		case PD7:
			if((Port_IO_flag & (1<<8)) == 0)
			{
				GPIOD->AFSEL &= ~(1<<7);
				GPIOD->DIR   &= ~(1<<7);
	    		GPIOD->DEN   |=  (1<<7);
	    		Port_IO_flag |= (1<<8);
	    	}
			
			if( state == PU )
				GPIOD->PUR   |=  (1<<7);
			
			else
				GPIOD->PDR   |=  (1<<7); 
				 	
    		Input_8 = GPIOD->DATA;      
	        Input_8 &= (1<<7);
	        Input_8 = (Input_8>>7);
	        Input = Input_8;
    		break;
    		
		case PF4:
			if((Port_IO_flag & (1<<9)) == 0)
			{
				GPIOF->AFSEL &= ~(1<<4);
				GPIOF->DIR   &= ~(1<<4);
	    		GPIOF->DEN   |=  (1<<4);
	    		Port_IO_flag |= (1<<9);
	    	}
			
			if( state == PU )
				GPIOF->PUR   |=  (1<<4);
			
			else
				GPIOF->PDR   |=  (1<<4); 
				 	
    		Input_9 = GPIOF->DATA;      
	        Input_9 &= (1<<4);
	        Input_9 = (Input_9>>4);
	        Input = Input_9;
    		break;
    		
    	default:
    		break;
    			
	}
	return (Input);	
}

