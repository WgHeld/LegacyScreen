#include <Servo.h> 

Servo myservo; 

int  d = 3000;
int rad = 0;
char i[4];
int cnt = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(50);
}

 
void loop() 
{ 
  if (Serial.available() > 0) {
    i[cnt] = Serial.read();     
    Serial.println(i[cnt]);
    cnt++;
  }
  if(cnt == 3) {
    i[3] = 0;
    rad = atoi(i);
    Serial.print("I received: ");
    Serial.println(rad); 
    if(rad >= 50 && rad <= 165) {
      myservo.write(rad);  
    }    
    cnt = 0;
  }
}

