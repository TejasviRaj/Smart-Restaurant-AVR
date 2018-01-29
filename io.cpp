extern "C"
#include "io.h"

int s0=8;
int s1=9;
int s2=10;
int up=001,down=10,right=11,left=100,del=101,ok=110,back=111;
int num_of_food;
int dnum_of_food;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
foods food[15];

    void wait_message()
    {
        lcd.clear();
        lcd.print("Please wait");
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

   void main_menu_print(int first_visit)
   {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(" ");
     lcd.setCursor(0,0);
      lcd.print(">");

      lcd.setCursor(2, 1);
      lcd.print("Selected Food");

      lcd.setCursor(2, 0);
      if (first_visit==1)
      lcd.print("Change Food");
      else
      lcd.print("Select Food");
   }

   void select_food_print(int selected_pk)
     {
               clear_second_line();

                lcd.setCursor(0,1);

                lcd.print(food[selected_pk].name);

                lcd.setCursor(8,1);
                lcd.print(food[selected_pk].price);

                 lcd.setCursor(14,1);
                lcd.print(food[selected_pk].num);

     }

     void clear_second_line()
     {
       for (int i=0;i<=15;i++)
       {
         lcd.setCursor(i,1);
         lcd.print(" ");
       }
     }

     void cannot_cancel()
     {
          delay(180);
          lcd.clear();
         lcd.print(" Cannot Cancel ");
         lcd.setCursor(6,1);
         lcd.print(">Ok");
         while(1)
           {
             int in=input();
             if (in == ok)
               {
                 delay(180);
                 //mainmenu();
                 return ;
                }
           }
     }

     //confirmation messages
     int display_message(String s)
       {
           lcd.clear();
           lcd.print(s);
           lcd.setCursor(2,1);
           lcd.print(">Yes");

           lcd.setCursor(12,1);
           lcd.print("No");
           delay(180);

           int state=1;
           while(1)
              {
                    int in=input();
                  //  lcd.print (in);
                   if (state==1&& (in==left ||in==right))
                     {
                        lcd.setCursor(2,1);
                        lcd.print(" ");
                        lcd.setCursor(11,1);
                         lcd.print(">");
                         state=0;
                      }
                   else if (state==0 && (in==left ||in==right))
                  {
                        lcd.setCursor(11,1);
                        lcd.print(" ");
                        lcd.setCursor(2,1);
                         lcd.print(">");
                         state=1;
                      }
                  else if (in==ok)
                   return state;

                   delay(180);
               }

       }




void get_info()
{
  Serial.write('1');
  while (!Serial.available()) {}
  num_of_food=Serial.parseInt();
//  Serial.print (num+1);

  char a =Serial.read();
  //Serial.print(a);
for (int i=0;i<num_of_food;i++)
{
    //  Serial.print("Start");
    while (!Serial.available()) {}
      food[i].id=Serial.parseInt();
      a =Serial.read();

      while (!Serial.available()) {}
      food[i].name=Serial.readStringUntil(' ');

      while (!Serial.available()) {}
      food[i].price=Serial.parseInt();
      a =Serial.read();

      while (!Serial.available()) {}
      food[i].num=Serial.parseInt();
      a =Serial.read();

      while (!Serial.available()) {}
      food[i].p=Serial.parseInt();
      a =Serial.read();


        // Serial.print("id no ");
        //      Serial.println(food[i].id);
        //      Serial.print(" food name: ");
        //      Serial.println(food[i].name);
        //      Serial.print(" price: ");
        //      Serial.println(food[i].price);
        //      Serial.print("total selected ");
        //      Serial.println(food[i].num);
        //      Serial.print(" prepared: ");
        //      Serial.println(food[i].p);
        //      Serial.println();

  }

  // Serial.println("Done");


}

      void send_info()
        {
          for (int i=0;i<num_of_food;i++)
              {
                Serial.print("2 ");
                Serial.print(food[i].id);
                Serial.print(' ');
                Serial.print(food[i].num);
                Serial.print(' ');
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
