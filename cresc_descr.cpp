int vermelho = 7;
int amarelo = 6;
int verde = 5;
int azul = 4;
int laranja = 3;
int branco = 2;

int pot = 0;
int tempo = 0;
String opcao = "";

void setup(){
    Serial.begin(9600);
    Serial.println("Inicializando...");

    for(int i=2; i<8; i++){
        pinMode(i,OUTPUT);
        delay(2000);
    String pino = "Definindo pino: ";
    Serial.println(pino + i);
    }

    Serial.println("Sistema Pronto!\n");
    Serial.println("Pressione C para Crescente");
    Serial.println("Pressione D para Descrescente");
}

void loop(){

    pot = analogRead(A0);
    tempo = map(pot, 0, 1023, 5000, 200);

    if(Serial.available() > 0){
        opcao = Serial.readString();
        String message = "Tempo em ms: ";

        Serial.println(opcao);
        if(opcao == "D" || opcao == "C"){
            Serial.println(message + tempo);
            controla(opcao);
        }
        else{
            Serial.println("Opção Indesejada!");
        }
    }
}

void controla(String sentido){
    if(sentido == "C"){
        Serial.println("Crescente");
        for(int i = 2; i<8; i++){
            digitalWrite(i,1);
            delay(tempo);
            digitalWrite(i,0);
            }
        }
    else if(sentido == "D"){
        Serial.println("decrescente");
        for(int i = 7; i>1; i--){
            digitalWrite(i,1);
            delay(tempo);
            digitalWrite(i,0);
        }
    }
}