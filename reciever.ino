 
#define length 8

int byt = 0;
const int LDR = 0;
int ldrValue[10];   //Stores the LDR value
int byteValue = 0;
int value, average, lastValue = 0;
boolean flag = false;
int bin[length];    //stores data in binary
int ascii = 0;      //Stores data in ascii
char character;     //Stores data in characters
int i = 0;

void read();
void calibrate();   //Reads ambient lighting
void converter();
void sdf();

void setup() 
{
  Serial.begin(9600);
  calibrate(); 
}// end setup

void loop() 
{
  start:
  
 
    delay(500);
    for(i=0;i<length;i++)// read data
    {
      read();
      bin[i] = byt;
      Serial.print(bin[i]);
      delay(50);
    }
    Serial.print(" \n"); 
    converter();
}// end loop

void read()
{
  int comp, comp1 = 0;
  comp = average*1,5;
  comp1 = average*1,3;
  
  byteValue = analogRead(LDR);

  if(byteValue <= comp1)
    byt = 0;

  
  if(byteValue >= comp)
    byt = 1;
    

 
 //Serial.print("byt:");
 //Serial.println(byt);
 //Serial.print("byteValue: ");
 //Serial.println(byteValue);
 delay(1000);

}// end read

void calibrate()
{
  int i;
   for ( i = 0; i < 10; i++)
   {
     ldrValue[i] = analogRead(LDR);
     delay(100);
   }
  for ( i = 0; i < 10; i++)
  {
    valor += ldrValue[i];
    /*
    Serial.print("ldrValue:");
    Serial.println(ldrValue[i]);
    Serial.print("value:");
    Serial.println(value);
    */
  }
  average = value/10;
 
  Serial.print("Average value:");
  Serial.println(average);
  
  lastValue = average;
 

}// end calibrate

void converter()
{
  ascii += bin[7] * 1;
  ascii += bin[6] * (2);
  ascii += bin[5] * (2*2);
  ascii += bin[4] * (2*2*2);
  ascii += bin[3] * (2*2*2*2);
  ascii += bin[2] * (2*2*2*2*2);
  ascii += bin[1] * (2*2*2*2*2*2);
  ascii += bin[0] * (2*2*2*2*2*2*2);
  Serial.print(" ascii: ");
  Serial.print(ascii);
  //Serial.print("\n");
  character = (char) ascii;
  Serial.print(" Character: ");
  Serial.print(character);
  Serial.print("\n");
  ascii = 0;
}


void sdf()
{
  int sdfcomp, sdfcomp1, bite = 0;
  int Sdf[4];
  int *p;

  
  sdfcomp = average*1,3;
  sdfcomp1 = average*1,5;
  
  lastValue = analogRead(LDR);
  
  if(lastValue != average)
  {
    byteValue = analogRead(LDR);
    
    
    for(int x=0; x<4; x++)//Read data
      {
        if(byteValue >= sdfcomp1)
            bite = 1;
  
    
        if(byteValue <= sdfcomp)
            bite = 0;
            
         Sdf[x] = bite;
         //Serial.print("Sdf: ");
         //Serial.print(Sdf[x]);
         delay(50);
      }
      //Serial.print("\n");
      
     p = Sdf;
      
     if( *(p+0) == 1 && *(p+1) == 1 && *(p+2) == 1 && *(p+3) == 1)
      {
       flag = true;
      }
      else
      {
        flag = false;
      }
  }
    
}// end sdf
