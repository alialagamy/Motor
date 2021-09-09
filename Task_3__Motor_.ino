#define led 10
#define motor 9
int potPin = 0;
int potval = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(motor,OUTPUT);
  pinMode(A0,INPUT); 
}
void loop() {
potval = analogRead(potPin);
Serial.println(potval);
potval = map(potval, 0, 1023, 0, 255);
analogWrite(10,potval);
  if(potval>512){
    potval = map(potval, 0, 512, 0, 255);  
    Serial.println(potval);
    analogWrite(led,potval);
          digitalWrite(motor,LOW);
    digitalWrite(led,HIGH);
    digitalWrite(led,LOW);
    }else{
      potval = map(potval, 512, 1023, 0, 255);
      Serial.println(potval);
      analogWrite(led,potval);
      digitalWrite(motor,LOW);
      digitalWrite(motor,HIGH);
      }
}
