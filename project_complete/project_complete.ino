#include <DHT.h>
#include <DHT_U.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const int sensor = 2, pin_hum = 10, pin_vent = 11;
int temp;
int hum;
int temp_max = 60, temp_min = 25, hum_max = 30, hum_min = 10;
int temp_in[7] = {0};
int temp_in_i; 

DHT dht(sensor, DHT22);

LiquidCrystal_I2C lcd(0x27,16,2); 

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
  pinMode(pin_hum, OUTPUT);
  pinMode(pin_vent, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Mode: ");
  lcd.setCursor(1,0);
  lcd.print("A: Custom  B: Auto");
  delay(2000);
  lcd.clear();
  KeyBoard();
  dht.begin();
}

void loop() 
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (temp > temp_max || hum > hum_max)
  {
      digitalWrite(pin_vent, HIGH);
  }
  else
  {
    digitalWrite(pin_vent, LOW);
  }

  if (temp < temp_min || hum < hum_min)
  {
      digitalWrite(pin_hum, HIGH);
  }
  else
  {
    digitalWrite(pin_hum, LOW);
  }
  
}


int temp_lect()
{
  tecla = teclado.getKey();
  int i = 0;
  
  if (tecla)
    {
      temp_in[i] = tecla;
      i = i + 1;
    }

    for(int j = i; j >= 0; j--)
    {
       temp_in_i = temp_in_i + temp_in[j]*pow(10, j);
    }
    
    return temp_in_i;
}

void KeyBoard()
{
  tecla = teclado.getKey();

  if (tecla == 'A')
  {
    lcd.setCursor(0, 0);
    lcd.print("Input temp min:");
    lcd.setCursor(1, 0);
    int i = 0;

    temp_min = temp_lect();
    temp_max = temp_lect();
  }
}
