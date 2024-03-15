#include <Servo.h>

Servo myservo;

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int servo = 9;
int boton = 8;
int estado;

void setup(){
  Serial.begin(9600);
  myservo.attach(servo);
  pinMode(boton, INPUT);
}

//De 0 a 89 es dirección antihoraria, siendo 0 la mayor velocidad.
//90 es condición de parada.
//De 91 a 180 es dirección horaria, siendo 180 la mayor velocidad.

void loop(){
  val = analogRead(potpin);  // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  if (val <= 30){
    //Serial.println("Antihorario");
    myservo.write(80);

  }
  else if (val >= 150){
    Serial.println("Horario");
    myservo.write(100);
  }
  else {
    Serial.println("Parada");
    myservo.write(90);
  }

  estado = digitalRead(boton);
  if (estado == HIGH){
    Serial.println("Encendido");
    myservo.write(100); //
    delay(1693);
  }
  else {
  //estado = LOW;
  //Serial.println("Apagado");
  }

  //myservo.write(90); //Valor del servo para estar quieto.
  //delay(3000);
  //myservo.write(100); //
  //delay(1625);
  //myservo.write(90); //Valor del servo para estar quieto.
  //delay(1500);
  //myservo.write(0); //
  //delay(1500);
}   