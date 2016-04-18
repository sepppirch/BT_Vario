//#include <SoftwareSerial.h>
#include <SFE_BMP180.h>
#include <Wire.h>


const byte buff_len = 90;
char CRCbuffer[buff_len];

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
  
  //Setup Bluetooth serial connection to android
 // bluetooth.begin(115200);
//  Serial.print("$$$");
  //delay(100);
 // Serial.println("U,9600,N");
 // bluetooth.begin(9600);
  
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

  
    P = getPressure();
    a = pressure.altitude(P,baseline);   ////meter
    
   timer(1000);
 /*   
      if(d > 1.3){
      d=0;
      beep(2,3520,90);

     
      }
      else if(d > 0.9){
      d=0;
      beep(2,3136,70);

      }
      else if(d > 0.6){
      d=0;
      beep(2,2793,70);
      }
      else if(d > 0.4){
      d=0;
   
      beep(2,2637,50);
      }
      else if(d > 0.2){
      d=0;
      beep(2,2349,30);
      }else if(d < -2){
      d=0;
      beep(2,2093,1405);
       
      }
 */


}

