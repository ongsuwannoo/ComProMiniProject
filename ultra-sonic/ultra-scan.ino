// Includes the Servo library
#include <Servo.h>

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor

int GetAnalog;
int Fade;
int Vr = A1;

int a = 6; //ขา a ต่อเข้ากับ Pin 2
int b = 2; //ขา b ต่อเข้ากับ Pin 3
int c = 4; //ขา c ต่อเข้ากับ Pin 4
int d = 5; //ขา d ต่อเข้ากับ Pin 5
int e = 8; //ขา e ต่อเข้ากับ Pin 6
int f = 7; //ขา f ต่อเข้ากับ Pin 7
int g = 3; //ขา g ต่อเข้ากับ Pin 8

int t = 10, n = 0, k = 0;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(9); // Defines on which pin is the servo motor attached
  pinMode(a, OUTPUT); //a
  pinMode(b, OUTPUT); //b
  pinMode(c, OUTPUT); //c
  pinMode(d, OUTPUT); //d
  pinMode(e, OUTPUT); //e
  pinMode(f, OUTPUT); //f
  pinMode(g, OUTPUT); //g
}
void loop(){
  loop_radar();
  //loop_Vr_degree();
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
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  Serial.print(k); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

  if(t != n)
    turnOff(); //ทำการดับไฟทั้งหมดเมื่อกำลังจะเปลี่ยนตัวเลข เพื่อไม่ให้ไฟดวงเดิมค้างสถานะติดไว้
  t = n;
}
void loop_radar() {
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
    myServo.write(i);
    delay(30-n);
    distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    Serial.print(i); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    
    GetAnalog = analogRead(Vr);
    Fade = GetAnalog;
    n = Fade/102;
    showNumber(n);
    if(t != n)
      turnOff(); //ทำการดับไฟทั้งหมดเมื่อกำลังจะเปลี่ยนตัวเลข เพื่อไม่ให้ไฟดวงเดิมค้างสถานะติดไว้
    t = n;
  }
  // Repeats the previous lines from 165 to 15 degrees
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
      turnOff(); //ทำการดับไฟทั้งหมดเมื่อกำลังจะเปลี่ยนตัวเลข เพื่อไม่ให้ไฟดวงเดิมค้างสถานะติดไว้
    t = n;
  }
  
}
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

void showNumber(int number) //สร้าง Function ชื่อ showNumber ที่ใช้ในการแสดงผลตัวเลข โดยรับค่า number จาก void loop มาอีกที การสร้าง fuction จะช่วยให้ประหยัดพื้นที่และทำให้ไม่สับสนในการเรียกใช้งานโปรแกรม
{
  //เงื่อนไขที่ Segment a ไฟติด เมื่อไม่ใช่เลข 1 และเลข 4
  if(number != 1 && number != 4)
    digitalWrite(a,LOW);
  
  //เงื่อนไขที่ Segment b ไฟติด
  if(number != 5 && number != 6)
    digitalWrite(b,LOW);
  
  //เงื่อนไขที่ Segment c ไฟติด
  if(number != 2)
    digitalWrite(c,LOW);

  //เงื่อนไขที่ Segment d ไฟติด
  if(number != 1 && number != 4 && number != 7)
    digitalWrite(d,LOW);
  
  //เงื่อนไขที่ Segment e ไฟติด เมื่อเป็นเลข 2 หรือ 6 หรือ 8 หรือ 0
  if(number == 2 || number == 6 || number == 8 || number == 0)
    digitalWrite(e,LOW);
  
  //เงื่อนไขที่ Segment f ไฟติด
  if(number != 1 && number != 2 && number != 3 && number != 7)
    digitalWrite(f,LOW);
  
  //เงื่อนไขที่ Segment g ไฟติด
  if (number != 0 && number != 1 && number != 7)
    digitalWrite(g,LOW);
}

void turnOff() //สร้าง Function ชื่อ turnOff ที่ใช้ในการดับไฟทั้งหมด เพื่อ Reset เมื่อกำลังจะเปลี่ยนเป็นอีกตัวเลขหนึ่ง
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
