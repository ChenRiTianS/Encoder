const int clkPin = 8;
const int dtPin = 7;
const int swPin = 6;


void setup()
{
  
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
  digitalWrite(swPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  int  EncoderState = getEncoderTurn();
 
  if (EncoderState == 1);
  {
    
  }
  if (EncoderState == 0);
  {
    
  }



}


int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;
  int result;

  int newA = digitalRead(dtPin);
  int newB = digitalRead(clkPin);
  if (newA != oldA || newB != oldB)
  {
    if (oldA == HIGH && newA == LOW)
    {
      result = oldB;//cw=1,ccw=0
    }
    
  }


  
  if (newA == oldA && newB == oldB)
  {
    result = 5;
    
    
  }
  if(result ==0)
  {
    Serial.println("cw");
  }
  if(result ==1)
  {
    Serial.println("ccw");
  }
  
  
  oldA = newA;
  oldB = newB;
  return result;
}
