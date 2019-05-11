//Hecho con placa Arduino Mega
byte Digit[10][8] =
   { 
     { 1,1,1,1,1,1,0,0 },    // 0
     { 0,1,1,0,0,0,0,0 },    // 1
     { 1,1,0,1,1,0,1,0 },    // 2
     { 1,1,1,1,0,0,1,0 },    // 3
     { 0,1,1,0,0,1,1,0 },    // 4
     { 1,0,1,1,0,1,1,0 },    // 5
     { 1,0,1,1,1,1,1,0 },    // 6
     { 1,1,1,0,0,0,0,0 },    // 7
     { 1,1,1,1,1,1,1,0 },    // 8
     { 1,1,1,0,0,1,1,0 }     // 9
   };

void setup()
    {   
      pinMode(13,INPUT);     
      for (int i= 22; i<33; i++)
                     pinMode(i, OUTPUT);
    }
 void Display(int pos, int N)
  {  
       digitalWrite(29 ,LOW);        
       digitalWrite(30,LOW);
       digitalWrite(31,LOW);
       digitalWrite(32,LOW);
 
      for (int i= 0 ; i<8 ; i++)    
            digitalWrite(i+22 , Digit[N][i]) ;

      digitalWrite(pos + 29, HIGH);     
  }
  void CalculaDigitos( int Num)
   {
      int Digit0 = Num %10 ;
      int Digit1 = (Num % 100) / 10 ;
      int Digit2 = (Num % 1000) / 100 ;
      int Digit3 = (Num  / 1000)  ;
     
      
      Display(3 , Digit3);
      Display(2 , Digit2);
      Display(1 , Digit1);
      Display(0 , Digit0);
      if(Digit0==0&&Digit1==0&&Digit2==0&&Digit3==0)//Parar cuando llegue a 0
      {
        while(1)
        {
        }
      }
   }
   void loop()
   {

   CalculaDigitos( 2400-millis() / 10);//Cambiar el 24 para iniciar desde otro valor, por ejemplo para contar desde 14 sería 14000 
   }
