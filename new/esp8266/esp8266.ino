#include <ESP8266WiFi.h>
void get_data();
void send_data();


const char* ssid     = "harke";
const char* password = "bodhinamaskar";
const char* host = "192.168.43.167";
int id;
int num;
void setup() {
  Serial.begin(115200);
  delay(100);
  // We start by connecting to a WiFi network
 // Serial.println();
 // Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 // Serial.println("");
  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//  Serial.print("Netmask: ");
//  Serial.println(WiFi.subnetMask());
//  Serial.print("Gateway: ");
//  Serial.println(WiFi.gatewayIP());
}
 int value = 0;

 void loop() {

  if(Serial.available())
    {
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
  
}

void get_data()
{
  delay(5000);
  ++value;
//  Serial.print("connecting to ");
//  Serial.println(host);
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
 String url = "/get_data.php?id=" + String(id) + "&num="+ String(num);
 //String url =  "/127.0.0.1/new.php?x=22";
 //localhost/send_data.php?id=1&num=10
//  Serial.print("Requesting URL: ");
//  Serial.println(url);
   // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  delay(500);
  int flag=0;
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    if (flag==0)
    {
    //  Serial.println("Flag still 0");
      String line = client.readStringUntil('\r');
    //  Serial.println(line);
      if(line=="The data are")
      {
            //    Serial.print("Now flag is 1");
                    flag=1;

      }
    }
    if(flag==1)
      {
         String count = client.readStringUntil('\r');
       //  Serial.println("The total number of data are ");
         Serial.print(count);
         Serial.print(' ');
         
                  //       Serial.print("Now flag is 2");

          flag=2;
      }
     if (flag==2)
     {
           String sid  = client.readStringUntil('\r');
       
           String food  = client.readStringUntil('\r');
           
           String price  = client.readStringUntil('\r');
           String num_selected  = client.readStringUntil('\r');
           String prepared  = client.readStringUntil('\r');

         //  Serial.print("id no ");
           Serial.print(sid);
                    Serial.print(' ');

          // Serial.print(" food name: ");
           Serial.print(food);
                    Serial.print(' ');

          // Serial.print(" price: ");
           Serial.print(price);
                    Serial.print(' ');

         //  Serial.print("total selected ");
           Serial.print(num_selected);
                    Serial.print(' ');

         //  Serial.print(" prepared: ");
           Serial.print(prepared);
                    Serial.print(' ');


     }

  }

  Serial.println();
  Serial.println("closing connection");
}


void send_data()
{
  delay(5000);
  ++value;
  //Serial.print("connecting to ");
  //Serial.println(host);
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
   // Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
 String url = "/send_data.php?id=" + String(id) + "&num="+ String(num);
 //String url =  "/127.0.0.1/new.php?x=22";
 //localhost/send_data.php?id=1&num=10
  //Serial.print("Requesting URL: ");
  //Serial.println(url);
   // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  delay(500);
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
      String line = client.readStringUntil('\r');
    //  Serial.println(line);
  }

 // Serial.println();
  //Serial.println("closing connection");
}




