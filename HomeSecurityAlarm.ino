#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //My LCD address is 0x27

// Define sensor and buzzer pins
const int sensor = 11;
const int buzzer = 6;

void setup() {
  Wire.begin(8, 9);  //Specify SDA and SCL pins

  lcd.init();  //initialize the LCD
  lcd.backlight();  //Turn on Backlight of LCD

  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);


  digitalWrite(buzzer, LOW);
  delay(2000);
}

void loop() {
  int movement = digitalRead(sensor);

  if (movement == HIGH) {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 0); 
    lcd.print("Warning!"); 
    lcd.setCursor(0, 1);         
    lcd.print("Movement Detected."); 
    delay(3000); 
  } 
  else {
    digitalWrite(buzzer, LOW); 
    lcd.setCursor(0, 0);         
    lcd.print("Peace..");
    lcd.setCursor(0, 1);
    lcd.print("No movement here.");
    delay(500); 
  }
}
