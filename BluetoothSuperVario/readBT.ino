void readBT(){
  //Read from bluetooth and write to usb serial 
  while(Serial.available() > 8)
  {
   char toSend = Serial.read();
    if (toSend == 'S'){
     
    
      v[0] = (int)Serial.read() -48; 
      v[1] = (int)Serial.read() -48;
      
      v[2] = (int)Serial.read() -48;
      v[3] = (int)Serial.read() -48; 
      
      v[4] = (int)Serial.read() -48;
      v[5] = (int)Serial.read() -48;
      
      v[6] = (int)Serial.read() -48;
      v[7] = (int)Serial.read() -48;
     
     

    int xVAL1 = v[0] + v[1] *10;  ///pitch
    int xVAL2 = v[2] + v[3] *10;  ////roll
    int xVAL3 = v[4] + v[5] *10;   ////thrust
    int xVAL4 = v[6] + v[7] *10;   //////Seitenruder
 
 if (((xVAL1 >= 0) &&( xVAL1 <  100))&&((xVAL2 >= 0) &&( xVAL2 < 100))&&((xVAL3 >= 0) &&( xVAL3 < 100))&&((xVAL4 >= 0) &&( xVAL4 < 100))){
    pitch = xVAL1;
    roll = xVAL2;
}
}
}
}
void writeBT(){

 //   long px = (out * 100);
//  Example: $POV,P,1018.35*39
 //   char strg[12] = "$POV,P,";
      Serial.write("$POV,P,");
    //  Serial.write(P);
      Serial.write("*");
     
      
//  Serial.write(getCheckSum(strg));
 Serial.write("\r\n"); 

       
           
}


void outputMsg(String msg) {
  msg.toCharArray(CRCbuffer,sizeof(CRCbuffer)); // put complete string into CRCbuffer
  int crc = convertToCRC(CRCbuffer);

  Serial.print(msg);
  if (crc < 16) Serial.print("0"); // add leading 0 
  Serial.println(crc);

 }

// -----------------------------------------------------------------------
byte convertToCRC(char *buff) {
  // NMEA CRC: XOR each byte with previous for all chars between '$' and '*'
  char c;
  byte i;
  byte start_with = 0;
  byte end_with = 0;
  byte CRC = 0;

  for (i = 0; i < buff_len; i++) {
    c = buff[i];
    if(c == '$'){
      start_with = i;
    }
    if(c == '*'){
      end_with = i;
    }      
  }
  if (end_with > start_with){
    for (i = start_with+1; i < end_with; i++){ // XOR every character between '$' and '*'
      CRC = CRC ^ buff[i] ;  // compute CRC
    }
  }
  else { // print locations if error
    Serial.println("CRC ERROR");
   
  }
  return CRC;
  //based on code by Elimeléc López - July-19th-2013
}

