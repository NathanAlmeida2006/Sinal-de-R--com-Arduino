#define TRIG_PIN 7        // Define o pino do Trig
#define ECHO_PIN 6        // Define o pino do Echo

#define VERMELHO_PIN 5    // Define o pino do LED vermelho
#define VERDE_PIN 4       // Define o pino do LED verde
#define AZUL_PIN 3        // Define o pino do LED azul
#define BUZZER_PIN A0     // Define o pino do Buzzer

const int DISTANCIA_VERMELHO = 10; // Distância máxima para LED vermelho
const int DISTANCIA_AMARELO = 20;  // Distância máxima para LED amarelo

unsigned long previousMillisVerde = 0;
unsigned long previousMillisAmarelo = 0;
const long intervalVerde = 500;   // Intervalo de 0.5 segundos para verde
const long intervalAmarelo = 100; // Intervalo de 0.1 segundo para amarelo

bool buzzerStateVerde = false;
bool buzzerStateAmarelo = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);  // Configura o pino do Trig como saída
  pinMode(ECHO_PIN, INPUT);   // Configura o pino do Echo como entrada
  pinMode(VERMELHO_PIN, OUTPUT);  // Configura o pino do LED vermelho como saída
  pinMode(VERDE_PIN, OUTPUT);     // Configura o pino do LED verde como saída
  pinMode(AZUL_PIN, OUTPUT);      // Configura o pino do LED azul como saída
  pinMode(BUZZER_PIN, OUTPUT);    // Configura o pino do Buzzer como saída
  Serial.begin(9600);             // Inicializa a comunicação serial para depuração
}

void loop() {
  long duracao = medirDuracaoPulso();
  long distancia = calcularDistancia(duracao);

  imprimirDistancia(distancia);
  definirCorLEDSom(distancia);

  delay(100); // Aguarda 100 ms antes de fazer a próxima leitura
}

// Função para medir a duração do pulso
long medirDuracaoPulso() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH);
}

// Função para calcular a distância em centímetros
long calcularDistancia(long duracao) {
  return duracao * 0.034 / 2;
}

// Função para imprimir a distância no monitor serial
void imprimirDistancia(long distancia) {
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");
}

// Função para definir a cor do LED RGB e som do buzzer com base na distância
void definirCorLEDSom(long distancia) {
  unsigned long currentMillis = millis();

  if (distancia <= DISTANCIA_VERMELHO) {
    setColor(255, 0, 0);  // Vermelho
    tone(BUZZER_PIN, 500); // Som contínuo

  } else if (distancia <= DISTANCIA_AMARELO) {
    setColor(255, 255, 0);  // Amarelo
    if (currentMillis - previousMillisAmarelo >= intervalAmarelo) {
      previousMillisAmarelo = currentMillis;
      buzzerStateAmarelo = !buzzerStateAmarelo;
      buzzerStateAmarelo ? tone(BUZZER_PIN, 500) : noTone(BUZZER_PIN);
    }
  } else {
    setColor(0, 255, 0);  // Verde
    if (currentMillis - previousMillisVerde >= intervalVerde) {
      previousMillisVerde = currentMillis;
      buzzerStateVerde = !buzzerStateVerde;
      buzzerStateVerde ? tone(BUZZER_PIN, 500) : noTone(BUZZER_PIN);
    }
  }
}

// Função para definir a cor do LED RGB
void setColor(int red, int green, int blue) {
  analogWrite(VERMELHO_PIN, red);
  analogWrite(VERDE_PIN, green);
  analogWrite(AZUL_PIN, blue);
}
