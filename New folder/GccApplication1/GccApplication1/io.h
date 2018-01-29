#ifndef IO_H
#define IO_H

#ifndef IO_H
#define F_CPU 16000000UL
#endif
#define s_zero PINB0
#define s_one PINB1
#define s_two PINB2
#define DELAY_TIME 50

#include<avr/io.h>
#include<util/delay.h>
#include<string.h>
#include<avr/interrupt.h>

class foods;
extern int num_of_food;
extern int dnum_of_food;

extern int up,down,right,left,del,ok,back;
extern foods food[15];
extern foods dfood[15];

void database_init();
 void uart0_gets(char s[]);
		int uart0_getint();
			int digitalRead (int s);
int input();
int display_message1(char const *s);
void cannot_cancel();
void select_food_print(int selected_pk);
void main_menu_print(int first_visit);
void clear_second_line();
void get_info();
void send_info();
void wait_message();
void lcd_setCursor(int y,int x);



struct foods
{
  int id;
  char name[20];
  int price;
  int num;
  int p;
  



  };





#endif
