# Projeto: Sinal de Ré com Sensor de Distância, LED RGB e Buzzer

## Descrição

Este projeto simula um sinal de ré para veículos utilizando um sensor de distância ultrassônico, um LED RGB e um buzzer. Quando o carro se aproxima de um obstáculo, o sistema mede a distância e responde com sinais visuais e sonoros para alertar o motorista.

## Componentes

- Arduino Uno
- Sensor de distância ultrassônico (HC-SR04)
- LED RGB
- Buzzer
- Resistores (220Ω para os LEDs)
- Jumpers

## Conexões

| Componente      | Pino Arduino       |
| --------------- | ------------------ |
| Trig do Sensor  | 7                  |
| Echo do Sensor  | 6                  |
| LED Vermelho    | 5                  |
| LED Verde       | 4                  |
| LED Azul        | 3                  |
| Buzzer          | A0                 |

## Funcionamento

1. **Medição de Distância:** O sensor ultrassônico mede a distância do veículo ao obstáculo.
2. **Indicações Visuais e Sonoras:**
   - **Vermelho e Som Contínuo:** Quando a distância é menor ou igual a 10 cm, o LED fica vermelho e o buzzer emite um som contínuo, indicando proximidade extrema.
   - **Amarelo e Som Intermitente Rápido:** Quando a distância está entre 11 cm e 20 cm, o LED fica amarelo e o buzzer emite um som intermitente com intervalos de 0.1 segundo.
   - **Verde e Som Intermitente Lento:** Quando a distância é maior que 20 cm, o LED fica verde e o buzzer emite um som intermitente com intervalos de 0.5 segundo.

3. **Atualizações Frequentes:** As medições e ações são atualizadas a cada 100 ms, garantindo uma resposta rápida e precisa.

## Requisitos

- Arduino IDE
- Placa Arduino Uno
- Bibliotecas padrão da Arduino IDE

## Instalação

1. Conecte todos os componentes conforme as conexões descritas.
2. Abra a Arduino IDE e carregue o código fornecido.
3. Faça o upload do código para o Arduino.
4. Abra o monitor serial para ver as leituras de distância em tempo real.

## Contato:

Se você tiver alguma dúvida ou sugestão, sinta-se à vontade para abrir uma issue no repositório do GitHub ou enviar um e-mail para: 
[nathanfelipi2006@gmail.com].

---

Desenvolvido com ❤️ por [Nathan Felipi Almeida].

