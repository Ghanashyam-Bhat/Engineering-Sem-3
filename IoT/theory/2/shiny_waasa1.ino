// C++ code
//
void setup()
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  int read=digitalRead(2);
  if(read==HIGH)
  {
   digitalWrite(3,HIGH); 
    delay(1000);
  }
  else
  {
    digitalWrite(3, LOW);
 	 delay(1000); // Wait for 1000 millisecond(s)
  }
  
}