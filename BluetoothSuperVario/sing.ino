
int thisNote = 0;
int thisNote1 = 0;
void sing1(){      
   // iterate over the notes of the melody:
   
  if (supermario == true){
 //    Serial.println(" 'Mario Theme'");
     int size = sizeof(melody) / sizeof(int);
     
     if (thisNote < size ) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/tempo[thisNote];

      

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30 / abs(d/2);
       long currTime = millis();
       
       int time =  currTime - lastTime;
       
       
       if (time <  pauseBetweenNotes ){
         
         if (pout == false){
         pout = true;
          buzz(melodyPin, melody[thisNote],noteDuration);
          
           }
          
         }else{
         lastTime = millis();
         thisNote = thisNote + 1;
       //  Serial.println(thisNote);
          buzz(melodyPin, 0,noteDuration);
          pout = false;
         }
         
        
     //  delay(pauseBetweenNotes);

       // stop the tone playing:
     

    
  }else{ thisNote = 0;} ///loop forever
}
}


void sing2(){      
   // iterate over the notes of the melody:
   
  if (supermario1 == true){
 //    Serial.println(" 'Mario Theme'");
     int size = sizeof(underworld_melody) / sizeof(int);
     
     if (thisNote1 < size ) {

       // to calculate the note duration, take one second
       // divided by the note type.
       //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
       int noteDuration = 1000/underworld_tempo[thisNote1];

      

       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration * 1.30 / abs(d/2);
       long currTime = millis();
       
       int time =  currTime - lastTime;
       
       
       if (time <  pauseBetweenNotes ){
         
         if (pout == false){
         pout = true;
          buzz(melodyPin, underworld_melody[thisNote1],noteDuration);
          
           }
          
         }else{
         lastTime = millis();
         thisNote1 = thisNote1 + 1;
       //  Serial.println(thisNote);
          buzz(melodyPin, 0,noteDuration);
          pout = false;
         }
         
        
     //  delay(pauseBetweenNotes);

       // stop the tone playing:
     

    
  }else{ thisNote1 = 0;} ///loop forever
}
}




void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13,HIGH);
  long delayValue = 1000000/frequency/2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to 
  //// get the total number of cycles to produce
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13,LOW);

}

