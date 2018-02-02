#ifndef IO_H
#define IO_H

#include "Arduino.h"
#include "LiquidCrystal.h"
#define DELAY_BOUNCE 30
#define DELAY_LOOP 200
#define DELAY_TIME_GET_INFO 200
#define DELAY_STRAIGHT 200

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
int input();
int display_message(String s);
void cannot_cancel();
void select_food_print(int selected_pk);
void main_menu_print(int first_visit);
void clear_second_line();
void get_info();
void send_info();
void wait_message();
void uart0_gets(char s[]);
  int uart0_getint();



struct foods
{
  int id;
  String name;
  int price;
  int num;
  int p;



  };





#endif
