//Bình thường giá trị điện áp lấy từ cầu phân áp của 
//quang trở sẽ hiển thị trên LCD

//Khi có ánh sáng từ đèn flash chiếu vào thì kết quả
//điện áp hiển thị lên OLED

//Bth V = 3.33v
//Flash V = 0.24v
#include <LiquidCrystal.h>

const int RS = 9, EN = 8, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setup() {
  pinMode(A0, INPUT);   //Đọc điện áp
  
  pinMode(2, OUTPUT);   //Chân LCD
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(8, OUTPUT);   //RS & E
  pinMode(9, OUTPUT);

  Serial.begin(9600);
  
  lcd.begin(16,2);
  
  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  
  delay(2000);

  oled.clearDisplay();
  
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  
}

void loop() {
  long gia_tri = analogRead(A0);
  float volt = gia_tri * 5.0 / 1023;
  Serial.println(volt);
  delay(500);
  lcd.setCursor(0,0);
  if(volt>3){
    oled.clearDisplay();
    
    lcd.print("Dien ap = ");
    lcd.print(volt);
    lcd.clear();
  
    Serial.print("Dien ap = ");
    Serial.print(volt);
    Serial.print("v");
    
    oled.print("");
    oled.display();
  }
  else{
    oled.setCursor(0,0);
    oled.print("Dien ap = ");
    oled.print(volt);
    oled.print("v");
    oled.display();
    oled.clearDisplay();
    
  }
}
