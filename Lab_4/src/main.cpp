//***************************************************************************************************************
// Universidad del Valle de Guatemala 
// BE3015 - Electrónica Digital 2
// Jeremy Mejía 
// Laboratorio #4
// Arduino
// Carné: 19846
//***************************************************************************************************************

//***************************************************************************************************************
// Librerías
//***************************************************************************************************************

#include <Arduino.h>
#include <LiquidCrystal.h>

//***************************************************************************************************************
// Definición de Pines
//***************************************************************************************************************

//Definición de entradas
#define BtnIn 13 //Botón Incrementar
#define BtnDe 12 //Botón Decrementar
#define Pot1 14 //Potenciómetro 1
#define Pot2 27 //Potenciómetro 2

//Definición de pines de salidas LCD
#define RS 2
#define E 16
#define D4 21
#define D5 3
#define D6 1
#define D7 22



//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************
void Incremento (void);
void Decremento (void);
void Antirrebote(void);

//***************************************************************************************************************
// Variabeles globales 
//***************************************************************************************************************
int contador = 0;
LiquidCrystal LCD(RS, E, D4, D5, D6, D7);
uint8_t decenas, unidades, decimal; 
uint8_t decenas1, unidades1, decimal1; 
int adcRaw;
float voltaje; 
float voltaje1; 
int num;
//***************************************************************************************************************
// ISR (Interrupciones)
//***************************************************************************************************************
void IRAM_ATTR BtnIncrementar(){
  contador = 1;
}

//***************************************************************************************************************
// Configuración
//***************************************************************************************************************


void setup() {
  //Serial.begin(115200);
  LCD.begin(16, 2);
  void Incremento();

  pinMode(BtnIn, PULLUP);
  pinMode(BtnDe, PULLUP);
  
}


//***************************************************************************************************************
// Loop Principal
//***************************************************************************************************************

void loop() {

  voltaje = analogReadMilliVolts(Pot1) / 10.0;
  int temp = voltaje;
  decenas = temp / 100.0;
  temp = temp - decenas *100.0;
  unidades = temp / 10.0; 
  temp = temp - unidades *10.0;
  decimal = temp; 

  LCD.clear();
  LCD.print("Pot1: ");
  LCD.print("Pot2: ");
  LCD.print("CPU:");
  LCD.setCursor(0, 1);
  LCD.print(decenas);
  LCD.print(".");
  LCD.print(unidades);
  LCD.print(decimal);
  LCD.print("V");
  delay(250);
  
  voltaje1 = analogReadMilliVolts(Pot2) / 10.0;
  int temp1 = voltaje1;
  decenas1 = temp1 / 100.0;
  temp1 = temp1- decenas1 *100.0;
  unidades1 = temp1 / 10.0; 
  temp1 = temp1 - unidades1 *10.0;
  decimal1 = temp1; 
  
  LCD.setCursor(6, 1);
  LCD.print(decenas1);
  LCD.print(".");
  LCD.print(unidades1);
  LCD.print(decimal1);
  LCD.print("V");
  delay(250);

  if (digitalRead(BtnIn) == 0){ //BtbIn está presionado
    Incremento();
  }

  
}
//***************************************************************************************************************
// Función Antirrebote
//***************************************************************************************************************

void Antirrebote(){
  if (contador == 1 && BtnIn == 0){
    delay(150);
    contador = 0; 
  }

  if (contador == 1 && BtnDe == 0){
    delay(150);
    contador = 0; 
  }

}

//***************************************************************************************************************
// Función Contador
//***************************************************************************************************************

void Incremento (void){

  if (digitalRead(BtnIn) == 0 && contador == 0){ //BtbIn está presionado
    LCD.setCursor(12, 1);
    LCD.print("0");
    contador = contador + 1;
    delay(5000);
  }
  else if (digitalRead(BtnIn) == 0 && contador == 1){ //BtbIn está presionado
    LCD.setCursor(12, 1);
    LCD.print("1");
    contador = contador + 1;
    delay(5000);
    
  }
  else if (digitalRead(BtnIn) == 0 && contador == 2){ //BtbIn está presionado
    LCD.setCursor(12, 1);
    LCD.print("2");
    contador = contador + 1;
    delay(5000);
  }
  else if (digitalRead(BtnIn) == 0 && contador == 3){ //BtbIn está presionado
    LCD.setCursor(12, 1);
    LCD.print("3");
    contador = contador + 1;
    delay(5000);
    
  }

}