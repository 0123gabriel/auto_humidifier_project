// C++ code
#include <LiquidCrystal_I2C.h>

String nom[4] = {"Gabriel", "Andrea", "Alexander", "Proyecto"};
String ap[4] = {"Garcia", "Peralta", "Pastor", "Humidificador"};
int i;

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() 
{
  lcd.init();
  lcd.backlight();
  
}

void loop() 
{
  for (i = 0; i < 4; i++)
  {
    lcd.setCursor(0,0);
    lcd.print(nom[i]);
    lcd.setCursor(0,1);
    lcd.print(ap[i]);
    lcd.display();
    delay(1000);
    lcd.noDisplay();
    delay(1000);
    lcd.clear();
  }
}
