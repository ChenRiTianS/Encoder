
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

  int  ButtonClick = getButtonClick();
}



int getButtonClick(void)
{
  int ButtonClick;
  int result;
  if (digitalRead(swPin) == LOW)
  {
    result = 1;

  }
  else
  {
    result = 0;

  }
  int i = 0;
  if (result == 1)//(!digitalRead(e))
  {
    //int i = 0;
    //按下循环
    while (result == 1 ) //(!digitalRead(e))
    {
      delay(10);
      i++;
      //按下超时（上一首）
      if (i > 50)
      {
        //#按钮长按保持#
        Serial.println("11");
        Serial.println("10");
        i = 0;
        while (result == 1)//(!digitalRead(e))
        {
          if (i > 1)

            //#按钮长按保持循环#
            Serial.println("21");
          Serial.println("20");
        }
        delay(500);
        i++;
      }
      return;
    }
  }
  i = 0;
  //释放循环
  while (result == 0)// (digitalRead(e))
  {
    delay(10);
    i++;
    //释放超时（暂停/播放）
    if (i > 50)
    {
      //#按钮短按#
      Serial.println("31");
      Serial.println("30");
      return;
    }
  }

  i = 0;
  //按下循环2
  while (result == 1)//(!digitalRead(e))
  {
    delay(10);
    i++;

    
    //按下超时（下一首）
    if (i > 50)
    {
      //#按钮双击保持#
      Serial.println("41");
      Serial.println("40");
      i = 0;
      while (result == 1)//(!digitalRead(e))
      {
        if (i > 1)
        {
          //#按钮双击保持循环#
          Serial.println("51");
          Serial.println("50");
        }
        delay(500);
        i++;
      }
      return;
    }
  }

  i = 0;
  //释放循环2
  while (result == 0 )// (digitalRead(e))
  {
    delay(10);
    i++;
    //释放超时（下一首）
    if (i > 50)
    {
      //#按钮双击#
      Serial.println("61");
      Serial.println("60");
      return;
    }
  }

  //按下循环3
  while (result == 1)//(!digitalRead(e))
  {
    delay(10);
    i++;
    //按下超时（喜欢）
    if (i > 50)
    {
      //#按钮三击保持#
      Serial.println("71");
      Serial.println("70");
      while (result == 1 )//(!digitalRead(e))
      {
        //#按钮三击保持循环#
        delay(500);
      }
      return;
    }
  }
  //#按钮三击#
  Serial.println("81");
  Serial.println("80");

  

return result;
}
