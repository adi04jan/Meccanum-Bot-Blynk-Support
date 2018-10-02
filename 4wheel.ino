#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "API Key";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "PASSWORD";
int x = 0;
int y = 0;
int a = 0;
int b = 0;
int m1 = 0; ///////////// m1     m2
int m2 = 0; ///////////// m3     m4
int m3 = 0;
int m4 = 0;
const int motor1a = 10;
const int motor2a = 11;
const int motor3a = 12;
const int motor4a = 13 ;
const int motor1b = 14;
const int motor2b = 4;
const int motor3b = 5;
const int motor4b = 6 ;
const int motorA = 7 ;
const int motorB = 1 ;
const int motorC = 2 ;
const int motorD = 3 ;
int q;
int w;
int e;
int g;
int spdf;
int fpwm1;
int fpwm2;
BLYNK_WRITE(V1) {
  x = param[0].asInt();
  y = param[1].asInt();



  int pwms1 = abs((x - 512) / 2);
  int pwms2 = abs((y - 512) / 2);
  //int pwm1 = map(pwms1, 0, 127, 0, 255);
  //int pwm2 = map(pwms2, 0, 128, 0, 255);
  int r = (pwms1 * pwms1 + pwms2 * pwms2);
  r = sqrt(r);

  if (y > 700 && x < 325 ) { //1
    m1 = 0;
    m2 = 1;
    m3 = 1;
    m4 = 0;

    Serial.println("0   1");
    Serial.println("1   0");
    Serial.println(" 1");
  }
  if (y > 700 && 700 > x && x > 325) { //2
    m1 = 1;
    m2 = 1;
    m3 = 1;
    m4 = 1;

    Serial.println("1   1");
    Serial.println("1   1");
    Serial.println(" 2");
  }
  if (y > 700 && x > 700) { //3
    m1 = 1;
    m2 = 0;
    m3 = 0;
    m4 = 1;

    Serial.println("1   0");
    Serial.println("0   1");
    Serial.println(" 3");
  }
  if (y < 700 && y > 325 && x < 325) { //4
    m1 = 2;
    m2 = 1;
    m3 = 1;
    m4 = 2;

    Serial.println("-1   1");
    Serial.println("1   -1");
    Serial.println(" 4");
  }
  if (y < 700 && y > 325 && 700 > x && x > 325) { //5
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;

    Serial.println("0   0");
    Serial.println("0   0");
    Serial.println(" 5");
  }
  if (y < 700 && y > 325 && x > 700 ) { //6
    m1 = 1;
    m2 = 2;
    m3 = 2;
    m4 = 1;

    Serial.println("1   -1");
    Serial.println("-1   1");
    Serial.println(" 6");
  }
  if (y < 325 && x < 325) { //7
    m1 = 2;
    m2 = 0;
    m3 = 0;
    m4 = 2;

    Serial.println("-1   0");
    Serial.println("0   -1");
    Serial.println(" 7");
  }
  if (y < 325 &&  700 > x && x > 325) { //8
    m1 = 2;
    m2 = 2;
    m3 = 2;
    m4 = 2;

    Serial.println("-1   -1");
    Serial.println("-1   -1");
    Serial.println(" 8");
  }
  if (y < 325 && x > 700 ) { //9
    m1 = 0;
    m2 = 2;
    m3 = 2;
    m4 = 0;

    Serial.println("0   -1");
    Serial.println("-1   0");
    Serial.println(" 9");
  }
  // Do something with x and y
  /* Serial.print("X = ");
    Serial.print(x);
    Serial.print("; Y = ");
    Serial.println(y);*/
  //drive(m1, m2, m3, m4, r);
  delay(100);
}

BLYNK_WRITE(V2) {
  a = param[0].asInt();
  b = param[1].asInt();

  // Do something with x and y
  /* Serial.print("X = ");
    Serial.print(a);
    Serial.print("; Y = ");
    Serial.println(b);*/
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
}

void loop()
{
  Blynk.run();

}

void drive ( int q, int w, int e, int g,int spdf) {


 fpwm1 = abs(spdf - 255);
 fpwm2 = map (fpwm1, 0, 255, 255, 0);



  if ( q = 0) {
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, LOW);
    analogWrite(motorA, fpwm1);

  }
  else if (q = 1) {
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    analogWrite(motorA, fpwm1);

  }
  else if (q = 2) {
    digitalWrite(motor1a, LOW);
    digitalWrite(motor1b, HIGH);
    analogWrite(motorA, fpwm1);

  }

  if ( w = 0) {
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, LOW);
    analogWrite(motorB, fpwm2);

  }
  else if (w = 1) {
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
    analogWrite(motorB, fpwm2);

  }
  else if (w = 2) {
    digitalWrite(motor2a, LOW);
    digitalWrite(motor2b, HIGH);
    analogWrite(motorB, fpwm2);

  }

  if ( e = 0) {
    digitalWrite(motor3a, LOW);
    digitalWrite(motor3b, LOW);
    analogWrite(motorC, fpwm2);

  }
  else if (e = 1) {
    digitalWrite(motor3a, HIGH);
    digitalWrite(motor3b, LOW);
    analogWrite(motorC, fpwm2);

  }
  else if (e = 2) {
    digitalWrite(motor3a, LOW);
    digitalWrite(motor3b, HIGH);
    analogWrite(motorC, fpwm2);

  }

  if ( g = 0) {
    digitalWrite(motor4a, LOW);
    digitalWrite(motor4b, LOW);
    analogWrite(motorD, fpwm1);

  }
  else if (g = 1) {
    digitalWrite(motor4a, HIGH);
    digitalWrite(motor4b, LOW);
    analogWrite(motorD, fpwm1);

  }
  else if (g = 2) {
    digitalWrite(motor4a, LOW);
    digitalWrite(motor4b, HIGH);
    analogWrite(motorD, fpwm1);

  }


  delay(100);

}
