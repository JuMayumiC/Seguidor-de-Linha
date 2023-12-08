#define ENA 10
#define IN1 9
#define IN2 8
#define IN3 6
#define IN4 7
#define ENB 5

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Movimento do Motor A (ENA)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // Velocidade do motor (de 0 a 255)
  
  // Movimento do Motor B (ENB)
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); // Velocidade do motor (de 0 a 255)
  
  delay(2000); // Gira os motores por 2 segundos
  
  // Para os motores
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, LOW);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, LOW);
  
  delay(2000); // Aguarda 2 segundos antes do próximo teste
}
