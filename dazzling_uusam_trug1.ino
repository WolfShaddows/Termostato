#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo servo;
const int potPin = A0;          // Pin analógico para el potenciómetro
float tempDeseada = 20.0;       // Temperatura deseada en grados Celsius

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C de la pantalla LCD

void setup() {
  servo.attach(9);  // Pin para el servo motor
  lcd.begin(16, 2);
  lcd.backlight();  // Encender la retroiluminación del LCD
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);  // Leer el valor del potenciómetro

  // Convertir la lectura del potenciómetro a temperatura (ajuste según sea necesario)
  float tempActual = map(potValue, 0, 1023, 0, 100)/4.3;

  Serial.print("Temperatura Actual: ");
  Serial.print(tempActual);
  Serial.println(" °C");

  mostrarTemperaturaLCD(tempActual);

  if (tempActual > tempDeseada) {
    activarCalefaccion();
  } else {
    desactivarCalefaccion();
  }

  delay(1000);  // Esperar 1 segundo antes de la siguiente lectura
}

void mostrarTemperaturaLCD(float temp) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp Actual: ");
  lcd.print(temp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Temp Deseada: ");
  lcd.print(tempDeseada);
  lcd.print(" C");
}

void activarCalefaccion() {
  // Simular activar calefacción (girar el servo en una dirección)
  servo.write(90);
}

void desactivarCalefaccion() {
  // Simular desactivar calefacción (girar el servo en la otra dirección)
  servo.write(0);
}


