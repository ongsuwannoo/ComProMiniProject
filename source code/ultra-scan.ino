#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>

int show;
LiquidCrystal_PCF8574 lcd(0x3F);

const int trigPin = 10;
const int echoPin = 11;
int speed;

long duration;
int distance;
Servo myServo;

int GetAnalog;
int Fade;
int Vr = A1;

int a = 6; 
int b = 2; 
int c = 4; 
int d = 5; 
int e = 8; 
int f = 7; 
int g = 3; 

int t = 10, n = 0, k = 0;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(9); 
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT); 
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT); 
  pinMode(g, OUTPUT); 
  lcd.begin(16, 2);
  lcd.setBacklight(100);
}
void loop(){
  loop_radar();
  //loop_Vr_degree();
  //test();
}
void loop_Vr_degree() {
  GetAnalog = analogRead(Vr);
  Fade = GetAnalog;
  n = Fade/102;
  k = Fade/6;
  k = 175 - k;
  showNumber(n);
  
  myServo.write(k);
  delay(10);
  distance = calculateDistance();
  Serial.print(k); 
  Serial.print(","); 
  Serial.print(distance);
  Serial.print(".");

  if(distance <40){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Found object");
    lcd.setCursor(1, 1);
    lcd.print("Distance : ");
    lcd.setCursor(12, 1);
    lcd.print(distance);
    
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("Not found object");
    lcd.setCursor(1, 1);
    lcd.print("Distance : ");
    lcd.setCursor(12, 1);
    lcd.print(distance);
  } 

  if(t != n)
    turnOff();
  t = n;
}
void loop_radar() {
  for(int i=15;i<=165;i++){  
    myServo.write(i);
    delay(30-n);
    distance = calculateDistance();
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance);
    Serial.print(".");
    if(distance <40){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Found object");
      lcd.setCursor(1, 1);
      lcd.print("Distance : ");
      lcd.setCursor(12, 1);
      lcd.print(distance);
    }
  else{
    lcd.setCursor(0, 0);
    lcd.print("Not found object");
    lcd.setCursor(1, 1);
    lcd.print("Distance : ");
    lcd.setCursor(12, 1);
    lcd.print(distance);
  }
    
    GetAnalog = analogRead(Vr);
    Fade = GetAnalog;
    n = Fade/102;
    showNumber(n);
    if(t != n)
      turnOff();
    t = n;
  }
  for(int i=165;i>15;i--){  
    myServo.write(i);
    delay(30-n);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    GetAnalog = analogRead(Vr);
    Fade = GetAnalog;
    n = Fade/102;
    showNumber(n);
    if(t != n)
      turnOff();
    t = n;
  }
  
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}

void showNumber(int number)
{
  if(number != 1 && number != 4)
    digitalWrite(a,LOW);
  
  if(number != 5 && number != 6)
    digitalWrite(b,LOW);
  
  if(number != 2)
    digitalWrite(c,LOW);

  if(number != 1 && number != 4 && number != 7)
    digitalWrite(d,LOW);
  
  if(number == 2 || number == 6 || number == 8 || number == 0)
    digitalWrite(e,LOW);
  
  if(number != 1 && number != 2 && number != 3 && number != 7)
    digitalWrite(f,LOW);
  
  if (number != 0 && number != 1 && number != 7)
    digitalWrite(g,LOW);
}

void turnOff()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void test(){
  int fast;
  GetAnalog = analogRead(Vr);
  Fade = GetAnalog;
  n = Fade/102;
  fast = 30-n;
  delay(fast);
  Serial.println(fast);
}
