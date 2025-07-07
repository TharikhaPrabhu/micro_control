// Pin Definitions
const int level1 = 2;  // Push Button 1 - 2mm
const int level2 = 3;  // Push Button 2 - 4mm
const int level3 = 4;  // Push Button 3 - 6mm
const int ledPin = 13;
const int buzzerPin = 11;

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 9, 8, 12);  // RS, E, D4, D5, D6, D7

void setup() {
  pinMode(level1, INPUT);  // Pull-down logic (matches your Proteus wiring)
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Sludge Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  bool l1 = digitalRead(level1);
  bool l2 = digitalRead(level2);
  bool l3 = digitalRead(level3);

  lcd.setCursor(0, 0);
  lcd.print("Sludge Level:");

  if (l3) {
    lcd.setCursor(0, 1);
    lcd.print("HIGH          ");
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);  // Buzz continuously
  } else if (l2) {
    lcd.setCursor(0, 1);
    lcd.print("MEDIUM        ");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  } else if (l1) {
    lcd.setCursor(0, 1);
    lcd.print("LOW           ");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("CLEAN         ");
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  delay(500);
}
