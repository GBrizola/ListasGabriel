int bits = 0;
int led = 9;

void setup(){
  
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    bits = analogRead(A0)/4;
    for(bits; bits < 255; bits++)
    if(bits == 0){
        digitalWrite(led,0);
        Serial.println("Desligado!");
    }
    else{
        analogWrite(led, bits);
        Serial.println("Ligado!");
    }
}