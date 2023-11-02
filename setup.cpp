const int rele1  = 4;
const int rele2  = 2;
const int rele3  = A0;
const int rele4  = A1;
 
const int pwmger = 3;
 
const int botao0 = 5;
const int botao1 = 6;
const int botao2 = 7;
const int botao3 = 8;
const int botao4 = 9;
const int buzzer = 12;
 
// Define o estado lógico dos botões
int start     = 0;
int fixastart = 0;
int jogador1  = 0;
int jogador2  = 0;
int jogador3  = 0;
int jogador4  = 0;
 
void setup() {
  Serial.begin(9600);
 
  pinMode(botao0, INPUT_PULLUP);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
 
  pinMode(buzzer, OUTPUT);
  pinMode(pwmger, OUTPUT);
 
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
 
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
  digitalWrite(rele3, HIGH);
  digitalWrite(rele4, HIGH);
}
 
void loop() {
  int start    = digitalRead(botao0);
  int jogador1 = digitalRead(botao1);
  int jogador2 = digitalRead(botao2);
  int jogador3 = digitalRead(botao3);
  int jogador4 = digitalRead(botao4);
 
  if (start == 1) {
    fixastart = !fixastart;
    digitalWrite(buzzer, HIGH);
    delay(4000);                   // Altera o tempo do buzzer para inicio da rodada
    digitalWrite(buzzer, LOW);
  }
 
  if (fixastart == 1) {
 
    if ((jogador1 == 0) && (jogador2 == 1) && (jogador3 == 1) && (jogador4 == 1)) {
      digitalWrite(rele1, LOW);
      analogWrite(pwmger, 100);
      delay(50);
      analogWrite(pwmger, 0);
      delay(1000);
      digitalWrite(rele1, HIGH);
      delay(500);
      fixastart = !fixastart;
    }
 
    if ((jogador1 == 1) && (jogador2 == 0) && (jogador3 == 1) && (jogador4 == 1)) {
      digitalWrite(rele2, LOW);
      analogWrite(pwmger, 100);
      delay(50);
      analogWrite(pwmger, 0);
      delay(1000);
      digitalWrite(rele2, HIGH);
      delay(500);
      fixastart = !fixastart;
    }
 
    if ((jogador1 == 1) && (jogador2 == 1) && (jogador3 == 0) && (jogador4 == 1)) {
      analogWrite(rele3, 0);
      analogWrite(pwmger, 100);
      delay(50);
      analogWrite(pwmger, 0);
      delay(1000);
      analogWrite(rele3, 255);
      delay(500);
      fixastart = !fixastart;
    }
 
    if ((jogador1 == 1) && (jogador2 == 1) && (jogador3 == 1) && (jogador4 == 0)) {
      analogWrite(rele4, 0);
      analogWrite(pwmger, 100);
      delay(50);
      analogWrite(pwmger, 0);
      delay(1000);
      analogWrite(rele4, 255);
      delay(500);
      fixastart = !fixastart;
    }
  }
}
