#define IN1 9 
#define IN2 8 
#define IN3 7 
#define IN4 6
char Reading;  
void setup() {  
Serial.begin (9600); 
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
}  
void forword()
{
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW); 
}
void backword(){ 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, HIGH); }
void left(){ 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, HIGH); 
digitalWrite(IN4, LOW); }
void right()
{
digitalWrite(IN1, HIGH); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW); }
void stopp(){ 
digitalWrite(IN1, LOW); 
digitalWrite(IN2, LOW); 
digitalWrite(IN3, LOW); 
digitalWrite(IN4, LOW); }

void loop(){
if(Serial.available()>0){
  Reading=Serial.read();
  switch(Reading){
    case 'F': forword(); 
    break; 
    case 'B': backword(); 
    break; 
    case 'R': right(); 
    break; 
    case 'L' : left(); 
    break;
    case 'S' :stopp(); 
    break;
  }
  }
}
