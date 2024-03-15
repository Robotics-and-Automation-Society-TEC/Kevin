#include <Servo.h>

Servo myservo;

void setup(){
  myservo.attach(9);
}

//De 0 a 89 es dirección antihoraria, siendo 0 la mayor velocidad.
//90 es condición de parada.
//De 91 a 180 es dirección horaria, siendo 180 la mayor velocidad.

void loop(){
  myservo.write(90); //Valor del servo para estar quieto.
  delay(3000);
  myservo.write(180); //
  delay(1000);
  myservo.write(90); //Valor del servo para estar quieto.
  delay(3000);
  myservo.write(0); //
  delay(1000);
}