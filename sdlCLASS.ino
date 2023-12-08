/********************************************************/
/* Aula 33 - Robô Seguidor de Linha */
/* Programação: Abaixo um exemplo de código que */
/* controlará o robô para seguir uma linha. É utilizado */
/* dois módulos sensores de obstáculo IR para detectar */
/* a linha e a ponte H L298n para fazer o controle dos */
/* motores DC
. */
/* Links para obtenção da biblioteca de controle da */
/* ponte H by Andrea Lombardo. */
/* http://librarymanager/All#L298N#EASY */
/* https://github.com/AndreaLombardo/L298N */
/********************************************************/
/*=====ATENÇÃO!======== ATENÇÃO! =========ATENÇÃO!======*/
/* Antes de compilar/carregar o código, você deverá */
/* selecionar qual a cor da linha que o robô deverá */
/* seguir, para isto, descomente (removendo o //) de */
/* uma das duas linhas abaixo. */
//#define CorLinha 1 /* Linha PRETA */
#define CorLinha 0 /* Linha BRANCA */
/*=====ATENÇÃO!======== ATENÇÃO! =========ATENÇÃO!======*/
/* Configura o modo da detecção da linha de acordo com a*/
/* cor escolhida acima. */
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
/* Define os pinos 2 e 3 para os sensores IR */
#define Pino_Sensor_Direita 3
#define Pino_Sensor_Esquerda 2
/* Variáveis para armazenar os dados dos sensores. */
int Sensor_Direita, Sensor_Esquerda;

void setup() {
Serial.begin(9600);
pinMode(Pino_Sensor_Direita, INPUT);
pinMode(Pino_Sensor_Esquerda, INPUT);
/* Inicia com os motores parados. */
motores.stop();
}
void loop() {
/* Sensores realizam a leitura */
Sensor_Direita = digitalRead(Pino_Sensor_Direita);
Sensor_Esquerda = digitalRead(Pino_Sensor_Esquerda);
/* Nenhum sensor detectou a linha */
if (Sensor_Esquerda == naodetectou && Sensor_Direita == naodetectou)
{
motores.setSpeed(255); /* Define a velocidade dos motores */
motores.forward(); /* Robô move para frente */
Serial.println("Nenhum sensor detectou a linha.");
}
/* Sensor da direita detectou a linha */
if (Sensor_Esquerda == naodetectou && Sensor_Direita == detectou) {
motores.setSpeed(150); /* Define a velocidade dos motores */
motores.forwardB(); /* Robô vira à direita */
motores.backwardA();
Serial.println("Somente o sensor da Direita detectou a linha.");
}
/* Sensor da esquerda detectou a linha */
if (Sensor_Esquerda == detectou && Sensor_Direita == naodetectou) {
motores.setSpeed(150); /* Define a velocidade dos motores */
motores.forwardA(); /* Robô vira à esquerda */
motores.backwardB();
Serial.println("Somente o sensor da Esquerda detectou a linha.");
}
/* Os dois sensores detectaram a linha */
if (Sensor_Esquerda == detectou && Sensor_Direita == detectou) {
motores.stop(); /* Robô permanece parado */
Serial.println("Ambos sensores detectaram a linha.");
}
}