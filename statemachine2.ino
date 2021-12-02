const byte redONE = 13;
const byte yellowONE = 12;
const byte greenONE = 11;
const byte redTWO = 10;
const byte yellowTWO = 9;
const byte greenTWO = 8;
const byte redTHREE = 7;
const byte yellowTHREE = 6;
const byte greenTHREE = 5;
const byte redFOUR = 4;
const byte yellowFOUR = 3;
const byte greenFOUR = 2;

unsigned long currentTime;
unsigned long sequenceLedStartTime;
#define p1 A0
#define p2 A1
#define p3 A2
#define p4 A3

float IR1=0;
float IR2=0;
float IR3=0;
float IR4=0;

enum ledStates
{
  STATE0001,
  STATE0010,
  STATECLEAR,
  STATE0100,
  STATE1000
};

ledStates currentState = STATECLEAR;


void setup() {
   Serial.begin(115200);
  pinMode(redONE,OUTPUT);
  pinMode(yellowONE,OUTPUT);
  pinMode(greenONE,OUTPUT);
  
  pinMode(redTWO,OUTPUT);
  pinMode(yellowTWO,OUTPUT);
  pinMode(greenTWO,OUTPUT);
  
  pinMode(redTHREE,OUTPUT);
  pinMode(yellowTHREE,OUTPUT);
  pinMode(greenTHREE,OUTPUT);
  
  pinMode(redFOUR,OUTPUT);
  pinMode(yellowFOUR,OUTPUT);
  pinMode(greenFOUR,OUTPUT);

  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(p4,INPUT);

}

void loop() {
   currentTime = millis();
   
 IR1=analogRead(p1);
 IR2=analogRead(p2);
 IR3=analogRead(p3);
 IR4=analogRead(p4);

delay(3000);
if(IR1<500&&IR2<500&&IR3<500&&IR4<500)
ledStates currentState = STATECLEAR;
else if(IR1<500&&IR2<500&&IR3<500&&IR4>500)
ledStates currentState = STATE0001;
else if(IR1<500&&IR2<500&&IR3>500&&IR4<500)
ledStates currentState = STATE0010;
else if(IR1<500&&IR2>500&&IR3<500&&IR4<500)
ledStates currentState = STATE0100;
else if(IR1>500&&IR2<500&&IR3<500&&IR4<500)
ledStates currentState = STATE1000;
 switch(currentState)
  {
    case STATECLEAR:
 
  digitalWrite(redONE,HIGH);//g4 high
  digitalWrite(yellowONE,LOW);
  digitalWrite(greenONE,LOW);
  
  digitalWrite(redTWO,HIGH);
  digitalWrite(yellowTWO,LOW);
  digitalWrite(greenTWO,LOW);
   
  digitalWrite(redTHREE,HIGH);
  digitalWrite(yellowTHREE,LOW);
  digitalWrite(greenTHREE,LOW);
   
  digitalWrite(redFOUR,HIGH);
 digitalWrite(yellowFOUR,LOW);
  digitalWrite(greenFOUR,LOW);
     if (currentTime - sequenceLedStartTime >= 10000)
  {
    sequenceLedStartTime = currentTime;
    currentState = STATECLEAR;
  }
  
  break;
   case STATE0001:
 digitalWrite(redONE,HIGH);//g4 high
 digitalWrite(yellowONE,LOW);
  digitalWrite(greenONE,LOW);
  
  digitalWrite(redTWO,HIGH);
  digitalWrite(yellowTWO,LOW);
   digitalWrite(greenTWO,LOW);
   
  digitalWrite(redTHREE,HIGH);
  digitalWrite(yellowTHREE,LOW);
   digitalWrite(greenTHREE,LOW);
   
  digitalWrite(redFOUR,LOW);
 digitalWrite(yellowFOUR,LOW);
  digitalWrite(greenFOUR,HIGH);
     if (currentTime - sequenceLedStartTime >= 10000)
  {
    sequenceLedStartTime = currentTime;
    currentState = STATECLEAR;
  }
  break;
   case STATE0010:
  digitalWrite(redONE,HIGH);//g3 high
digitalWrite(yellowONE,LOW);
  digitalWrite(greenONE,LOW);
  
  digitalWrite(redTWO,HIGH);
 digitalWrite(yellowTWO,LOW);
  digitalWrite(greenTWO,LOW);
  
  digitalWrite(redTHREE,LOW);
 digitalWrite(yellowTHREE,LOW);
  digitalWrite(greenTHREE,HIGH);
  
  digitalWrite(redFOUR,HIGH);
 digitalWrite(yellowFOUR,LOW);
  digitalWrite(greenFOUR,LOW);
     if (currentTime - sequenceLedStartTime >= 10000)
  {
    sequenceLedStartTime = currentTime;
    currentState = STATECLEAR;
  }
break;
case STATE0100:
  digitalWrite(redONE,HIGH);//g2 high
  digitalWrite(yellowONE,LOW);
  digitalWrite(greenONE,LOW);
  
  digitalWrite(redTWO,LOW);
  digitalWrite(yellowTWO,LOW);
  digitalWrite(greenTWO,HIGH);
 
  digitalWrite(redTHREE,HIGH);
  digitalWrite(yellowTHREE,LOW);
  digitalWrite(greenTHREE,LOW);
  
  digitalWrite(redFOUR,HIGH);
  digitalWrite(yellowFOUR,LOW);
  digitalWrite(greenFOUR,LOW);
     if (currentTime - sequenceLedStartTime >= 10000)
  {
    sequenceLedStartTime = currentTime;
    currentState = STATECLEAR;
  }
  break;
 case STATE1000:
  digitalWrite(redONE,LOW);//g1 high
  digitalWrite(yellowONE,LOW);
  digitalWrite(greenONE,HIGH);
  
  digitalWrite(redTWO,HIGH);
  digitalWrite(yellowTWO,LOW);
  digitalWrite(greenTWO,LOW);
  
  digitalWrite(redTHREE,HIGH);
  digitalWrite(yellowTHREE,LOW);
  digitalWrite(greenTHREE,LOW);
  
  digitalWrite(redFOUR,HIGH);
  digitalWrite(yellowFOUR,LOW);
  digitalWrite(greenFOUR,LOW);
   if (currentTime - sequenceLedStartTime >= 10000)
  {
    sequenceLedStartTime = currentTime;
    currentState = STATECLEAR;
  }
  break;
  }
}
 
