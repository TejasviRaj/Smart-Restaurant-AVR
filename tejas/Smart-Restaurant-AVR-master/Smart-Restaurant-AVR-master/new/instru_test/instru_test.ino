#include<SoftwareSerial.h>

SoftwareSerial esp(2,3);

class foods
{
      public:
      int id;
      String name;
      int price;
      int num;
      int prepared;
  foods()
  {
  }
  foods(int id, String name,int price, int num,int prepared) : id(id),name(name),price(price),num(num),prepared(prepared)
   {


   }
};
class foods food[20];
int num_of_foods;
int id,num;
void get_data();
void send_data();

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
    esp.begin(9600);
    Serial.println("arduino");
    food[0]=foods(1,"Momo",100,0,0);
    food[1]=foods(2,"Chow",200,0,0);
    food[2]=foods(3,"Dal",300,0,0);
    num_of_foods=3;
}   

void loop() {
     char b=Serial.read();
      if (b=='1')
      get_data();
      else if (b=='2')
      {
              char a=Serial.read();
              id=Serial.parseInt();
              a=Serial.read();
              num=Serial.parseInt();
              a=Serial.read();
              send_data();
              
      }
}

void get_data()
{
  Serial.print(num_of_foods);
  Serial.print(' ');
for (int i=0;i<num_of_foods;i++)
{

        Serial.print(food[i].id);
                    Serial.print(' ');

          // Serial.print(" food name: ");
           Serial.print(food[i].name);
                    Serial.print(' ');

          // Serial.print(" price: ");
           Serial.print(food[i].price);
                    Serial.print(' ');

         //  Serial.print("total selected ");
           Serial.print(food[i].num);
                    Serial.print(' ');

         //  Serial.print(" prepared: ");
           Serial.print(food[i].prepared);
                    Serial.print(' ');

  }

}

void send_data()
{
    food[id-1].num=num;
}


