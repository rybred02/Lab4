
#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>


U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);
DHT dht(3, DHT11);
int buzzerPin = 5;
void setup() {
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
dht.begin();
pinMode(buzzerPin, OUTPUT);
}
void loop() {
float t = dht.readTemperature();
float h = dht.readHumidity();
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
float tempFarenheit = (t*9/5) + 32;
u8x8.println("Temperature:");
u8x8.println(tempFarenheit);
u8x8.println("Humidity:");
u8x8.print(h);
while (h > 70) {
    tone(5, 9000);
  
  }
}


