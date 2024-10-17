#include <BluetoothSerial.h>
#include <ESP32Servo.h>

BluetoothSerial SerialBT;
Servo servoCaderaD;
Servo servoRodillaD;
Servo servoPieD;
Servo servoCaderaI;
Servo servoRodillaI;
Servo servoPieI;

int pinServoCaderaD = 12;
int pinServoRodillaD = 13;
int pinServoPieD = 14;
int pinServoCaderaI = 25;
int pinServoRodillaI = 26;
int pinServoPieI = 27;

int delayTime = 500;  // Tiempo de espera entre movimientos

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Servo_Control");  // Nombre del dispositivo Bluetooth

  // Conectar los servos a los pines correspondientes
  servoCaderaD.attach(pinServoCaderaD);
  servoRodillaD.attach(pinServoRodillaD);
  servoPieD.attach(pinServoPieD);
  servoCaderaI.attach(pinServoCaderaI);
  servoRodillaI.attach(pinServoRodillaI);
  servoPieI.attach(pinServoPieI);

  // Posición inicial: todos los servos en posición neutral
  setPosition(90, 90, 90, 90, 90, 90);
  
  Serial.println("El dispositivo Bluetooth está listo para emparejarse.");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();

    if (command == 'W') {  // Si el comando es caminar
      walkSequence();
    }
  }
}

// Función para ajustar los ángulos de todos los servos
void setPosition(int caderaD, int rodillaD, int pieD, int caderaI, int rodillaI, int pieI) {
  servoCaderaD.write(caderaD);
  delay(delayTime);  // Pausa entre cada movimiento
  servoRodillaD.write(rodillaD);
  delay(delayTime);
  servoPieD.write(pieD);
  delay(delayTime);
  
  servoCaderaI.write(caderaI);
  delay(delayTime);
  servoRodillaI.write(rodillaI);
  delay(delayTime);
  servoPieI.write(pieI);
  delay(delayTime);
}

// Secuencia de caminar hacia adelante
void walkSequence() {
  // Paso 1: Levantar la pierna derecha hacia adelante
  setPosition(60, 90, 90, 90, 70, 90);  // Cadera derecha hacia adelante, rodilla derecha ligeramente flexionada

  // Paso 2: Mover la pierna derecha hacia el frente
  setPosition(90, 60, 90, 90, 70, 90);  // Rodilla derecha más flexionada, cadera en posición neutral

  // Paso 3: Aterrizar la pierna derecha y levantar la izquierda
  setPosition(90, 90, 90, 60, 90, 90);  // Cadera izquierda hacia adelante, rodilla izquierda ligeramente flexionada

  // Paso 4: Mover la pierna izquierda hacia el frente
  setPosition(90, 90, 90, 90, 60, 90);  // Rodilla izquierda más flexionada, cadera en posición neutral

  // Paso 5: Aterrizar la pierna izquierda
  setPosition(90, 90, 90, 90, 90, 90);  // Volver a posición neutral
}
