
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                     Dispencer de suco
//
//   build 129/10/2020 by Raul 
//  v1.0
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Ard uino.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONFIGURACAO

#define RELE1     2
#define RELE2     3
#define LED       4
#define SENSOR    5
#define CHAVE     6

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//VARIAVEIS PUBLICAS
int inicio = 0;
long volume = 50;
 
int cont = 0;
bool enche_copo(long intervalo);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CONFIGURAÇÃO DE PINOS
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
pinMode(RELE1, OUTPUT);
pinMode(RELE2,OUTPUT);
pinMode(LED, OUTPUT);
pinMode(SENSOR, INPUT);
pinMode(CHAVE, INPUT_PULLUP);

Serial.begin(9600);

Serial.println("Dispenser suco");
digitalWrite(LED, HIGH);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {

  if((digitalRead(CHAVE) == 0) && (digitalRead(SENSOR)==1)) {
    Serial.println("Iniciando");
    digitalWrite(LED, LOW);
    inicio = 1;
    cont = 0;
    delay(1000);
   
    while ((digitalRead(SENSOR)==0) && (cont <= volume)){
      digitalWrite(LED, HIGH); 
      digitalWrite(RELE1, HIGH);
      delay(500);
      cont ++;
      Serial.println(cont);
    }  
    Serial.println("terminado"); 
    digitalWrite(RELE1, LOW);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);  
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH); 
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    digitalWrite(LED, HIGH);  
  }


delay(100);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 bool enche_copo(long volume){
  static int ledState = LOW;  
  static unsigned long previousMillis = 0;
  static bool rodando = false;
  unsigned long currentMillis = millis();



  if((volume > 0) && (rodando == 0)){
    rodando = true;
    digitalWrite(RELE1, HIGH);
    Serial.println("rodando");
  }

  digitalWrite(LED, ledState);

  if(rodando == true ){
    Serial.println("começando");
    


 }
  
}

*/
 