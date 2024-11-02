#### Link do projeto no Tinkercad
https://www.tinkercad.com/things/5DPjNpYH1iN/editel?returnTo=%2Fdashboard

---

##### Imagem da montagem física do projeto

![Montagem física do semáforo offline. (buzzer desconetado para maior conforto dos colegas)](<Programação/Semáforo offline montagem física protoboard com LEDs conectados.jpg>)

##### Vídeo demonstrado ao solução básica requerida

<video controls src="Programação/Semáforo offline básico como pede a ponderada.mp4" title="Title"></video>

##### Vídeo demonstrando o projeto indo além
<video controls src="Programação/Semáforo offline indo além.mp4" title="Title"></video>

Para ir além, afora a adição da funcionalidade de aumento de segurança através do countdown anunciado pelp buzzer, consertei a lógica do semáforo, saltando do farol vermelho direto para o verde, sem que passe antes pelo amarelo.

---

## Relato da Montagem e Conexões do Semáforo

Para a montagem do semáforo, utilizei uma **protoboard** para organizar os componentes, incluindo três LEDs (vermelho, amarelo e verde) que representam as fases do semáforo para veículos, um buzzer para sinal sonoro e resistores para proteção dos LEDs. Cada LED foi conectado a um pino digital do Arduino para controle individual, e o buzzer foi conectado para emitir um aviso sonoro nos últimos segundos da fase verde, conforme a lógica de trânsito programada.

### Passos da Montagem
1. **Conexão dos LEDs**:
   - Conectei o **LED vermelho** ao pino digital 8 do Arduino, o **LED amarelo** ao pino 9, e o **LED verde** ao pino 10.
   - Em série com cada LED, adicionei um **resistor** para limitar a corrente, evitando a queima dos LEDs.
   - O terminal negativo de cada LED foi conectado à linha de GND da protoboard, que está conectada ao GND do Arduino.

2. **Conexão do Buzzer**:
   - O **buzzer** foi conectado ao pino 12 do Arduino, com o terminal negativo conectado ao GND.
   - Esse buzzer emite bips nos últimos 2 segundos da fase verde, indicando a contagem regressiva para a troca.

Essa montagem foi feita de forma organizada na protoboard, facilitando o entendimento e teste do circuito.

---

### Especificações dos Componentes Utilizados

| Componente       | Função                                                 |
|------------------|--------------------------------------------------------|
| LED Vermelho     | Indica a fase de parada (vermelho)                     |
| LED Amarelo      | Indica a fase de atenção (amarelo)                     |
| LED Verde        | Indica a fase de avanço (verde)                        |
| Resistor         | Limita a corrente dos LEDs                             |
| Buzzer     | Emite som para contagem regressiva na fase verde       |
| Protoboard       | Facilita a montagem dos componentes sem solda          |
| Arduino Uno      | Controla as fases do semáforo e o buzzer               |

---

Essa montagem e programação permitem simular o comportamento de um semáforo com um aviso sonoro nos últimos segundos do verde, tornando o sistema mais próximo de semáforos reais e simulado um aumento da segurança de sinalização para veículos e pedestres.

---

### Código do Projeto

``` C++

int ledVermelho = 8;
int ledAmarelo = 9;
int ledVerde = 10;
int buzzerPin = 12;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Farol vermelho
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(buzzerPin, LOW);  // Buzzer desligado
  delay(6000); // 6 segundos no vermelho

  // Transição farol do Vermelho -> Amarelo
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(buzzerPin, LOW);  // Buzzer desligado
  delay(2000); // 2 segundos no amarelo

  // Farol verde 
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, HIGH);

  // Primeiros 2 segundos do verde, sem aviso do buzzer
  delay(2000);

  // Últimos 2 segundos do verde, com aviso do buzzer
  for (int i = 0; i < 2; i++) {
    digitalWrite(buzzerPin, HIGH);  // Liga o buzzer
    delay(250);                     // Buzzer ligado por 0.25 segundos
    digitalWrite(buzzerPin, LOW);   // Desliga o buzzer
    delay(750);                     // Buzzer desligado pelo restante do segundo
  }

  // Transição do farol verde -> amarelo
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(buzzerPin, LOW);  // Buzzer desligado
  delay(2000); // 2 segundos no amarelo
}

```

---

### Avaliador: Nicolas Ramon
| Critério                                                                                                 | Contempla (Pontos) | Contempla Parcialmente (Pontos) | Não Contempla (Pontos) | Observações do Avaliador |
|---------------------------------------------------------------------------------------------------------|--------------------|----------------------------------|--------------------------|---------------------------|
| Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores                | Até 3              | Até 1,5                            | 0                        |  Fernando montou de forma adequada os cabos, as cores são facilmente distinguiveis e bem organizados, os resistores foram corretamente utilizados. 3,0                        |
| Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo                  | Até 3              | Até 1,5                          | 0                        |  As luzes acendem corretamente. 3,0                         |
| Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) | Até 3              | Até 1,5                          | 0                        |  Código bem estruturado, porém faltam comentários na parte inicial. 2,5                         |
| Extra: Implementou um componente de liga/desliga no semáforo e/ou usou ponteiros no código | Até 1              |  Até 0,5                         | 0                        |  Ficou legal o alerta utilizando o buzzer para quando o semáforo está prestes a fechar. 1,0                         |
|  |                                                             |  | |**Pontuação Total 9,5**|

---

### Avaliador: Kethlen Martins 
| Critério                                                                                                 | Contempla (Pontos) | Contempla Parcialmente (Pontos) | Não Contempla (Pontos) | Observações do Avaliador |
|---------------------------------------------------------------------------------------------------------|--------------------|----------------------------------|--------------------------|---------------------------|
| Montagem física com cores corretas, boa disposição dos fios e uso adequado de resistores                | Até 3              | Até 1,5                            | 0                        |  O circuito foi montado corretamente e as cores utilizadas no semáforo seguem um padrão fácil de entender o que está ligado à protoboard e o que está ligado ao Arduino. 3,o                       |
| Temporização adequada conforme tempos medidos com auxílio de algum instrumento externo                  | Até 3              | Até 1,5                          | 0                        |  As luzes acendem corretamente (vermelho, amarelo e verde) na solução básica do exercício, mas na solução indo além, fazendo uso do buzzer, a sequência do loop não está correta no momento da demonstração (após o vermelho, salta direto para o verde, sem antes acender o amarelo). 2,0.                         |
| Código implementa corretamente as fases do semáforo e estrutura do código (variáveis representativas e comentários) | Até 3              | Até 1,5                          | 0                        |  O código está bem estruturado e aparentemente funciona corretamente. Faltou manter o padrão dos comentários na definição das variáveis. 2,5.                       |
| Extra: Implementou um componente de liga/desliga no semáforo e/ou usou ponteiros no código | Até 1              |  Até 0,5                         | 0                        |  O buzzer utilizado no montagem permitiu o liga/desliga do semáforo. 1,0                         |
|  |                                                             |  | |**Pontuação Total 8,5**|