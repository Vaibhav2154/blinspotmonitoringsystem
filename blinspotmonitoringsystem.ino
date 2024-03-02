// Define the pins for the ultrasonic sensor, buzzer, and LED
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int ledPin = 13; 

// Define variables for duration and distance
long duration;
int distance;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Set trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT);

  // Set echoPin as an INPUT
  pinMode(echoPin, INPUT);

  // Set buzzerPin and ledPin as OUTPUTs
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Generate a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Map the distance value to control the intensity of the buzzer and brightness of the LED
  int buzzerIntensity = map(distance, 5, 20, 150, 0);
  int ledBrightness = map(distance, 5, 20, 150, 0);

  // Constrain values to valid ranges
  buzzerIntensity = constrain(buzzerIntensity, 0, 255);
  ledBrightness = constrain(ledBrightness, 0, 255);

  // Set the buzzer intensity
  analogWrite(buzzerPin, buzzerIntensity);

  // Set the LED brightness
  analogWrite(ledPin, ledBrightness);

  // Add a delay to control how often the distance is measured
  delay(500);
}
