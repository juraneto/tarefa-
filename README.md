# Temporizador_Tinkercard

Este é um projeto que usa o Tinkercad para simular um temporizador com um display LCD. O código é escrito em C++ e usa a biblioteca LiquidCrystal.h e Wire.h. O projeto tem como objetivo mostrar o nome, sobrenome e matrícula do aluno(a) em um display de LCD de 16x2 colunas, com um temporizador que faz o texto se mover da direita para a esquerda no display.

## Como funciona

O temporizador começa a contar quando o botão é pressionado pela primeira vez. Quando o botão é pressionado novamente, o temporizador para de contar. O display LCD mostra uma mensagem de boas-vindas ao aluno(a), seguido do nome e sobrenome do aluno(a) e, por fim, sua matrícula. A mensagem no display é atualizada a cada segundo.

![temporizador](https://user-images.githubusercontent.com/96122153/235533496-5a00dc00-af6c-4c9c-8a0e-3c520615a2bc.gif)

## Componentes necessários

* Arduino Uno
* Breadboard
* Display LCD 16x2
* Botão
* Jumpers

## Como montar

* Conecte o pino RS do display LCD ao pino 8 do Arduino.
* Conecte o pino EN do display LCD ao pino 9 do Arduino.
* Conecte os pinos DB4, DB5, DB6 e DB7 do display LCD aos pinos 4, 5, 6 e 7 do Arduino, respectivamente.
* Conecte o pino de um lado do botão ao pino 2 do Arduino.
* Conecte o outro pino do botão ao terra (GND) do Arduino.

## Como executar

* Abra o [Tinkercad](https://www.tinkercad.com) e crie um novo circuito.
* Adicione os componentes necessários e faça as conexões de acordo com as instruções acima.
* Copie o código fornecido acima e cole-o no editor de código do Tinkercad.
* Pressione o botão "Start Simulation" para executar o código.

### Observações

* Certifique-se de selecionar o modelo correto do Arduino na simulação do Tinkercad.
* Verifique se as conexões estão corretas antes de iniciar a simulação.
* Este projeto pode ser modificado para atender às suas necessidades, como alterar a mensagem exibida no display ou a funcionalidade do botão.
