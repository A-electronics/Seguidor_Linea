int PWM1 = 10;
int INA1 = 7;
int INA2 = 8;

int PWM2 = 9;
int INB1 = 2;
int INB2 = 4;

#define btn1 2
#define btn2 4

int vel = 220;

int sensor4 = 0;  //pines analogicos almacenados en una variable
int sensor3 = 1;  //pines analogicos almacenados en una variable
int sensor2 = 2;  //pines analogicos almacenados en una variable
int sensor1 = 3;  //pines analogicos almacenados en una variable

int valorSensor4 = 0;
int valorSensor3 = 0;
int valorSensor2 = 0;
int valorSensor1 = 0;

int aux1 = 1;

void setup() {
  Serial.begin(9600);
  pinMode(PWM1, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(INB2, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  digitalWrite(PWM1, LOW);  //Deshabilitar los motores
  digitalWrite(PWM2, LOW);  //Deshabilitar los motores
}

void loop() {
  //Mapeo de Sensores
  valorSensor1 = map(analogRead(sensor1), 0, 1023, 0, 255);
  valorSensor2 = map(analogRead(sensor2), 0, 1023, 0, 255);
  valorSensor3 = map(analogRead(sensor3), 0, 1023, 0, 255);
  valorSensor4 = map(analogRead(sensor4), 0, 1023, 0, 255);

  Serial.print("Sensor 1 =");
  Serial.println(valorSensor1);
  Serial.print("Sensor 2 =");
  Serial.println(valorSensor2);
  Serial.print("Sensor 3 =");
  Serial.println(valorSensor3);
  Serial.print("Sensor 4 =");
  Serial.println(valorSensor4);
  Serial.println("-------------------------------------------------------");
  delay(200);

  // if (digitalRead(btn1) == LOW){
  //   aux1 = 0;
  // }

  // while (aux1 == 0) {
  if (valorSensor2 >= 20 && valorSensor2 <= 255 || valorSensor3 >= 20 && valorSensor3 <= 255) {
    //Recto
    analogWrite(PWM1, vel);
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    analogWrite(PWM2, vel);
    digitalWrite(INB1, LOW);
    digitalWrite(INB2, HIGH);
  }

  if (valorSensor4 >= 20 && valorSensor4 <= 255) {
    //Derecha
    analogWrite(PWM1, vel);
    digitalWrite(INA1, HIGH);
    digitalWrite(INA2, LOW);
    analogWrite(PWM2, vel);
    digitalWrite(INB1, LOW);
    digitalWrite(INB2, HIGH);
  }

  if (valorSensor1 >= 20 && valorSensor1 <= 255) {
    //Izquierda
    analogWrite(PWM1, vel);
    digitalWrite(INA1, LOW);
    digitalWrite(INA2, HIGH);

    analogWrite(PWM2, vel);
    digitalWrite(INB1, HIGH);
    digitalWrite(INB2, LOW);
  }

  if (valorSensor1 < 9 && valorSensor2 < 9 && valorSensor3 < 9 && valorSensor4 < 9) {
    while (valorSensor4 < 9) {
      //Derecha
      analogWrite(PWM1, vel);
      digitalWrite(INA1, HIGH);
      digitalWrite(INA2, LOW);
      analogWrite(PWM2, vel);
      digitalWrite(INB1, LOW);
      digitalWrite(INB2, HIGH);
      valorSensor4 = map(analogRead(sensor4), 0, 1023, 0, 255);
    }
  }
  // }
}
