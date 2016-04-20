//#include <SoftwareSerial.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include "pitches.h"
#define melodyPin 2

float smoothD[10];
float smoothedD = 0;
int smoothCount = 0;

const byte buff_len = 90;
char CRCbuffer[buff_len];
boolean pout = false;
boolean supermario = false;
boolean supermario1 = false;
unsigned long lastTime = 0;
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//
//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, 
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4, 
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  3,
  12, 12, 12, 12, 
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18,18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

// create pre-dfined strings to control flexible output formatting
String sp = " ";
String delim = ",";
String splat = "*";
String msg = ""; 



int pitch = 45;
int roll = 45;
int thrust = 30;
int seitenruder = 45;

int amswitchIn = 10;
int amswitch1 = 5;
int amswitch2 = 3;
int State = 0;
long pulse = 0;
SFE_BMP180 pressure;
double baseline; // baseline pressure

//int bluetoothTx = 10;
//int bluetoothRx = 11;


int CH;
int VAL1,VAL2,VAL3,VAL4;
int v [] = {0,0,0,0,0,0,0,0};
float a,P,average, lastA,d;
byte alt [3];
double aDIFF, aLASTDIFF;
int count = 0;
int i = 0;
//SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
    char strX[8];
  char strY[8];
 

void setup()
{ 

 pinMode(2, OUTPUT);

   
  //Setup usb serial connection to computer
  Serial.begin(9600);

  if (pressure.begin())
   // Serial.println("BMP180 init success");
   delay(100);
  else
  {

   // Serial.println("BMP180 init fail (disconnected?)\n\n");
    while(1); // Pause forever.
  }

  // Get the baseline pressure:
  
  baseline = getPressure();
//  Serial.print("baseline pressure: ");
//  Serial.print(baseline);
}  

void loop()
{ 

  
 
    
   timer(1000);
   if (d > 0.1){
   supermario = true;
    sing1();
   }
   else if (d <= 0.1 && d > -0.5){
     supermario = false;
     supermario1 = false;
   }
   else{
       supermario1 = true;
     sing2();
   }
      



}



