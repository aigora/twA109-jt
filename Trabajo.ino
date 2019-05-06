void setup() 
  {
    pinMode(22,OUTPUT);
    pinMode(23,OUTPUT);
    pinMode(24,OUTPUT);
    pinMode(25,OUTPUT);
    pinMode(26,OUTPUT);
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);
    pinMode(29,OUTPUT);
    pinMode(30,OUTPUT);
    pinMode(31,OUTPUT);
    pinMode(32,OUTPUT);
    pinMode(33,OUTPUT);
    pinMode(34,OUTPUT);
    pinMode(35,OUTPUT);
}
void 7seg1(int a1, int b1,int c1, int d1, int e1,int f1, int g1)
{
digitalWrite(22,a1);
digitalWrite(23,b1);
digitalWrite(24,c1);
digitalWrite(25,d1);
digitalWrite(26,e1);
digitalWrite(27,f1);
digitalWrite(28,g1);
}
void 7seg2(int a2, int b2,int c2, int d2, int e2,int f2,int g2)
{
digitalWrite(29,a);
digitalWrite(30,b);
digitalWrite(31,c);
digitalWrite(32,d);
digitalWrite(33,e);
digitalWrite(34,f);
digitalWrite(35,g);
}

void loop() {
  // put your main code here, to run repeatedly:

}
