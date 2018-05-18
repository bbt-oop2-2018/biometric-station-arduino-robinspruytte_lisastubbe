#include <Time.h>
#include <TimeLib.h>

#include <SoftwareSerial.h>

//communication variables
SoftwareSerial mySerial(10, 11); // RX, TX


//preset values
const int MAX_DATA_VALUE = 1000;
const int MIN_DATA_VALUE = 0;
const int NUMBER_OF_DOUBLE_NUMBERS_AFTER_COMMA = 2;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Hello World from Arduino!");
}

void loop() { // run over and over
  //if (Serial.available()) {
    String seconds = (String) now();
    String hartBeat = (String) generateRandomInteger();
    String accelx = (String) generateRandomDouble();
    String accely = (String) generateRandomDouble();
    String accelz = (String) generateRandomDouble();
    String temperature = (String) generateRandomInteger();
    String fingerprint = (String) generateRandomInteger();
    String message = "{ \"timestamp\": " + seconds + ", \"bpm\": " + hartBeat + ", \"temperature\": " + temperature + ", \"accellcx\": " + accelx + ", \"accellcy\": " + accely + ", \"accellcz\": " + accelz + "}";
    
    Serial.println(message);
  //}
  delay(1000);
}


double generateRandomDouble () {
  return random(MIN_DATA_VALUE, MAX_DATA_VALUE)/pow(10, NUMBER_OF_DOUBLE_NUMBERS_AFTER_COMMA);
}

int generateRandomInteger () {
 return random(MIN_DATA_VALUE, MAX_DATA_VALUE); 
}

