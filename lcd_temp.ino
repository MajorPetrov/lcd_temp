#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#define ONE_WIRE_BUS 2

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
  lcd.begin(20,4);   // initialisation de l'écran à la bonne taille
  //lcd.backlight(); aussi utile que la bite d'un pape
  lcd.setCursor(0, 0); //première ligne
  lcd.print(" Temperature: ");
}
 
 
void loop(void)
{
  float temp;
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  temp = sensors.getTempCByIndex(0);
  Serial.print(temp); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
  lcd.setCursor(14, 0);  
  lcd.print(temp);
  delay(1000);
}
