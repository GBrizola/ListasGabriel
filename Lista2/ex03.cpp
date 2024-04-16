int led_vermelho = 8;
int led_amarelo = 10;
int led_verde = 9;

    void setup() {
    pinMode(led_vermelho, OUTPUT);
    pinMode(led_verde, OUTPUT);
    pinMode(led_amarelo, OUTPUT);
    Serial.begin(9600);
    }

    void loop() {
    char liga_desliga = Serial.read();

    if (liga_desliga == 'r' || liga_desliga =='R'){
    digitalWrite(led_vermelho,1);
    digitalWrite(led_verde,0);
    digitalWrite(led_amarelo,0);
    Serial.println("led_vermelho: Ligado!");
    }

    else if (liga_desliga == 'g' || liga_desliga =='G'){ 
        digitalWrite(led_verde,1);
        digitalWrite(led_amarelo,0);
        digitalWrite(led_vermelho,0);
        Serial.println("led_verde: Ligado!");
    }

    else if (liga_desliga == 'y' || liga_desliga =='Y'){
        digitalWrite(led_amarelo,1);
        digitalWrite(led_vermelho,0);
        digitalWrite(led_verde,0);
        Serial.println("led_amarelo: Ligado!");
            }
    }
