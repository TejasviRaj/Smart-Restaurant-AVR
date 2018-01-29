#include<SoftwareSerial.h>

SoftwareSerial esp(2,3);

class foods
{
      public:
      int id;
      String name;
      int price;
      int num;
      int p;
  foods()
  {
  }
  foods(int id, String name,int price, int num,int p) : id(id),name(name),price(price),num(num),p(p)
   {


   }
};
class foods food[20];
void get_data();


void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
    esp.begin(9600);
    Serial.println("arduino");
    get_data();
}

void loop() {
    //   while (!Serial.available()) {}
    // String id1=Serial.readStringUntil(' ');
    // while (!Serial.available()) {}
    // String food1=Serial.readStringUntil(' ');
    // while (!Serial.available()) {}
    // String price1=Serial.readStringUntil(' ');
    // while (!Serial.available()) {}
    // String num_selected=Serial.readStringUntil(' ');
    // while (!Serial.available()) {}
    // String prepared1=Serial.readStringUntil(' ');
    //   Serial.print("id no ");
    //        Serial.print(id1);
    //        Serial.print(" food name: ");
    //        Serial.print(food1);
    //        Serial.print(" price: ");
    //        Serial.print(price1);
    //        Serial.print("total selected ");
    //        Serial.print(num_selected);
    //        Serial.print(" prepared: ");
    //        Serial.print(prepared1);
}

void get_data()
{
  while (!Serial.available()) {}
  int num=Serial.parseInt();
  Serial.print (num+1);

  char a =Serial.read();
  Serial.print(a);
for (int i=0;i<num;i++)
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


        Serial.print("id no ");
             Serial.println(food[i].id);
             Serial.print(" food name: ");
             Serial.println(food[i].name);
             Serial.print(" price: ");
             Serial.println(food[i].price);
             Serial.print("total selected ");
             Serial.println(food[i].num);
             Serial.print(" prepared: ");
             Serial.println(food[i].p);
             Serial.println();

  }

  Serial.println("Done");


}
