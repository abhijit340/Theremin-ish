
 // Speker output pin
int SPEAKER_OUT = 4;
int POT_PIN = 1;
int PotIn = 0;
int Freq = 440;
// this was the range i found to be plesant
int MIN_F = 100;
int MAX_F = 670;

//utrasonic varibles 
int TRIG_PIN = 2;
int ECHO_PIN = 3;
long dur;
double dist;

//pushbutton set up
int PUSH_PIN= 9;
int buttonState = 0;

void setup() {
  
 Serial.begin(9600);
 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);
 pinMode(PUSH_PIN, INPUT);

  
}

void loop() {
  
  
  // 100 to 10k is approx buzzer range
// Code Adapted From http://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 
// clear pin  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

//send trigger for 10 milsec
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(50);
  digitalWrite(TRIG_PIN, LOW);

// read ultrasound response
 dur = pulseIn(ECHO_PIN, HIGH);

buttonState =digitalRead(PUSH_PIN);
if (buttonState == LOW)
{
  dist = dur*0.034/2 + 15;
}
else
{
  
}

//distance calcs


Freq = dist*16.75;
if(Freq < MIN_F)
{
Freq = MIN_F;
}

if(Freq > MAX_F)
{
noTone(SPEAKER_OUT);
}
else
{
  tone(SPEAKER_OUT ,Freq);
}



//noTone(SPEAKER_OUT);
//delay(0);
//noTone(SPEAKER_OUT);
Serial.print(Freq);
Serial.print(" ");
}
