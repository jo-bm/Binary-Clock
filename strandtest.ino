
//test leds only without clock 
bool test = false;

// declare current time in four digits. HHMM
String currentTime="1407";

// Extract hours and minutes from currentTime
int chours = (currentTime.substring(0, 2)).toInt();
int cminutes = (currentTime.substring(2)).toInt();

// Convert hours and minutes to milliseconds
unsigned long hoursMillis = chours * 3600000;
unsigned long minutesMillis = cminutes * 60000;


int led1=2;
int led2=3;
int led3=9;
int led4=6;
int led5=4;
int led6=5;
int led7=16;
int led8=8;
int led9=7;
int led10=15;
int led11=14;
int led12=A0;
int led13=10;
unsigned long myTime;


void setup() 
{
 //pinMode(pin,mode);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(16,OUTPUT);
 pinMode(14,OUTPUT);
 pinMode(15,OUTPUT);
 pinMode(A0,OUTPUT);

 Serial.begin(9600);
}



void loop() {

  if (test) {
    int row4[] = {led1, led2, led3, led4, led5, led6, led7, led8, led9, led10, led11, led12, led13};
  // Loop over the LED pins and turn them on one by one
  for (int i = 0; i < 13; i++) {
    digitalWrite(row4[i], HIGH);
    delay(200);
  }

  // Turn off all the LED pins
  for (int i = 0; i < 13; i++) {
    digitalWrite(row4[i], LOW);
  }
    return;
  }
 
  unsigned long myTime = millis()+ hoursMillis + minutesMillis;
  int hours = (myTime / 3600000) % 24; // 1 hour = 3600000 milliseconds
  int minutes =(myTime / 60000) % 60; // 1 minute = 60000 milliseconds

  // Convert hours and minutes to string format
  char timeStr[6]; // Allocate buffer for time string
  sprintf(timeStr, "%02d%02d", hours, minutes); // Format hours and minutes into time string

  Serial.print("Time: ");
  Serial.println(timeStr);
  
  
  // ~~~ prepare first leds row 
  int digit1 = timeStr[0] - '0';
  String digit1BIN = String(digit1, BIN);
  //complete with 0s
  while (strlen(digit1BIN.c_str()) != 2) {
      digit1BIN = "0" + digit1BIN;  
  }
  
  int row1[] = {led2, led1};
  
  // ~~~ prepare second leds row 
  int digit2 = timeStr[1] - '0';
  String digit2BIN = String(digit2, BIN);
  
  //complete with 0s
  while (strlen(digit2BIN.c_str()) != 4) {
      digit2BIN = "0" + digit2BIN;  
  }
  
  int row2[] = {led6, led5, led4, led3};
  
  
  // ~~~ prepare third leds row
  int digit3 = timeStr[2] - '0';
  String digit3BIN = String(digit3, BIN);
  
  //complete with 0s
  while (strlen(digit3BIN.c_str()) != 3) {
      digit3BIN = "0" + digit3BIN;  
  }
  
  int row3[] = {led9, led8, led7};
  

  // ~~~ prepare fourth leds row
  int digit4 = timeStr[3] - '0';
  String digit4BIN = String(digit4, BIN);
  
  //complete with 0s
  while (strlen(digit4BIN.c_str()) != 4) {
      digit4BIN = "0" + digit4BIN;  
  }
  
  int row4[] = {led13, led12, led11 ,led10};
  
  
  Serial.print("digit1: ");
  Serial.println(digit1BIN);
  for (int i = 0; i < digit1BIN.length(); i++) {

    
    if (digit1BIN[i] == '1'){
      digitalWrite(row1[i], HIGH);
    }
    else {
        digitalWrite(row1[i], LOW);
    }
  }
  
  
  Serial.print("digit2: ");
  Serial.println(digit2BIN);
  for (int i = 0; i < digit2BIN.length(); i++) {

    
    if (digit2BIN[i] == '1'){
      digitalWrite(row2[i], HIGH);
    }
    else {
        digitalWrite(row2[i], LOW);
    }
  }
  
  Serial.print("digit3: ");
  Serial.println(digit3BIN);
  for (int i = 0; i < digit3BIN.length(); i++) {

    
    if (digit3BIN[i] == '1'){
      digitalWrite(row3[i], HIGH);
    }
    else {
        digitalWrite(row3[i], LOW);
    }
  }
  
  Serial.print("digit4: ");
  Serial.println(digit4BIN);
  for (int i = 0; i < digit4BIN.length(); i++) {

    
    if (digit4BIN[i] == '1'){
      digitalWrite(row4[i], HIGH);
    }
    else {
        digitalWrite(row4[i], LOW);
    }
  }

  delay(1000);
  
  
}
