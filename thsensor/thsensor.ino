/* THM
 Temperature- & Humiditymeter
 10.7.2022

 Including the needed libraries & defining the used sensor as type 22
 [we use quite non-traditional library dht_nonblocking from https://github.com/olewolfDHT_nonblocking by wolf@blazingangles.com]
 as this enables you to read sensor values from the DHT22 temperature and humiditiy sensors without blocking other code execution.
*/
#include <dht_nonblocking.h>
#include <LiquidCrystal.h>

#define DHT_TYPE DHT_TYPE_22

// Defining essential pins

static const int DHT_PIN = 8;
DHT_nonblocking sensor(DHT_PIN, DHT_TYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Only the LCD-screen requires setup here, so we do that

void setup(){

  lcd.begin(16, 2);

}

void loop(){
  
  // declaring variables
  float temperature;
  float humidity;
  
  // set the cursor to the beginning
  lcd.setCursor(0, 0);
  
  // measure the temperature and humidity
  sensor.measure(&temperature, &humidity);
  
  // Print to LCD: temperature and its value, set cursor to the beginning of the next row, print humidity and its value.
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print(" C,");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");
}
