int inPin = 11;         // the number of the input pin
int outPin = 7;       // the number of the output pin
int pinSpeaker = 12;   // The Speaker!

int state = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin

long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(0,OUTPUT); // 1 Minute
  pinMode(1,OUTPUT); // 2 Minutes
  pinMode(2,OUTPUT); // 3 Minutes
  pinMode(3,OUTPUT); // 4 Minutes
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(pinSpeaker, OUTPUT);
}

void flash(long duration, int led, int flashes){
 for(int one = 0; one <= flashes; one++){
    delay(duration);
    digitalWrite(led,LOW);
    delay(duration);
    digitalWrite(led,HIGH);
    }
   
}

void loop()
{
  reading = digitalRead(inPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    time = millis();    
  }

  digitalWrite(outPin, state);

  previous = reading;
  
  if(state == HIGH){
    digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(5000);
 flash(500,0,5);
  digitalWrite(0,LOW);
  delay(5000);
 flash(500,1,5);
  digitalWrite(1,LOW);
  delay(5000);
 flash(500,2,5);
  digitalWrite(2,LOW);
  delay(5000);
 flash(500,3,5);
  digitalWrite(3,LOW);
  delay(150);
  }
  
  
  for(int alarm = 0; alarm <= 60; alarm++){
    delay(150);
    playTone(300, 160);
    delay(150);
     }
  }
  



void playTone(long duration, int freq) { 
 duration *= 1000; 
 int period = (1.0 / freq) * 1000000; 
 long elapsed_time = 0; 
 while (elapsed_time < duration) { 
 digitalWrite(pinSpeaker,HIGH); 
 delayMicroseconds(period / 2); 
 digitalWrite(pinSpeaker, LOW); 
 delayMicroseconds(period / 2); 
 elapsed_time += (period); 
 } 
}
