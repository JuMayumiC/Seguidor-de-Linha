#define Pino_Sensor_Dianteiro 3
#define Pino_Sensor_Traseiro 2

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(Pino_Sensor_Dianteiro, INPUT);
  pinMode(Pino_Sensor_Traseiro, INPUT);
}

void loop() {
  int valorSensorDianteiro = digitalRead(Pino_Sensor_Dianteiro);
  int valorSensorTraseiro = digitalRead(Pino_Sensor_Traseiro);
  
  if (valorSensorDianteiro == LOW) {
    Serial.println("Obstáculo detectado na frente!");
  } else {
    Serial.println("Nenhum obstáculo à frente.");
  }
  
  if (valorSensorTraseiro == LOW) {
    Serial.println("Obstáculo detectado atrás!");
  } else {
    Serial.println("Nenhum obstáculo atrás.");
  }
  
  delay(500); // Aguarda meio segundo antes da próxima leitura
}
