#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

String aux, palavra;
int seg = 0;
int minutos = 0;
int horas = 0;

void setup(){
  LCD.init();
  LCD.backlight();
  Serial.begin(9600);

  LCD.setCursor(0,0);
  LCD.print("Helo world");
  delay(1000);
  LCD.clear();
  LCD.print("Setup pronto");
  LCD.clear();
}

void loop(){

  while(Serial.available() > 0){
   palavra = Serial.readString();
     escreve(0,1, palavra);
    
  }
  relogio();
}

void escreve(int col, int lin, String msg){
  if(msg != aux){
    LCD.clear();
    LCD.setCursor(col,lin);
    LCD.print(msg);
    aux = msg;
  }
  else{
    LCD.setCursor(col,lin);
    LCD.print(msg);
  }
}
void relogio(){
  LCD.setCursor(4,0);
  LCD.print(horas);
  LCD.setCursor(6,0);
  LCD.print(":");
  LCD.setCursor(7,0);
  LCD.print(minutos);
  LCD.setCursor(9,0);
  LCD.print(":");
  LCD.setCursor(11,0);
  LCD.print(seg);
  seg += 1;
  delay(1000);

  if(seg == 60){
    seg = 0;
    minutos += 1;
  }
  if(minutos == 60){
    minutos = 0;
    horas += 1;
  }
}