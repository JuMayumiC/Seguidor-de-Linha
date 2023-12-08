# Algoritmo de Montagem do Robô de Sumô

## Materiais Necessários
- 1 placa Arduino Uno R3
- 1 placa protoboard
- 1 Cabo USB
- 1 sensor de distância ultrassônico HC-SR04
- 2 módulos sensor de obstáculo infravermelho IR
- 1 ponte H L298n (driver)
- 1 kit chassi 2WD robô para Arduino
- 16 jumpers macho-fêmea
- 4 jumpers macho-macho
- 1 fonte de alimentação (pilhas ou bateria 9V)
- 1 notebook
- Software mBlock ou Arduino IDE

## Procedimento de Montagem
1. Fixar a ponte H, os sensores de obstáculo IR e o sensor ultrassônico sobre o chassi 2WD.
2. Conectar os fios dos motores nos bornes da ponte H.
3. Posicionar a protoboard sobre o chassi e conectar os bornes da ponte H nela.
4. Posicionar a placa Arduino sobre a protoboard e conectá-la aos bornes da ponte H na protoboard.
5. Conectar os pinos da ponte H às portas digitais do Arduino usando jumpers macho-fêmea.
6. Conectar os pinos GND e VCC dos sensores na protoboard.
7. Interligar os pinos de dados dos sensores de obstáculos infravermelho ao Arduino.
8. Conectar os pinos de dados do sensor ultrassônico ao Arduino.
9. Conectar a fonte de energia à ponte H, respeitando a polaridade correta.

## Programação
1. Instalar as bibliotecas necessárias para controlar os sensores e a ponte H.
2. Desenvolver o código para ler os sensores e controlar os motores baseado nas estratégias desejadas.

## Considerações Finais
- Testar cada componente individualmente após a montagem para garantir seu funcionamento.
- Utilizar o código para verificar se os sensores e motores respondem corretamente aos comandos.
