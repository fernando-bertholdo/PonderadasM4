unsigned long tempo;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tempo=millis();
  int vr= analogRead(A0);
  float vrVolts= vr*5.0/1023;
  float vcVolts= 5.0 - vrVolts;
  
  
  //IMPRIMINDO OS RESULTADOS
  Serial.print("VC: ");
  Serial.print(vcVolts,2);
  Serial.print("    	  ");
  Serial.print("TEMPO: ");
  Serial.print(tempo);
  Serial.print("    	  ");
  Serial.print("VR: ");
  Serial.println(vrVolts,2);
  delay(100);
  
}