int botao = 2;
bool estadoBotao = 0;

void setup(){

  pinMode(botao,INPUT);
  Serial.begin(9600);
}

void loop(){
    estadoBotao = digitalRead(botao);

    if(estadoBotao == 0){
        Serial.println("Desligado!");
    }
    else{
        Serial.println("Ligado!");
    }
}