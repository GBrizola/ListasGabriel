int botao1 = 6;
int botao2 = 4; 
int led_amarelo = 10;
int led_verde = 9;
int led_vermelho = 8;

int vermelho = 0;
int amarelo = 0;
int verde = 0;

bool estadoBotao1 = 0;
bool estadoBotao2 = 0;

void setup(){
    Serial.begin(9600);
    pinMode(botao1,INPUT);
    pinMode(botao2,INPUT);
  
    pinMode(led_amarelo,OUTPUT);
  	pinMode(led_verde,OUTPUT);
  	pinMode(led_vermelho,OUTPUT);
}

void loop(){
    digitalWrite(led_amarelo,0);
    digitalWrite(led_vermelho,0);
    digitalWrite(led_verde,0);
    estadoBotao1 = digitalRead(botao1);
    estadoBotao2 = digitalRead(botao2);

    if(estadoBotao1 == 1 && estadoBotao2 == 1){
        digitalWrite(led_vermelho,1);
        digitalWrite(led_verde,0);
        digitalWrite(led_amarelo,0);
        if(vermelho > 0){
            Serial.println("led_vermelho: Ligado!");
            vermelho = 0;
    
        }
        else{
            Serial.println("led_vermelho: Desligado!");
            vermelho = 1;
        }
        
    }

    if(estadoBotao1 == 1 ^ estadoBotao2 == 1){
        digitalWrite(led_amarelo,1);
        digitalWrite(led_vermelho,0);
        digitalWrite(led_verde,0);
        if(amarelo > 0){
                Serial.println("led_amarelo: Ligado!");
                amarelo = 0;
            }
            else{
                Serial.println("led_amarelo: Desligado!");
                amarelo = 1;
        }
    }
  
    if(estadoBotao1 == 1 || estadoBotao2 == 1){
        digitalWrite(led_amarelo,0);
        digitalWrite(led_vermelho,0);
        digitalWrite(led_verde,1);
        if(verde > 0){
            Serial.println("led_verde: Ligado!");
            verde = 0;
        }
        else{
            Serial.println("led_verde: Desligado!");
            verde = 1;
        }
    }
}