/*
int coil1 = 2;
int coil2 = 4;
int coil3 = 3;
int coil4 = 5;
*/

int coil1 = 3;
int coil2 = 6;
int coil3 = 5;
int coil4 = 9;


int step ;

int interval = 10;

int passi ;

int val_direzione = 0;

int numero ;


void setup() {
  // put your setup code here, to run once:
  

pinMode(coil1,OUTPUT);
pinMode(coil2,OUTPUT);
pinMode(coil3,OUTPUT);
pinMode(coil4,OUTPUT);
}

void loop() {
  

				digitalWrite(coil1, step==0?HIGH:LOW);
				digitalWrite(coil2, step==1?HIGH:LOW);
				digitalWrite(coil3, step==2?HIGH:LOW);
				digitalWrite(coil4, step==3?HIGH:LOW);

				delay(interval);

				step = (step+1)%4;


}
