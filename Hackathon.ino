#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define OLED_RESET 4
DHT dht(3, DHT11);
Adafruit_SSD1306 display(OLED_RESET);

void setup(){
 Serial.begin(9600);
 pinMode(A0, INPUT);
 pinMode(5, OUTPUT);
 dht.begin();
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

}

void loop() {
  //OLED
  display.clearDisplay(); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);


  //Humidity and Temperature
   float t = dht.readTemperature();

   float h = dht.readHumidity();
   display.print ("Temperature: ");
   display.println(t);

   display.print("Humidity: ");
   display.println(h);

  //Moisture
  int ms_value = analogRead(A0);
  Serial.print("Moisture: ");
  Serial.println(ms_value);

  if(ms_value<=300)
  {
    digitalWrite(5, LOW);
    delay(1500);
    digitalWrite(5, HIGH);
    delay(10000);

  }
  else
  {
    digitalWrite(5, LOW);
    delay(1000);
  }

  delay(1000);
  display.display();
}