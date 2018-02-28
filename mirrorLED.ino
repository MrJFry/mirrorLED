int led = 9;
int buttonpin = 2;
boolean stayon = false;
int inertia = 10;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;

void setup (){ 
  pinMode(buttonpin,INPUT);
  pinMode(led,OUTPUT);
  analogWrite(led,0);
}

void loop(){
  if((digitalRead(buttonpin) == HIGH) && (stayon == false)){
    fadeup();
      stayon = true;
  }    
  while((digitalRead(buttonpin) == HIGH) && (stayon == true)){
    analogWrite(led, 255);
  }
  if((digitalRead(buttonpin) == LOW) && (stayon == true)){
      delay(5000);
        if((digitalRead(buttonpin) == LOW) && (stayon == true)){
          fadedown();
          stayon = false;
        }
        else{
          while(digitalRead(buttonpin) == HIGH){
          analogWrite(led, 255);
          }
        }
   }
   if((digitalRead(buttonpin) == LOW) && (stayon == false)){
    analogWrite(led, 0);
   }


} //END LOOP +++ START FUNCTIONS

void fadeup (void) {
  for(int state=0;state<256;state++){
      analogWrite(led, state);
      delay(inertia);
  }
}

void fadedown (void){
  for(int state=255;state>0;state--){
      analogWrite(led, state);
      delay(inertia);
  }
 }
