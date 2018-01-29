extern "C"
#include "io.h"
#include "uart.h"
#define s0 0
#define s1 1
#define s2 2



int up=001,down=10,right=11,left=100,del=101,ok=110,back=111;
int num_of_food;
int dnum_of_food;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
foods food[15];

	char* uart0_gets()
	{
		char return_char[100];
		int index=0;
			do
			{
				while (!uart0_available()) {}
				return_char[index]=uart0_putc();
				index++;
			}
					while(return_char[index-1] != ' ');
			return_char[index]='\0';
			
			return return_char;
	}
	int uart0_getint()
	{
		char d=uart0_gets();
		
		int ans=0;
		for (i=0;i<strlen(d);i++)
		{
			ans=ans*10+d[i];
		}
		return ans;
	}
	
	bool digitalRead (int s)
	{
		bool a=bit_is_set(PORTB,s);
		return a;
	}

    void wait_message()
    {
        lcd_clear();
        lcd_puts("Please wait");
    }
   int input()
   {
       int a=0;
       if (digitalRead(s0))
         a+=1;
       if (digitalRead(s1))
         a+=10;
       if (digitalRead(s2))
         a+=100;
       return(a);
   }

   void main_menu_puts(int first_visit)
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

   void select_food_puts(int selected_pk)
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
          __delay_ms(180);
          lcd_clear();
         lcd_puts(" Cannot Cancel ");
         lcd_setCursor(6,1);
         lcd_puts(">Ok");
         while(1)
           {
             int in=input();
             if (in == ok)
               {
                 __delay_ms(180);
                 //mainmenu();
                 return ;
                }
           }
     }

     //confirmation messages
     int display_message(String s)
       {
           lcd_clear();
           lcd_puts(s);
           lcd_setCursor(2,1);
           lcd_puts(">Yes");

           lcd_setCursor(12,1);
           lcd_puts("No");
           __delay_ms(180);

           int state=1;
           while(1)
              {
                    int in=input();
                  //  lcd_puts (in);
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

                   __delay_ms(180);
               }

       }




void get_info()
{
	
  uart0_putc('1');
  while (!Serial.available()) {}
  num_of_food=uart0_getint()();
//  Serial.puts (num+1);

  //Serial.puts(a);
for (int i=0;i<num_of_food;i++)
{
    //  Serial.puts("Start");
    while (!Serial.available()) {}
      food[i].id=uart0_getint()();

      while (!Serial.available()) {}
      food[i].name=uart0_gets();

      while (!Serial.available()) {}
      food[i].price=uart0_getint()();

      while (!Serial.available()) {}
      food[i].num=uart0_getint()();

      while (!Serial.available()) {}
      food[i].p=uart0_getint()();

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
                Serial_puts("2 ");
				uart0_putint(food[i].id);
                Serial_putc(' ');
                uart0_putint(food[i].num);
                Serial.putc(' ');
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
