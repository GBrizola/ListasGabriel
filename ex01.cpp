int led_builtin = 13;

void setup() {
  pinMode(led_builtin,OUTPUT);
  Serial.begin(9600);
}

void loop(){
    digitalWrite(led_builtin, 1);
  	Serial.println("Ligado!");
    delay(1000);
    digitalWrite(led_builtin, 0);
    Serial.println("Desligado!");
    delay(1000);
}