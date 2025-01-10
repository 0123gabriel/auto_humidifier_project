// C++ code

//Definicion de variables
const int pin_vent = 8, pin_led = 13;
bool led = true;
unsigned long t_enc = 0, t_apag = 0;

void setup()
{
  //Inicializacion de los pines a usar, y encendido del LED
  pinMode(pin_led, OUTPUT);
  pinMode(pin_vent, OUTPUT);
  digitalWrite(pin_led, led);
  digitalWrite(pin_vent, led);
  
}

void loop()
{
  //Validacion para apagar el LED
  if (millis() - t_enc == 4000 && led == true)
  {
    led = false;
    digitalWrite(pin_led, led);
    digitalWrite(pin_vent, led);
    t_apag = millis();
  }
  
  //Validacion para encender el LED
  if (millis() - t_apag == 1000 && led == false)
  {
    led = true;
    digitalWrite(pin_led, led);
    digitalWrite(pin_vent, led);
    t_enc = millis();
  }

}
