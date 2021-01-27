//maskerbox
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);//alamat lcd bisa 0x3f, 0x27
int IRSensorM = 8; // Pin out IR Sensor ke pin 8 arduino
int in1 = 2; // Motor Driver 1 pin 2 arduino
int in2 = 3; // Motor Driver 2 pin 3 arduino
int pwm = 9; //pin enA driver ke pin 9 arduino

void setup() {
  Serial.begin(9600);
   lcd.begin();
  pinMode(pwm, OUTPUT);     //motor driver sbg out
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);  
  pinMode(IRSensorM, INPUT); //irsensor sbg in
  }

void loop() {
  lcd.setCursor(0,0); //tampilan lcd
  lcd.print("Letakkan Tangan");
  lcd.setCursor(0,1);
  lcd.print("  Pada Sensor");
  delay(2000);
  lcd.clear();

      if (digitalRead (IRSensorM) == LOW) //ketika sensor membaca tangan
      {          
  lcd.setCursor(0,0);
  lcd.print("   Silahkan");
  lcd.setCursor(0,1);
  lcd.print("Ambil Masker");
        Serial.println(120);
        analogWrite(pwm, 120);      //perangkat mekanik berputar
        delay(10);
        digitalWrite( in1, HIGH);
        digitalWrite( in2, LOW);
        delay(400);//480
      digitalWrite( in1, LOW);
      digitalWrite( in2, LOW);
      analogWrite(pwm, 255); 
      while(digitalRead (IRSensorM) == LOW);
      delay(2000);
     }
      else if(digitalRead (IRSensorM) == HIGH)
      {
        digitalWrite( in1, LOW);
      digitalWrite( in2, LOW);
      }
    }
