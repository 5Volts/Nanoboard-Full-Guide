#include<SoftwareSerial.h>

#define TX 8
#define RX 2

String AP="ssid"; //put the ssid for wifi you want to connect here
String PASS="password"; //put the password for wifi you want to connect here
String HOST="host"; //put the host you want to connect here (if you're using my server, 
                    //it will be your computer's ipv4 address, like 192.168.25.27)
String PORT="port"; //put the port you want to connect here (most likely 5000)
String getData;

int countTrueCommand;
int countTimeCommand;
boolean found =false;

SoftwareSerial esp8266(RX,TX);
void setup() {

  Serial.begin(9600);
  esp8266.begin(9600);
  connect_to_AP(AP,PASS);
}

void loop() {
  get_info();
}

void get_info(){
  String response = ""; 
  sendCommand("AT+CIPMUX=1",5,"OK");
   sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
   getData = "GET /esp_api HTTP/1.1";
   //GET /esp_api HTTP/1.1
   //21char
   
   sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
   esp8266.println(getData);
   esp8266.println();   
   response = esp8266.readString();  
   string2info(response);
   sendCommand("AT+CIPCLOSE=0",5,"OK");
}

void string2info(String mess){
  int idx_b = mess.indexOf("brightness");
  String brightness = mess.substring(idx_b+12, idx_b+15);
  int idx_red = mess.indexOf("red");
  int idx_green = mess.indexOf("green");
  int idx_blue = mess.indexOf("blue");  

  int end_red = readuntilcomma(mess, idx_red);
  int end_blue = readuntilcomma(mess, idx_blue);
  int end_green = readuntilcomma(mess, idx_green);
  String r_intensity = mess.substring(idx_red+5,end_red);  
  String g_intensity = mess.substring(idx_green+7,end_green);  
  String b_intensity = mess.substring(idx_blue+6,end_blue);  
 
  Serial.println(brightness);
  analogWrite(9,brightness.toInt());
  
 
}

int readuntilcomma(String anystring, int idx){  
  while(true){
//    Serial.print(char(anystring[idx]));
//    Serial.print("  ");
//    Serial.print("}");
//    Serial.print("  ");
//    Serial.println(char(anystring[idx]) == '}');
    if(char(anystring[idx]) == ',' || char(anystring[idx]) == '}'){      
      break;
    }
    idx ++;
  }
  return idx;
}

void connect_to_AP(String AP, String PASS){
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}

void sendCommand(String command, int maxTime, char readReplay[]) {  
  Serial.print(countTrueCommand);
  Serial.print(" AT Command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    esp8266.println(command);//at+cipsend        
    if(esp8266.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("OYI");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
  
 }
