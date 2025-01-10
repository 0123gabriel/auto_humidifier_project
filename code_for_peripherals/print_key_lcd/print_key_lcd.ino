// C++ code
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

int lcd_col = 0;
int fil_lcd = 0;

const byte filas = 4;
const byte colum = 4;
char keys[filas][colum] = {
    {'1',  '2', '3', 'A'},
    {'4',  '5', '6', 'B'},
    {'7',  '8', '9', 'C'},
    {'*',  '0', '#', 'D'}
};

byte pinfilas[filas] = {9, 8 ,7, 6};
byte pincolum[colum] = {5, 4 ,3, 2};
char tecla; 

Keypad teclado = Keypad(makeKeymap(keys), pinfilas, pincolum, filas, colum);

void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(lcd_col,0);
}

void loop() 
{
  tecla = teclado.getKey();

  if (tecla)
  {
    lcd.print(tecla);
    lcd.setCursor(++lcd_col, fil_lcd);

    if (lcd_col == 15 && fil_lcd == 0)
    {
      lcd_col = -1;
      fil_lcd = 1;
    }
  }
}
