#include <Servo.h> 

Servo myservo; 

int  d = 3000;
int rad = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
}

 
void loop() 
{ 
  char i[4];
  int cnt = 0;
  for(int cnt = 0; cnt < 3; cnt++) {    
    if (Serial.available() > 0) {
      i[cnt] = Serial.read();     
      Serial.println(i[cnt]);
    }
  }
  i[3] = 0;
  rad = atoi(i);
  Serial.print("I received: ");
  Serial.println(rad);  
  myservo.write(rad);  
}

