int vermelho = 3;
int amarelo = 4;
int verde = 5;
int tempo_intermitente = 1000;
int botao = 2;
int verde2 = 6;
int vermelho2 = 7;

//tem energia -> DigitalRead() retorna 1
// não tem energia -> DigitalRead retorna 0


//void setup
void setup(){
    //Determina que os pinos 3,4,5 serão saídas.
    pinMode(vermelho, OUTPUT);
    pinMode(amarelo, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(botao, INPUT);
  	pinMode(verde2, OUTPUT);
  	pinMode(vermelho2, OUTPUT);

    controlaCor(amarelo,1000, false);
    controlaCor(amarelo,1000, false);
    controlaCor(amarelo,1000, false);

}


//{tipo do retorno} {nome da função} (parâmetros)
//void loop
void loop(){ 
    bool estadoBotao = false;
    estadoBotao = digitalRead(botao);
  
  if(estadoBotao == true){
    digitalWrite(vermelho2,1);
    controlaCor(verde, 4000, true);
    controlaCor(amarelo, 2000, true);
    digitalWrite(vermelho,1);
    digitalWrite(vermelho2,0);
    digitalWrite(verde2,1);
    delay(3000);
    digitalWrite(verde2,0);
    controlaCor(vermelho2, 500, false);
    controlaCor(vermelho2, 500, false);
    controlaCor(vermelho2, 500, false);
    digitalWrite(vermelho,0);
    }
  
   if(estadoBotao == false){
    
    digitalWrite(vermelho2, 1);
    controlaCor(verde, 7000, true);
    controlaCor(amarelo, 4000, true);
    digitalWrite(vermelho2,0);
    digitalWrite(verde2,1);
    digitalWrite(vermelho,1);
    delay(3000);
    digitalWrite(verde2,0);
    controlaCor(vermelho2, 500, false);
    controlaCor(vermelho2, 500, false);
    controlaCor(vermelho2, 500, false);
    digitalWrite(vermelho,0);
   }
  
}
//Função serve para controlar a cor que eu quiser, pelo tempo que eu quiser.
int controlaCor (int cor, int tempo, bool esta_no_loop) {
    digitalWrite(cor, 1);
    delay(tempo);
    digitalWrite(cor, 0);
  
    if(esta_no_loop == false){
        delay(tempo);
        return 0;
        //se bateu aqui, é por que a função foi chamada no setup
    }
    else{
        return 1;
        //se bateu aqui, é por que a função foi chamada no Loop
    }
}
