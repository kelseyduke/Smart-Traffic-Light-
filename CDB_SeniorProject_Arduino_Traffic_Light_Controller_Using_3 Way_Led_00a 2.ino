 // CDB_SeniorProject_Arduino_Traffic_Light_Controller_Using_3 Way_Led_00a



 // Major direction lights
int Major1=8;
int Major2=9;   
int Major3=10;
 // Minor direction lights
int Minor1=11;
int Minor2=12;
int Minor3=13;

  // Traffic Light Time Cycle Sequence: d = 20000 [20-seconds] and dd = 12000 [12-seconds]
int d=9000;
int dd=5000;
int ccc=2000;

void setup()
{
  pinMode(Major1, OUTPUT);
  pinMode(Major2, OUTPUT);
  pinMode(Major3, OUTPUT);

  pinMode(Minor1, OUTPUT);
  pinMode(Minor2, OUTPUT);
  pinMode(Minor3, OUTPUT);
}

void loop()
{

  // State-1: Major Traffic Flow with Minor Traffic at a halt.
  digitalWrite(Major1,HIGH);
    digitalWrite(Major2,LOW);
    digitalWrite(Major3,LOW);
      digitalWrite(Minor1,LOW);
      digitalWrite(Minor2,LOW);
      digitalWrite(Minor3,HIGH);
delay(d);

    digitalWrite(Major1,LOW);
  digitalWrite(Major2,HIGH);
    digitalWrite(Major3,LOW);
      digitalWrite(Minor1,LOW);
      digitalWrite(Minor2,LOW);
      digitalWrite(Minor3,HIGH);
delay(dd);

    digitalWrite(Major1,LOW);
    digitalWrite(Major2,LOW);
  digitalWrite(Major3,HIGH);

      digitalWrite(Minor1,LOW);
      digitalWrite(Minor2,LOW);
      //digitalWrite(Minor3,HIGH);
//delay(dd);

  //digitalWrite(Minor3,LOW);
delay(ccc);


  // State-2: Minor Traffic Flow with Major Traffic at a halt.
  digitalWrite(Minor1,HIGH);
    digitalWrite(Minor2,LOW);
    digitalWrite(Minor3,LOW);
      digitalWrite(Major1,LOW);
      digitalWrite(Major2,LOW);
      digitalWrite(Major3,HIGH);
delay(d);

    digitalWrite(Minor1,LOW);
  digitalWrite(Minor2,HIGH);
    digitalWrite(Minor3,LOW);
      digitalWrite(Major1,LOW);
      digitalWrite(Major2,LOW);
      digitalWrite(Major3,HIGH);
delay(dd);

    digitalWrite(Minor1,LOW);
    digitalWrite(Minor2,LOW);
  digitalWrite(Minor3,HIGH);
  
      digitalWrite(Major1,LOW);
      digitalWrite(Major2,LOW);
      //digitalWrite(Major3,HIGH);
//delay(dd);

  //digitalWrite(Major3,HIGH);
delay(ccc);


}
