#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "lcd.h"
#include "uart.h"
#include "myio.h"


int main()
{
  //uart0_init(UART_BAUD_SELECT(9600,F_CPU));
  lcd_init();

//  while(1)
  lcd_num(7);
  _delay_ms(200);

//  lcd_num(5);
//  _delay_ms(200);
lcd_gotoxy(0,5);
Printf("Hello");
_delay_ms(200);
lcd_clear();


}
