/*
 * UART_Driver_05.c
 *
 * Created: 27/11/2020 06:21:11 م
 * Author : Ali
 */ 

#define  F_CPU  16000000UL
#include <util/delay.h>
#include "SPI.h"
#include "UART.h"
#include "LCD.h"


int main(void)
{
   UART_Init();
   SPI_Master_Init();
   LCD_Init();
   
  while (1)
  {
	  LCD_WriteString( "My Smart Home");
	  if (UART_Rx()=='1')
	  {
		  SPI_Write('1');
		  LCD_GoTo(2,0);
		  LCD_WriteString( "LED is ON");
		  _delay_ms(500);
		  LCD_Clear();
	  }
	  if (UART_Rx()=='2')
	  {
		  SPI_Write('2');
		  LCD_GoTo(2,0);
		  LCD_WriteString("LED is OFF");
		  _delay_ms(500);
          LCD_Clear();	
      }
	  if (UART_Rx()=='3')
	  {
		  SPI_Write('3');
		  LCD_GoTo(2,0);
		  LCD_WriteString("Reading Temp.");
		  _delay_ms(500);
		  LCD_Clear();
	  }
	  if (UART_Rx()=='+')
	  {
		  SPI_Write('+');
		  LCD_GoTo(2,0);
		  LCD_WriteString("Motor is accel.");
		  _delay_ms(500);
		  LCD_Clear();
	  }
	  if (UART_Rx()=='-')
	  {
		  SPI_Write('-');
		  LCD_GoTo(2,0);
		  LCD_WriteString("Motor is decel.");
		  _delay_ms(500);
		  LCD_Clear();

	  }
  }
}

