long previousMillis = 0;

boolean timer(int interval) {
 unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
 
 d = a - lastA;
 lastA = a;
 

 
  float x = P + 0.01;
  float y = 20;
  String cmd = "$POV,P";    // a command name
  dtostrf(x,4,2,strX);      // format float value to string XX.X
  dtostrf(y,4,1,strY);      
  msg = cmd + delim + strX  + splat; ///
  
 outputMsg(msg);
 
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
