#include <Ultrasonic.h>
Ultrasonic ultra(12,13);
int distancia;
int vermelho = 5;
int verde = 6;
int azul = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop()
{
  distancia = ultra.read();
  if(distancia > 45)
  {
    digitalWrite(verde, 1);
    digitalWrite(azul, 0);
    digitalWrite(vermelho, 0);
    Serial.println(distancia);
    Serial.println("Verde");
  }
  else if(distancia >= 15 && distancia <= 45)
  {
    digitalWrite(verde, 1);
    digitalWrite(azul, 0);
    digitalWrite(vermelho, 1);
    Serial.println(distancia);
    Serial.println("Amarelo");
  }
  else if(distancia < 15)
  {
    digitalWrite(verde, 0);
    digitalWrite(azul, 0);
    digitalWrite(vermelho, 1);
    Serial.println(distancia);
    Serial.println("Vermelho");
  }

  
  delay(1500);
}
