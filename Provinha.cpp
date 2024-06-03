#include <LiquidCrystal_I2C.h>
int bot_azul = 33;
int bot_verde = 34;
int bot_vermelho = 35;
int bot_amarelo = 32;

int menu = 0;
int opcao = 0;
int tempo = 1000;
int seg = 0;
int minutos = 0;
int horas = 0;
int contador = 0;
int contadorR = 0;

LiquidCrystal_I2C LCD = LiquidCrystal_I2C(0x27, 16, 2);

void setup(){
  pinMode(bot_azul, INPUT);
  pinMode(bot_verde, INPUT);
  pinMode(bot_vermelho, INPUT);
  pinMode(bot_azul, INPUT);
  LCD.init();
  LCD.backlight();
}

void loop(){
  bool botao_amarelo = digitalRead(bot_amarelo);
  bool botao_verde = digitalRead(bot_verde);
  bool botao_vermelho = digitalRead(bot_vermelho);
  bool botao_azul = digitalRead(bot_azul);

  if(menu >= 0 && menu <= 3){
    if(botao_azul == true){
      menu += 1;
      LCD.clear();
      delay(200);
    }

    if(botao_amarelo == true){
      menu -= 1;
      LCD.clear();
      delay(200);
    }

    if(menu > 3){
      menu = 0;
      LCD.clear();
    }

    if(menu < 0){
      menu = 3;
      LCD.clear();
    }
    if(botao_vermelho == true){
      menu = 0;
      LCD.clear();
    }
  }

  switch(menu){
    case 1:
    LCD.setCursor(3,0);
    LCD.print("Click");
    if(botao_verde == true){
      opcao = menu;
      LCD.clear();
    }
    break;

    case 2:
    LCD.setCursor(3,0);
    LCD.print("Relogio");
    if(botao_verde == true){
      opcao = menu;
      LCD.clear();
    }
    break;

    case 3:
    LCD.setCursor(3,0);
    LCD.print("Zerar dados");
    if(botao_verde == true){
      opcao = menu;
      LCD.clear();
    }
    break;

    case 4:
    break;

    default:
    LCD.setCursor(3,0);
    LCD.print("Bem vindo!");
    opcao = 4;
    break;
  }

  switch(opcao){
    case 1:
    menu = 4;
    if(botao_vermelho == true){
      menu = 0;
      LCD.clear();
    }

    if(botao_azul == 1){
      contador += 1;
    }
    if(botao_amarelo == 1){
      contador = 0;
    }

    LCD.setCursor(3,0);
    LCD.print("Clicks:");
    LCD.setCursor(11,0);
    LCD.print(contador);
    break;

    case 2:
    menu = 4;
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
    delay(tempo);

    if(botao_azul == 1){
      tempo = 250;
    }
    if(botao_amarelo == 1){
      tempo = 1000;
    }

    if(botao_vermelho == true){
      menu = 0;
      LCD.clear();
    }

    if(seg > 59){
      seg = 0;
      minutos += 1;
      LCD.clear();
    }
    if(minutos > 59){
      minutos = 0;
      horas += 1;
    }
    break;

    case 3:
    menu = 4;
    LCD.setCursor(3,1);
    LCD.print("Zerar dados?");
    if(botao_verde == true){
      contadorR += 1;
      delay(1000);
      if(contadorR == 3){
        seg = 0;
        minutos = 0;
        horas = 0;
        contador = 0;
        menu = 0;
        contadorR = 0;
        LCD.clear();
      }
    }
    if(botao_vermelho == true){
      menu = 0;
      LCD.clear();
    }
    break;

    default:
    LCD.setCursor(3,1);
    LCD.print("");
    break;
  }
}