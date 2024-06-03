int botao = 2;
int a = 3;
int b = 4;
int c = 5;
int d = 6;
int e = 7;
int f = 8;
int g = 9;

int incremento = 0;

void setup(){
    pinMode(botao,INPUT);

    for(int i = 3; i <= 9; i++){
        pinMode(i,OUTPUT);
    }
}

void loop(){
    bool estadoBotao = digitalRead(botao);

    if(estadoBotao == true){
        incremento ++;
        delay(200);
    }

    ligaLeds(incremento);
}

void ligaLeds(int numero){

    switch(numero){

    case 0:
        for(int j = 3; j <= 8; j++){
            digitalWrite(j,1);
        }

        digitalWrite(g,0);

        break;

    case 1:
        for(int j=3; j<=9 ; j++){
            if(j == 4 || j == 5){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 2:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 4 || j == 6 || j == 7 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 3:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 4 || j == 5 || j == 6 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 4:
        for(int j=3; j<=9 ; j++){
            if(j == 4 || j == 5 || j == 8 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 5:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 5 || j == 6 || j == 8 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 6:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 5 || j == 6 || j == 7 || j == 8 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 7:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 4 || j == 5){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 8:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    case 9:
        for(int j=3; j<=9 ; j++){
            if(j == 3 || j == 4 || j == 5 || j == 8 || j == 9){
                digitalWrite(j,1);
            }
            else{
                digitalWrite(j,0);
            }

            }
        break;

    default:
        for(int j=3; j<=9;j++){
                digitalWrite(j,0);
       }
    }
}