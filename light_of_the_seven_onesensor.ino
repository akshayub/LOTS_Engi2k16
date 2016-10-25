
const int enable = 11;
const int lmf = 10;
const int lmb = 12;
const int rmf = 9;
const int rmb = 8;
int thresh= 10;

int in[3];
void setup() {
  for(int i=0; i<=13; i++)
    pinMode(i,OUTPUT);
    Serial.begin(9600);
  }
void get_input(){
  for(int i=0; i<3; i++){
    in[i] = analogRead(i);
    }
}

void rotate(){
  if (in[2] < thresh){
      analogWrite(11,150);
      analogWrite(rmf,150);
      analogWrite(rmb,0);

      analogWrite(lmf,0);
      analogWrite(lmb,150);
    }
  else{// if( in[0] > 150){
    light_follow();
  }
}

void light_follow(){
  analogWrite(11,150);
  digitalWrite(lmb,LOW);
  digitalWrite(rmb,LOW);
  digitalWrite(13,HIGH);
  analogWrite(lmf,150);
  analogWrite(rmf,150);
  }


void loop() {
    get_input();
    rotate();
}

