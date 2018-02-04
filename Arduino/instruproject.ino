
// include the library code:
#include "io.h"
//#include <LiquidCrystal.h>


void mainmenu();
void  get_info();
int select_food();
void selected_food();
void change_food();

// initialize the library with the numbers of the interface pins

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
    pinMode(13,OUTPUT);

  pinMode(s0,INPUT);
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  lcd.begin(16, 2);
  //Serial.print(447);
  //Serial.print(" Hello");
  //Serial.print(" ");
  mainmenu();
  // Print a message to the LCD.
//  lcd.print("hello, world!");
}



void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
        //    lcd.clear();
          //   int in=input();
           // lcd.print (in);
           // dela
          
          int in=input();
        
        if(in !=000 )
        {
          delay(30);
          in=input();
          if (in==ok)
          {
             Serial.print("HI ");

          get_info();
          Serial.print("OK ");
          for (int i=0;i<num_of_food;i++)
            {
                Serial.print(food[i].id);
                            Serial.print(" "); 
                            Serial.print(food[i].name);
                            Serial.print(" ");  
                            Serial.print(food[i].price);
                            Serial.print(" ");
              Serial.print(food[i].num);
                            Serial.print(" ");
                             Serial.print(food[i].p);
                            Serial.print(" ");
          }
          

            }

            if (in==back)
            {
              Serial.print("] 1 9 ] 2 0 ] 3 1 ");
            }
              delay(200);
        }

//Serial.print("2 3 5 ");
//delay(1000);



}

int select_food()
{
    wait_message();
    get_info();
      delay(DELAY_TIME_GET_INFO);

    lcd.clear();
    lcd.print("Food");

    lcd.setCursor(8,0);
    lcd.print("Price");

    lcd.setCursor(14,0);
    lcd.print("No");

    int selected_pk=0;
    lcd.setCursor(0,1);

   lcd.print(food[selected_pk].name);

   lcd.setCursor(8,1);
   lcd.print(food[selected_pk].price);

    lcd.setCursor(14,1);
   lcd.print(food[selected_pk].num);


    while(1)
    {
      int in=input();

      if (in !=0)
      {
        delay(DELAY_BOUNCE);
        in=input();
      if (in==up)
          {
             if (selected_pk==0)  selected_pk=num_of_food-1;
                             else selected_pk--;
                             select_food_print(selected_pk);

          }

      else if (in==down)
          {
                if (selected_pk==num_of_food-1) selected_pk=0;
                else selected_pk++;
                select_food_print(selected_pk);

          }

      else if (in==left)
        {
            if(food[selected_pk].num != 0)
            {
              food[selected_pk].num--;
              select_food_print(selected_pk);
            }


        }

      else if (in==right)
      {
            food[selected_pk].num++;
            select_food_print(selected_pk);

      }

      else if (in==del)
        {
            if (display_message("Set the no to 0?"))
              food[selected_pk].num=0;

            lcd.clear();
            lcd.print("Food");

            lcd.setCursor(8,0);
            lcd.print("Price");

            lcd.setCursor(14,0);
            lcd.print("No");

            select_food_print(selected_pk);
        }

      else if (in==ok)
        {
          if (display_message("Save the changes"))
            {
              send_info();
              delay(180);
              return 1;
            }

            lcd.clear();
            lcd.print("Food");

            lcd.setCursor(8,0);
            lcd.print("Price");

            lcd.setCursor(14,0);
            lcd.print("No");

            select_food_print(selected_pk);

        }


        else if (in==back)
          {
            if (display_message("Discard Changes?"))
              {
                delay(180);
                return 0;
              }

              lcd.clear();
              lcd.print("Food");

              lcd.setCursor(8,0);
              lcd.print("Price");

              lcd.setCursor(14,0);
              lcd.print("No");

              select_food_print(selected_pk);

          }




            delay(DELAY_LOOP);
      }
      }

}



void selected_food()
{
  wait_message();
  get_info();
    delay(DELAY_TIME_GET_INFO);

  lcd.clear();

  int *ar=new int[num_of_food];
  int count=0;
  for (int i=0;i<num_of_food;i++)
    {
      if (food[i].num>0)
      {
        ar[count]=i;
    //    lcd.print(ar[count]);
        count++;
      }
    }
  if (count==0)
      {
        lcd.print("No Foods Ordered");
        lcd.setCursor(6,1);
        lcd.print(">Ok");
        while(1)
          {
            int in=input();
            if (in == ok)
              {
               // delay(180);
                //mainmenu();
                return ;
               }
          }

      }
  lcd.print("Food");

  lcd.setCursor(8,0);
  lcd.print("Price");

  lcd.setCursor(14,0);
  lcd.print("No");

  lcd.setCursor(0,1);

  int pk=0;

 lcd.print(food[ar[pk]].name);

 lcd.setCursor(8,1);
 lcd.print(food[ar[pk]].price);

  lcd.setCursor(14,1);
 lcd.print(food[ar[pk]].num);


  while(1)
  {
    int in=input();

  if (in !=0)
  {
      delay(DELAY_BOUNCE);
      in=input();
    if (in==up)
        {
          if (pk==0)  pk=count-1;
                          else   pk--;
                           select_food_print(ar[pk]);

        }

    else if (in==down)
        {
             if (pk==count-1) pk=0;
               else pk++;
              select_food_print(ar[pk]);

        }


    else if (in==ok || in==back)
      {
            return;
      }

          delay(DELAY_LOOP);
  }
    }
}






void mainmenu()
{
  lcd.clear();
  num_of_food=0;
  int state=0;
  int first_visit=0;
  main_menu_print(first_visit);

  delay(DELAY_STRAIGHT);

  while(1)
      {
            int in=input();
            if (in!=000)
            {

              delay(DELAY_BOUNCE);
              in=input();
                if (state==0&& (in==up ||in==down))
             {
                lcd.setCursor(0,0);
                lcd.print(" ");
                lcd.setCursor(0,1);
                 lcd.print(">");
                 state=1;
              }
           else if (state==1 && (in==up ||in==down))
          {
                lcd.setCursor(0,1);
                lcd.print(" ");
                lcd.setCursor(0,0);
                 lcd.print(">");
                 state=0;
              }
          else if (in==ok)
            {
                delay(180);
                if (state==0)
                  {
                    int c=0;
                    if (first_visit==0)
                    c=select_food();
                    else
                    change_food();
                    if (c==1)
                    first_visit=1;
                     state=0;
                     main_menu_print(first_visit);
                  }
                 else
                 //selected_food();
                    {
                      selected_food();
                      main_menu_print(first_visit);
                      state=0;
                    }

                }
         delay(DELAY_LOOP);
            }
           
      }



}








void change_food()
{
  wait_message();
    get_info();
    delay(DELAY_TIME_GET_INFO);
    lcd.clear();
    lcd.print("Food");

    lcd.setCursor(8,0);
    lcd.print("Price");

    lcd.setCursor(14,0);
    lcd.print("No");

    int selected_pk=0;
    lcd.setCursor(0,1);

   lcd.print(food[selected_pk].name);

   lcd.setCursor(8,1);
   lcd.print(food[selected_pk].price);

    lcd.setCursor(14,1);
   lcd.print(food[selected_pk].num);


    while(1)
    {
      int in=input();

      if (in !=0)
      {
        delay(DELAY_BOUNCE);
        in=input();
        
      if (in==up)
          {
             if (selected_pk==0)  selected_pk=num_of_food-1;
                             else selected_pk--;
                             select_food_print(selected_pk);

          }

      else if (in==down)
          {
                if (selected_pk==num_of_food-1) selected_pk=0;
                else selected_pk++;
                select_food_print(selected_pk);

          }

      else if (in==left)
        {
          if (food[selected_pk].p==0)
          {
            if(food[selected_pk].num != 0)
            {
              food[selected_pk].num--;
              select_food_print(selected_pk);
            }

          }
            else
              {
                cannot_cancel();
                lcd.clear();
                lcd.print("Food");

                lcd.setCursor(8,0);
                lcd.print("Price");

                lcd.setCursor(14,0);
                lcd.print("No");

                select_food_print(selected_pk);
              }
          }







      else if (in==right)
      {
            food[selected_pk].num++;
            select_food_print(selected_pk);

      }

      else if (in==del)
        {
          if (food[selected_pk].p==0)
            {
              if (display_message("Set the no to 0?"))
                food[selected_pk].num=0;
            }
          else
            cannot_cancel();

            lcd.clear();
            lcd.print("Food");

            lcd.setCursor(8,0);
            lcd.print("Price");

            lcd.setCursor(14,0);
            lcd.print("No");

            select_food_print(selected_pk);
        }

      else if (in==ok)
        {
          if (display_message("Save the changes"))
            {
              send_info();
              delay(180);
              return;
            }

            lcd.clear();
            lcd.print("Food");

            lcd.setCursor(8,0);
            lcd.print("Price");

            lcd.setCursor(14,0);
            lcd.print("No");

            select_food_print(selected_pk);

        }


        else if (in==back)
          {
            if (display_message("Discard Changes?"))
              {
                delay(180);
                return ;
              }

              lcd.clear();
              lcd.print("Food");

              lcd.setCursor(8,0);
              lcd.print("Price");

              lcd.setCursor(14,0);
              lcd.print("No");

              select_food_print(selected_pk);

          }




            delay(DELAY_LOOP);
      }
      }

}

