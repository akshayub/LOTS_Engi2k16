int enable_speed = 150;
const int  enable = 11;
const int  lmf = 10;
const int  lmb = 12;
const int  rmf = 9;
const int  rmb = 8;
int thresh = 10;

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
      analogWrite(rmf,175);
      analogWrite(rmb,0);

      analogWrite(lmf,0);
      analogWrite(lmb,175);
    }
  else{// if( in[0] > 150){
    light_follow();
  }
}

void light_follow(){
  analogWrite(enable,enable_speed);
  digitalWrite(rmb,LOW);
  digitalWrite(lmb,LOW);
  if(in[1]>thresh /*&& in[1]<1000 */){
    //int x=(-1.0/9.0)*in[1]+(1900/9);
    int x=-0.2*in[1]+280;
    if ( x > 200 )  x = 200;
    analogWrite(lmf,x);
  }
  /*else{
   
    }*/
  if(in[0]>thresh /*&& in[0]<1000*/){
    int z=-0.2*in[0]+280;
    if ( z > 200 )  z = 200;
    //int z=(-1.0/9.0)*in[0]+(1900/9);
    analogWrite(rmf,z);
  }
  /*else{
    analogWrite(rmf,0);
    }
    */
  }


void loop() {
  digitalWrite(13,HIGH);
    get_input();
    rotate();
}
