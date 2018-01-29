#ifndef IO_H
#define IO_H

#include<avr/io.h>
#include<util/delay.h>
#include "Arduino.h"
#include "LiquidCrystal.h"

extern LiquidCrystal lcd;
class foods;
extern int num_of_food;
extern int dnum_of_food;
extern int s0;
extern int s1;
extern int s2;
extern int up,down,right,left,del,ok,back;
extern foods food[15];
extern foods dfood[15];

void database_init();
	char* uart0_gets();
		int uart0_getint();
			bool digitalRead (int s);
int input();
int display_message(String s);
void cannot_cancel();
void select_food_print(int selected_pk);
void main_menu_print(int first_visit);
void clear_second_line();
void get_info();
void send_info();
void wait_message();



struct foods
{
  int id;
  String name;
  int price;
  int num;
  int p;



  };





#endif
