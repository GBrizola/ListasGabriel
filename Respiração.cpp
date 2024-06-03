int led = 3;

void setup(){
    pinMode(led,OUTPUT);
}

void loop(){
    for(int i=0; i<=256; i++){
        analogWrite(led,i);
        delay(50);
    }
    delay(100);
    for(int j = 0; j<=256; j--){
        analogWrite(led,j);
        delay(50);
    }
    delay(100);

}