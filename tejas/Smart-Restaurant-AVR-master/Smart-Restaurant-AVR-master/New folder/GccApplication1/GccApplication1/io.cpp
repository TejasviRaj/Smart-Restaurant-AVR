#ifndef IO_H
#define F_CPU 16000000UL
#endif

extern "C"
#include "io.h"
#include "uart.h"
#include "lcd.h"
#include<util/delay.h>





int up=001,down=10,right=11,left=100,del=101,ok=110,back=111;
int num_of_food;
int dnum_of_food;
foods dfood[15];

void lcd_setCursor(int x,int y)
{
	
	lcd_gotoxy(x,(1-y)+1);
}


foods food[15];

	void uart0_gets(char s[])
	{
		char return_char[100];
		int index=0;
			do
			{
				while (!uart0_available()) {}
				return_char[index]=uart0_getc();
				index++;
			}
					while(return_char[index-1] != ' ');
			return_char[index-1]='\0';
			strcpy(s,return_char);		
	}
	int uart0_getint()
	{
		char d[5];
		uart0_gets(d);
		
		int ans=0;
		for (unsigned int i=0;i<strlen(d);i++)
		{
			ans=ans*10+(d[i]-'0');
		}
		return ans;
	}
	
	int digitalRead (int s)
	{
		return (PIND & (1<<s));
	}

    void wait_message()
    {
        lcd_clear();
        lcd_puts("Please wait");
    }
   int input()
   {
       int a=0;
       if (digitalRead(s_zero))
         a+=1;
       if (digitalRead(s_one))
         a+=10;
       if (digitalRead(s_two))
         a+=100;
       return(a);
   }

   void main_menu_print(int first_visit)
   {
     lcd_clear();
     lcd_setCursor(0,0);
     lcd_puts(" ");
     lcd_setCursor(0,0);
      lcd_puts(">");

      lcd_setCursor(2, 1);
      lcd_puts("Selected Food");

      lcd_setCursor(2, 0);
      if (first_visit==1)
      lcd_puts("Change Food");
      else
      lcd_puts("Select Food");
   }

   void select_food_print(int selected_pk)
     {
               clear_second_line();

                lcd_setCursor(0,1);

                lcd_puts(food[selected_pk].name);

                lcd_setCursor(8,1);
                lcd_num(food[selected_pk].price);

                 lcd_setCursor(14,1);
                lcd_num(food[selected_pk].num);

     }

     void clear_second_line()
     {
       for (int i=0;i<=15;i++)
       {
         lcd_setCursor(i,1);
         lcd_puts(" ");
       }
     }

     void cannot_cancel()
     {
		  _delay_ms(DELAY_TIME_STRAIGHT_START);
          lcd_clear();
         lcd_puts(" Cannot Cancel ");
         lcd_setCursor(6,1);
         lcd_puts(">Ok");
         while(1)
           {
             int in=input();
			 if (in !=0)
			 {
				 _delay_ms(DELAY_BOUNCE);
             if (in == ok)
               {
				//	_delay_ms(DELAY_TIME);
                 //mainmenu();
                 return ;
                }
						   _delay_ms(DELAY_TIME_LOOP);

           }
		 }
     }

     //confirmation messages
     int display_message1(char const *s)
       {
           lcd_clear();
           lcd_puts(s);
           lcd_setCursor(2,1);
           lcd_puts(">Yes");

           lcd_setCursor(12,1);
           lcd_puts("No");
           _delay_ms(DELAY_TIME_STRAIGHT_START);

           int state=1;
           while(1)
              {
                    int in=input();
                  //  lcd_puts (in);
				  if (in !=0)
				  {
					  _delay_ms(DELAY_BOUNCE);
					  in =input();
                   if (state==1&& (in==left ||in==right))
                     {
                        lcd_setCursor(2,1);
                        lcd_puts(" ");
                        lcd_setCursor(11,1);
                         lcd_puts(">");
                         state=0;
                      }
                   else if (state==0 && (in==left ||in==right))
                  {
                        lcd_setCursor(11,1);
                        lcd_puts(" ");
                        lcd_setCursor(2,1);
                         lcd_puts(">");
                         state=1;
                      }
                  else if (in==ok)
                   return state;

                   _delay_ms(DELAY_TIME_LOOP);
				  }
               }
				
       }




void get_info()
{
	//_delay_ms(DELAY_FLUSH);
   char a ;
   char c[30];
	int i;
	while(uart0_available()) a=uart0_getc();
	//uart0_flush();
  uart0_puts("[ ");
  do 
  {
	  a=uart0_getc();
  }
  while (a!='=');
  num_of_food=uart0_getint();
//  Serial.puts (num+1);

  //Serial.puts(a);
for (int i=0;i<num_of_food;i++)
{
    //  Serial.puts("Start");
      food[i].id=uart0_getint();
      uart0_gets(food[i].name);
      food[i].price=uart0_getint();
      food[i].num=uart0_getint();
      food[i].p=uart0_getint();

        // Serial.puts("id no ");
        //      Serial.putsln(food[i].id);
        //      Serial.puts(" food name: ");
        //      Serial.putsln(food[i].name);
        //      Serial.puts(" price: ");
        //      Serial.putsln(food[i].price);
        //      Serial.puts("total selected ");
        //      Serial.putsln(food[i].num);
        //      Serial.puts(" prepared: ");
        //      Serial.putsln(food[i].p);
        //      Serial.putsln();

  }

  // Serial.putsln("Done");


}

      void send_info()
        {
          for (int i=0;i<num_of_food;i++)
              {
                uart0_puts("] ");
				uart0_putint(food[i].id);
                uart0_putc(' ');
                uart0_putint(food[i].num);
                uart0_putc(' ');
              }



        }



    //food class declaration
   // foods::foods()
   // {
   // }
   // foods::foods(int id, String name,int price, int num,int p) : id(id),name(name),price(price),num(num),p(p)
   //  {
   //
   //
   //  }
