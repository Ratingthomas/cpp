/*video met de map functie: https://www.youtube.com/watch?v=1WnGv-DPexc
video voor welke pin waar moet: https://www.youtube.com/watch?v=hkN-xdZz-Gc*/
#include <Servo.h>
/*de Servo wordt s1 genoemt*/
Servo s1; 
/*het uit einde van de draaden zit aan een kant helemaal zwart dat is de boven kant en als 
je dan van te voren kijkt dan.
Het meest linker draat moet op een pin(hij kan op elke pin)
Het middelste moet op 5V en de rechter moet op ground*/
int pin = 14; 
int change =180;
bool max = true;
int graden = 180;

void verander_map(){
  if(max == true){
    change = change - 10;
  }else{
    change = change + 10;
  }
  if(change >= 10000){
max = true;
  }else if(change <= 0){
max = false;
}
}
void verander_graden(){
 /*dit stuk werkt ook en je hoeft dan geen map te gebruiken je moet dan gewoon bij s1.write
graden neer te zetten*/
if(max == true){
    graden = graden - 5;
  }else{
    graden = graden + 5;
  }
  // put your main code here, to run repeatedly:
  if(graden >= 180){
max = true;
  }else if(graden <= 0){
max = false;
} 
}
void Servo_move(){
  /*Met map kan je alle max en min waarden aan passen van de servo
  de 1ste plek is de waarde, 2de minimale waarden, 3de max waarden,
  4de min doelberijk(van hoeveel tot hoeveel graden hij gaat), 5de max doelbereik*/
int angle = map(change,0,10000,0,180);
  s1.write(angle); 
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  s1.attach(pin);
}

void loop() {
  // put your main code here, to run repeatedly:
 verander_map();
  Servo_move();
  delay(5);
}
