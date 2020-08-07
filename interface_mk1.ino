#include <Servo.h>
Servo ms1;
Servo ms2;
Servo ms3;
Servo ms4;

int a1;
int a2;
int a3;
int a4;

int ax;

int aa1;
int aa2;
int aa3;
int aa4;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  ms1.attach(3);
  ms2.attach(5);
  ms3.attach(6);
  ms4.attach(9);
  Serial.begin(9600);
}
void pitchmm(){
     aa2=aa2-10;
     
     for(int i=0;i<1000;i++){
     justwrite(aa1 ,aa2 ,aa3 ,aa4);
     }
     
     aa2=aa2+10;
}






void pitchpp(){
  
     aa2=aa2+10;
     
     for(int i=0;i<1000;i++){
     justwrite(aa1 ,aa2 ,aa3 ,aa4);
     }
     
     aa2=aa2-10;
}





void justwrite(int aa1, int aa2, int aa3, int aa4){
      ms1.write(aa1);
      ms2.write(aa2);
      ms3.write(aa3);
      ms4.write(aa4);  
}

void yawhead(int reqhead){
    aa4=aa4+9;
    while(reqhead>=(head()+1)&& reqhead<=(head()-1) && ax<1500){
        if(ax<1500){
          ax=pulseIn(12,HIGH);
          justwrite(aa1 ,aa2 ,aa3 ,aa4);
        }else{
          readwrite();
          break;
        }
        aa4=aa4-9;
  }
  








void readwrite(){
  
  a1=pulseIn(2,HIGH);  
  a2=pulseIn(4,HIGH);
  a3=pulseIn(7,HIGH);
  a4=pulseIn(8,HIGH);

  aa1=map(a1,1000,1980,46,141);
  aa2=map(a2,1000,1980,46,141);
  aa3=map(a3,1000,1980,46,141);
  aa4=map(a4,1000,1980,46,141);
  
  ms1.write(aa1);

  ms2.write(aa2);

  ms3.write(aa3);

  ms4.write(aa4);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  ax=pulseIn(12,HIGH);

  Serial.println(ax);

  if(ax>=1500){

  a1=pulseIn(2,HIGH);  
  a2=pulseIn(4,HIGH);
  a3=pulseIn(7,HIGH);
  a4=pulseIn(8,HIGH);

  aa1=map(a1,1000,1980,46,141);
  aa2=map(a2,1000,1980,46,141);
  aa3=map(a3,1000,1980,46,141);
  aa4=map(a4,1000,1980,46,141);
  
  ms1.write(aa1);
  Serial.println(aa1);
  ms2.write(aa2);
  Serial.println(aa2);

  ms3.write(aa3);
  Serial.println(aa3);

  ms4.write(aa4);
  Serial.println(aa4);
  
  }

  
  else{

//functions after toggel
    
  }
  //functions
  


}
