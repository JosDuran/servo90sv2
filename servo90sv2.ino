#include <Servo.h>
//Next, we create an object of the servo library

Servo servo;
//Next, we move proceed to the void setup function where we attach the servo object to a digital pin and set the servo angle to 0. This is known as centering the servo.

int angle = 0;
boolean izquierda=LOW;
boolean derecha = LOW;
int pinizq = 7;
int pinder = 6;
int pinservo = 13;
void setup() {
  Serial.begin(115200);
  servo.attach(pinservo);
  servo.write(angle);
  pinMode(pinizq,INPUT);
  pinMode(pinder, INPUT);
}
//Next, is the loop function. To turn make the servo rotate to a particular degree, we use the servo.write() function to write the degree of rotation we desire to the servo. We used the function to turn the servo from one to the other and back.

void loop() 
{
  izquierda = (digitalRead(pinizq) == HIGH);
  if (izquierda){
 // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  }
  
  }

  derecha = (digitalRead(pinder) == HIGH);
  if (derecha){

 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  }
  
  } 
}
