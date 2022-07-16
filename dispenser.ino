#include <Servo.h> //libreria per utilizzare le funzioni del servomotore
#include "SR04.h" //libreria per utilizzare le funzioni del sensore di distanza
Servo servomotore; //dichiaro la variabile ti tipo servo con il nome servomotore
#define trigPin=3; //definisco in che pin digitale è collegato il connettore trigPin 
#define echoPin = 2;
int servoPin = 9; //dichiaro in che pin digitale è collegato il connettore del servo motore
SR04 sr04 = SR04 8ECHO_PIN,TRIG_PIN; //dichiaro la variabile sr04 e assegno i valori dei pin digitali corrispondenti
long a; //dichiaro una variabile a, la useremo per calcolare la distanza

void setup () {
   servo.attach(servoPin); //"accendiamo il pin"
   servo.write(0); //il pin si posizionare alla posizione o gradi
   delay(1000); //pausa di 1 sec
   servo.detach(); //"spegnimento" del servo
}

void loop (){
   a=sr04.Distance(); //misuro la distanza
   if(a<20){ //se la distanza è inferiore a 20 cm allora...
   servo.attach(servoPin); //"accendo" il servo
   delay(10);
   servo.write(150); //il servo si ruota di 150 gradi
   delay(1000);
   servo.write(0); //ritorna alla posizione iniziale (0)
   delay(1000);
   servo.detach(); //"si spegne"
}
