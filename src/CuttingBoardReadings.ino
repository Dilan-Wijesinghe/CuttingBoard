unsigned long sum;
unsigned long avg; 
int numReads = 100;

// Init Input Variables
static const int potPins[] = {A0, A1, A2, A5, A6, A7};
static const int numSensors = sizeof(potPins) / sizeof(potPins[0]);
static const int togglePin = 0; // Digital Pin for Toggle Switch is pin0
bool currState = false;
bool lastState = false;
int potVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  while(!Serial);
  if(!digitalRead(togglePin)) {
    currState = true;
  } else {
    currState = false;
  }

  if(currState != lastState) {
    Serial.write(253);
  }
  lastState = currState;

  //Take 100 readings, find avg
  for (int i = 0; i < numSensors; i++) {
    avg = 0;
    sum = 0;
    for(int j = 0; j < numReads; j++) {
       potVal = analogRead(potPins[i]);
       sum += potVal; // Sum for averaging
    }
    avg = (sum / numReads);
    int bit1 = (avg >> 8) & 0x0F; // 4 Upper
    int bit2 = avg & 0xFF; // 8 Lower
    Serial.write(255); // Pre-amble 
    Serial.write(bit1);
    Serial.write(bit2);
    // Serial.print("Sensor ");
    // Serial.print(i);
    // Serial.print(" ");
    // Serial.println(avg);
  }
  Serial.write(254); // End of Read from all 6
}

