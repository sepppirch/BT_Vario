long previousMillis = 0;

boolean timer(int interval) {
  
  
 unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
 
 P = getPressure();
 a = pressure.altitude(P,baseline);   ////meter
 
 d = a - lastA;
 lastA = a;
/* 
 if (smoothCount < 3){
    smoothD[smoothCount] = d;
    smoothCount++;
  }
 else{
 float sum = 0;
 
   for (int i = 0; i < 3; i++){
       sum = sum + smoothD[i];
       }
       smoothedD = sum;
        smoothCount = 0;
        
        */
  float x = P + 0.01;
  float y = 20;
  String cmd = "$POV,P";    // a command name
  dtostrf(x,4,2,strX);      // format float value to string XX.X
  dtostrf(y,4,1,strY);      
  msg = cmd + delim + strX  + splat; ///
  Serial.println(d);
// outputMsg(msg);
 
 return true;
 
 }




 return false; 
}


void beep (unsigned char speakerPin, int frequencyInHertz, long timeInMilliseconds)     // the sound producing function
{	 
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
          for (x=0;x<loopTime;x++)	 
          {	 
              digitalWrite(speakerPin,HIGH);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
              delayMicroseconds(delayAmount);
          }	 
}
