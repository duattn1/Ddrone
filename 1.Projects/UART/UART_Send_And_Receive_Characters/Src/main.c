/** @file main.c
 *  @brief Application main function
 *
 *  This is the main place to control the application.
 *
 *  @author 	Tran Nhat Duat (duattn)
 *	@version 	V0.1
 */ 
 
#include "stm32f407xx.h"
#include "../Inc/GPIO_driver.h"
#include "../Inc/UART_driver.h"

#define BUFFER_SIZE 256

int main(void){		
	uint8_t *buffer = 0;
	uint8_t ch;
	/* Configure PB10 as TX and PB11 as RX */
	GPIOInit(GPIOB, USART3PortB.txPin, ALTFUNCTION, PUSHPULL, VERYHIGHSPEED, NOPULL, AF7);
	GPIOInit(GPIOB, USART3PortB.rxPin, ALTFUNCTION, PUSHPULL, VERYHIGHSPEED, NOPULL, AF7);		
	
	UARTInit(USART3, IS_8_BITS_DATA, IS_1_STOP_BIT, DISABLE_PARITY, OVER_BY_16, 9600);		
	
	sendString(USART3, "con heo", 7);	
	
	while(1){
		//buffer = getString(USART3);
		ch = getChar(USART3);
		sendChar(USART3, ch);	
		//sendChar(USART3, 10); //LF: line feed - move cursor to next new line
		//sendChar(USART3, 13); //CR: carriage return - return cursor to the beginning of line
		
	}
	return 0;
}
