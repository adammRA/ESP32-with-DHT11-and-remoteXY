#include <DHT11.h>

//component pin
DHT11 dht11(4);
int ledyel = 25;
int ledred = 33;
int ledgree = 32;

void setup() { 
  Serial.begin(9600);
  pinMode(ledyel, OUTPUT);  
  pinMode(ledred, OUTPUT);
  pinMode(ledgree, OUTPUT);
}

void loop() {
  int temperature = 0;
  int humidity = 0;

  // Attempt to read the temperature and humidity values from the DHT11 sensor.
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Check the results of the readings.
  // If the reading is successful, print the temperature and humidity values.
  // If there are errors, print the appropriate error messages.
  if (result == 0) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  } else {
    // Print error message based on the error code.
    Serial.println(DHT11::getErrorString(result));
  }

  // Control LEDs based on temperature
  if (temperature<29){
    	digitalWrite(ledgree,HIGH);
        digitalWrite(ledred,LOW);
        digitalWrite(ledyel,LOW);
  }
  else if (temperature>=29&&temperature<40){
      	digitalWrite(ledgree,LOW);
      	digitalWrite(ledyel,HIGH);
      	digitalWrite(ledred,LOW); 
  }
  
  else{
    	digitalWrite(ledgree,LOW);
    	digitalWrite(ledyel,LOW);
    	digitalWrite(ledred,HIGH);
          
  }
}

