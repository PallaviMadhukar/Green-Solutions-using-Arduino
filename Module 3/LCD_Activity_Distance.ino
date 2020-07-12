// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <LiquidCrystal_PCF8574.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

LiquidCrystal_PCF8574 lcd(0x3F);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.home(); 
  lcd.clear();
  lcd.print("Auto Measure RB");
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  int distance = sonar.ping_cm();
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  lcd.setCursor(0, 0);
  lcd.print("CM to object is");
  lcd.setCursor(0, 1);
  lcd.print(distance);
}
