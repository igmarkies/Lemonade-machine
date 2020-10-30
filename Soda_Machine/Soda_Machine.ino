#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

// Contant Variables Declarations
#define start 3
#define errorWifi 4

#define Button_Up 22
#define  Button_Down 23
#define  Button_Right 24
#define  Button_Left 25
#define  Button_Ok 26

// Variables Declaration
int Ratio = 0;

void setup() {
  // Library declarations
  void UpdateMenu(int Menu);
  int Keys_V ();

  // Serial Communication Setup
  Serial.begin(9600);
  Serial.println ("Soda Machine Rev 1.0");
  
  // LCD Setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print ("Soda Machine Rev 1.0");

  // Pin Mode Declaration
  pinMode (Button_Up, INPUT_PULLUP);
  pinMode (Button_Down, INPUT_PULLUP);
  pinMode (Button_Right, INPUT_PULLUP);
  pinMode (Button_Left, INPUT_PULLUP);
  pinMode (Button_Ok, INPUT_PULLUP);

}

void loop() {
  UpdateMenu (Keys_V());

}
void UpdateMenu (int Menu){
  switch (Menu){
    case 0:
        Menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print ("Menu");
      lcd.setCursor (0, 2);
      lcd.print ("> Select drink");
      lcd.setCursor (0, 3);
      lcd.print ("  Setting");
      break;
    case 2:
      lcd.clear();
      lcd.print ("Menu");
      lcd.setCursor (0, 2);
      lcd.print ("  Select drink");
      lcd.setCursor (0, 3);
      lcd.print ("> Setting");
      break;
    case 3:
      Menu = 2;
      break;
  }
}

int Keys_V (){
  int count;
  
 if (digitalRead(Button_Down)){
    count++;
    while (digitalRead(Button_Down));
  }
  if (digitalRead(Button_Up)){
    count--;
    while (digitalRead(Button_Up));
  } 
  return count;
}

int Keys_H (){
  int count;
  
 if (digitalRead(Button_Right)){
    count++;
    while (digitalRead(Button_Right));
  }
  if (digitalRead(Button_Left)){
    count--;
    while (digitalRead(Button_Left));
  } 
  return count;
}
int Keys_Ok (){
  int count;
  
 if (digitalRead(Button_Down)){
    count++;
    while (digitalRead(Button_Down));
  }
  if (digitalRead(Button_Up)){
    count--;
    while (digitalRead(Button_Up));
  } 
  return count;
}
