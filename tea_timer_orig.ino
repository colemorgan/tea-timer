int pinSpeaker = 12;
int pinButton = 11;
int state = HIGH; // the current state of the output pin
int revstate = LOW;
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
int val = 0;

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers


void setup() {
  pinMode(0,OUTPUT); // 1 Minute
  pinMode(1,OUTPUT); // 2 Minutes
  pinMode(2,OUTPUT); // 3 Minutes
  pinMode(3,OUTPUT); // 4 Minutes
  pinMode(4,OUTPUT); // Not used yet
  pinMode(A0,INPUT); // Selector 1
  pinMode(A1,INPUT); // Selector 2
  pinMode(A2,INPUT); // Selector 3
  pinMode(A3,INPUT); // Selector 4
  pinMode(A4,INPUT); // Start
  pinMode(A5,INPUT); // Reset
  pinMode(pinSpeaker, OUTPUT);
  pinMode(pinButton,INPUT);
}
 
void loop() {
  
  
  reading = digitalRead(pinButton);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH)
      state = LOW,revstate = HIGH;
    else
      state = HIGH,revstate = LOW;

    time = millis();    
  }
  
  val = digitalRead(pinButton); // read input value 
  if (val == HIGH && state == HIGH) { // check if the input is HIGH 
  
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  delay(30000);
  for(int one = 0; one <= 30; one++){
    delay(500);
    digitalWrite(0,LOW);
    delay(500);
    digitalWrite(0,HIGH);
     }
  digitalWrite(0,LOW);
  delay(30000);
  for(int two = 0; two <= 30; two++){
    delay(500);
    digitalWrite(1,LOW);
    delay(500);
    digitalWrite(1,HIGH);
     }
  digitalWrite(1,LOW);
  delay(30000);
  for(int three = 0; three <= 30; three++){
    delay(500);
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(2,HIGH);
     }
  digitalWrite(2,LOW);
  delay(30000);
  for(int four = 0; four <= 5; four++){
    delay(500);
    digitalWrite(3,LOW);
    delay(500);
    digitalWrite(3,HIGH);
     }
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
  
