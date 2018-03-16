#include <LiquidCrystal.h>
#include <dht.h>
#define dht_dpin A1

const int buzzer = 10;
int i =0;
float t = 0;
float u = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;

int portSpeak(10);  
int melodia[] = {660,660,660,510,660,770};
int duracaodasnotas[] = {100,100,100,100,100,100};

 

void setup() {

 lcd.begin(16,2);
 pinMode(buzzer,OUTPUT);
 tone(buzzer,1000);   
 delay(500);
 noTone(buzzer);
 delay(500);


       for (int nota = 0; nota < 6; nota++) {
             int duracaodanota = duracaodasnotas[nota];
             tone(portSpeak, melodia[nota],duracaodanota);
             int pausadepoisdasnotas[] ={150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};
             delay(pausadepoisdasnotas[nota]);}
             noTone(portSpeak);
}

void loop() {
 DHT.read11(dht_dpin);
 float te = DHT.temperature;
 float um = DHT.humidity;
 for (i =0; i <= 2000; i++){
    float t = te + t;
    float u = um + u;
    if( i == 1999){
     u = u/2000;
     t = t/2000;
    if(t > 1 || u > 22){
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("Temp.: ");
    lcd.print(t);
    lcd.print(" C");
    lcd.setCursor(0,1);
    lcd.print("Umid.: ");
    lcd.print(u+19);
    lcd.print(" %");
    delay(2000);   
 }

    if(t == 0 || u == 19){
    lcd.setCursor(0,0);
    lcd.print("--Desconectado--");
    lcd.setCursor(0,1);
    lcd.print("CONECTE O SENSOR ");
    delay(2000);
}

    if(t > 26 || u > 80){
    tone(buzzer,1000);   
    delay(1500);
    noTone(buzzer);
 }


    if(t < 16 && t > 1 ){
    tone(buzzer,1500);   
    delay(1500);
    noTone(buzzer);

 } }  } }
