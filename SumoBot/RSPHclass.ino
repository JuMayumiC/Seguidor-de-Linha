/********************************************************/
/* Aula 38 - Robô Sumô */
/* Programação: Abaixo um exemplo de código que */
/* controlará o robô a disputa de sumô. É utilizado dois*/
/* módulos sensores de obstáculo IR para detectar a */
/* borda da arena, um módulo sensor ultrassônico para */
/* detectar o adversário e a ponte H para fazer o */
/* controle dos motores DC. */
/* Links para obtenção das bibliotecas */
/* */
/* http://librarymanager/All#minimalist#Ultrasonic */
/* https://github.com/ErickSimoes/Ultrasonic */
/* Biblioteca Ultrasonic by Erick Simões */
/* */
/* http://librarymanager/All#L298N#EASY */
/* https://github.com/AndreaLombardo/L298N */
/* Biblioteca da ponte H by Andrea Lombardo. */
/********************************************************/

/* Inclui as bibliotecas para controle da ponte H sensor*/
/* ultrassônico. */
#include <L298NX2.h>
#include <Ultrasonic.h>
#define ENA 10 // ENA precisa estar em uma porta PWM
#define IN1 9
#define IN2 8
#define IN3 6
#define IN4 7
#define ENB 5 // ENB precisa estar em uma porta PWM
/* Definimos os pinos do sensor ultrassônico. */
#define Pino_Trig 12
#define Pino_Echo 11
/* Define os pinos para os sensores IR */
#define Pino_Sensor_Dianteiro 3
#define Pino_Sensor_Traseiro 2
/* Criamos um objeto de controle dos motores. */
L298NX2 motores(ENA, IN1, IN2, ENB, IN3, IN4);
/* Criamos um objeto de controle para o ultrassônico. */
Ultrasonic ultrasonic(Pino_Trig, Pino_Echo);
/* Declaração de variáveis: */
/* Variável "distancia" armazenará a distância lida */
/* pelo Sensor Ultrassônico; */
/* Variáveis "IR_Dianteiro" e "IR_Traseiro" armazenarão */
/* a leitura dos Sensores Infravermelho; */
/* Variáveis "Vel_Ataque" e "Vel_Padrao" definirão as */
/* velocidades de movimento do robô; */
/* Variável "tempo" define o tempo de delay nas funções.*/
int distancia, IR_Dianteiro, IR_Traseiro, tempo;
int Vel_Ataque = 255, Vel_Padrao = 120;
void setup() {
/* Configura os pinos dos sensores IR como entradas */
pinMode(Pino_Sensor_Dianteiro, INPUT);
pinMode(Pino_Sensor_Traseiro, INPUT);
delay(3000); /* Aguarda 3 segundos para iniciar */
}
void loop() {
/* Chama a função de leitura dos sensores. */
ler_sensores();
/* Se detectar o adversário a frente, faz */
/* o robô atacar até detectar a linha. */
if (distancia < 30 && IR_Dianteiro == 0) {
/* Chama a função de correção da posição */
/* para direcionar o ataque. */
correcao(200);
while (IR_Dianteiro == 0) {
ataque();
ler_sensores();
}
}
/* Chama a função de leitura dos sensores. */
ler_sensores();
/* Se detectar a linha na traseira, faz o */
/* robô ir para frente por meio segundo. */
if (IR_Traseiro == 1) {
frente(500);
}
/* Chama a função de leitura dos sensores. */
ler_sensores();
/* Se detectar a linha na dianteira, faz o */
/* robô ir para trás por um segundo. */
if (IR_Dianteiro == 1) {
re(1000);
}
/* Chama a função de giro em busca do */
/* adversário. */
gira();
}
/* Funções de controle do robô */
/* Função que move o robô para frente. */
void frente(int tempo) {
/* Define a velocidade dos motores */
motores.setSpeed(Vel_Padrao);
/* Robô move para frente */
motores.forward();
delay(tempo);
/* Para o robô */
motores.stop();
}
/* Função que move o robô para trás. */
void re(int tempo) {
motores.setSpeed(Vel_Padrao);
/* Robô move para trás */
motores.backward();
delay(tempo);
motores.stop();
}
/* Função que gira o robô em busca do */
/* adversário. */
void gira() {
motores.setSpeed(Vel_Padrao);
motores.forwardA();
motores.backwardB();
}
/* Função que posiciona o robô para o ataque */
void correcao(int tempo) {
motores.setSpeed(Vel_Padrao);
motores.forwardB();
motores.backwardA();
delay(tempo);
motores.stop();
}
/* Função que faz o ataque do robô. */
void ataque() {
motores.setSpeed(Vel_Ataque);
motores.forward();
}
/* Função que realiza a leitura dos */
/* sensores. */
void ler_sensores() {
/* Leitura da distância. */
distancia = ultrasonic.read();
/* Leitura doS SensorES IR */
IR_Dianteiro = digitalRead(Pino_Sensor_Dianteiro);
IR_Traseiro = digitalRead(Pino_Sensor_Traseiro);
}