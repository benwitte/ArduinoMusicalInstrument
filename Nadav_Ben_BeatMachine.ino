
float gChord[] = {98.0, 123.47, 146.83};
float dChord[] = {146.83, 185.00, 220.00};
float eChord[] = {164.81, 196.00, 246.94};
float cChord[] = {130.81, 164.81, 196.00};

float* allChords[] = {gChord, dChord, eChord, cChord}; 



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

// courtesy of shlomo
void playTone(float frequency, int knobValue)
{
    int octave = map(knobValue, 70, 400, 0, 9);
    frequency = frequency * pow(2, octave);
    tone(4, frequency, 200);
}

void loop() {

  // chord input
  int sensorReading = analogRead(A0);
  // speed input
  int potentiometer = analogRead(A5);
  // octave input
  int lightReading = analogRead(A3);


  int playing = map(sensorReading, 30, 650, 0, 3);
  int speed = map(potentiometer, 0, 1023, 2, 7);

  Serial.println(sensorReading);
  
  
  for (int i=0; i < 3; i++) {
    playTone(allChords[playing][i], lightReading);
    delay(speed*100);
  }

}



//sizeof(gChord)/sizeof(float)
