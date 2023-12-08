#define Pino_Trig 12
#define Pino_Echo 11

void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
  pinMode(Pino_Trig, OUTPUT);
  pinMode(Pino_Echo, INPUT);
}

void loop() {
  long duracao, distancia;
  
  digitalWrite(Pino_Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Pino_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Pino_Trig, LOW);
  
  duracao = pulseIn(Pino_Echo, HIGH);
  distancia = (duracao / 2) / 29.1; // Converte para centímetros
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  delay(500); // Aguarda meio segundo antes da próxima leitura
}
