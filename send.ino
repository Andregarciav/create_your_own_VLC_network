/* 
    This code is an example for transmitting a character via vlc.
    It captures a character and transmits it using an ascii table.
    The code was developed to use two Arduinos.
*/
#define length 8

const int led = 13;
char msg;
int ascii;
int bin[length];
int i = 7;
int j = i;
int *p;

void char2bin();

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}// end setup

void loop() 
{
  if(Serial.available())
  {
    msg = Serial.read();

    char2bin();

    p = bin;
    //Preamble
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
    delay(500);
    //end preamble
    
    // Transmission
    for(int x= 0; x< length; x++)
    {
      if( *(p+x) == 1)
      {
        digitalWrite(led, HIGH);
        //Serial.print("On ");
      }
      else
      {
        digitalWrite(led, LOW); 
        //)Serial.print("Off ");
      }
         delay(1050);
    }
  }
  
  else
  {
    delay(500);
    digitalWrite(led,HIGH);
  }


}// end loop

void char2bin()
{
  ascii =(int) msg;
  Serial.print("ascii");
  Serial.println(ascii);
  if (ascii >= 1)
  {
    while (ascii/2 > 0)
    {
      bin[i] = ascii%2;
      ascii /= 2;
      i--;
      j--;
    }

    for (i = 0; i <j; i++)
      bin[i] = 0;

    bin[j] = 1;

    Serial.print("Binary:");
    for (i = 0; i < length; i++)
    {
      Serial.print(bin[i]);
    }

  } 
  else if (ascii == 0)
  {
    for (i = 0; i < length; i++)
    {
      bin[i] = 0;
    }

    Serial.print("Binary:");
    for (i = 0; i < length; i++)
    {
      Serial.print(bin[i]);
    }

  }
  Serial.print("\n\n");
}


