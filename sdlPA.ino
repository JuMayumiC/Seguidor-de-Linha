#define CorLinha 1 // 1 = Preto, 0 = Branco

#if CorLinha == 1
boolean detectou = 1;
boolean naodetectou = 0;
#else
boolean detectou = 0;
boolean naodetectou = 1;
#endif
/* Inclui a Biblioteca para controle da ponte H. */
#include <L298NX2.h>
#define ENA 10 // ENA precisa estar em uma porta PWM
#define IN1 9
#define IN2 8
#define IN3 6
#define IN4 7
#define ENB 5 // ENB precisa estar em uma porta PWM
/* Criamos um objeto de controle dos motores. */
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);

/* Define os pinos para os sensores IR como entrada analógica */
#define Pino_Sensor_Direita A1
#define Pino_Sensor_Esquerda A0

/* Variáveis para armazenar os valores analógicos dos sensores */
int Valor_Sensor_Direita;
int Valor_Sensor_Esquerda;
int Limiar = 500; // Limiar de decisão entre linha e fundo

void setup() {
  Serial.begin(9600);
  pinMode(Pino_Sensor_Direita, INPUT);
  pinMode(Pino_Sensor_Esquerda, INPUT);
  motores.stop(); // Inicia com os motores parados
}

void loop() {
  /* Sensores realizam a leitura analógica */
  Valor_Sensor_Direita = analogRead(Pino_Sensor_Direita);
  Valor_Sensor_Esquerda = analogRead(Pino_Sensor_Esquerda);
  
  /* Lógica baseada na leitura analógica dos sensores */
  if (Valor_Sensor_Esquerda > Limiar && Valor_Sensor_Direita > Limiar) {
    // Ambos os sensores sobre a linha
    motores.stop();
    Serial.println("Ambos sensores detectaram a linha.");
  } else if (Valor_Sensor_Esquerda > Limiar) {
    // Apenas sensor esquerdo sobre a linha
    motores.setSpeed(150);
    motores.forwardA(); // Vira à esquerda
    motores.backwardB();
    Serial.println("Somente o sensor da Esquerda detectou a linha.");
  } else if (Valor_Sensor_Direita > Limiar) {
    // Apenas sensor direito sobre a linha
    motores.setSpeed(150);
    motores.forwardB(); // Vira à direita
    motores.backwardA();
    Serial.println("Somente o sensor da Direita detectou a linha.");
  } else {
    // Nenhum sensor detectou a linha
    motores.setSpeed(255);
    motores.forward();
    Serial.println("Nenhum sensor detectou a linha.");
  }
}
