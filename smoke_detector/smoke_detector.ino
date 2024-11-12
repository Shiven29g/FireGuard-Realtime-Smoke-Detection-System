#define BLYNK_TEMPLATE_ID "TMPL3A5y0qsm2"
#define BLYNK_TEMPLATE_NAME "smoke detection system"
#define BLYNK_AUTH_TOKEN "quT0PQfFPTyvYvFxH_AF834pX3k69Gow"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);  // Initialize OLED display

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Sus";  // WiFi name
char pass[] = "shiven1234";   // WiFi password

BlynkTimer timer;

int GasSensor = A0;  // Gas sensor input pin
#define Buzzer D6     // Buzzer pin

int sensorThreshold = 600;  // Adjusted threshold for gas detection
bool buzzerActive = false;  // To track buzzer status

// Blynk virtual pin for buzzer control
BLYNK_WRITE(V1) {
   int value = param.asInt();  // Get value from Blynk app (0 or 1)
   if (value == 0) {
       stopBuzzer();  // Stop the buzzer if the button is pressed
   }
}

// Function to stop the buzzer
void stopBuzzer() {
   buzzerActive = false;
   digitalWrite(Buzzer, LOW);  // Turn off the buzzer
   Serial.println("Buzzer Stopped");
}

// Function to read sensor value and update status
void sendSensor() {
   int gasValue = analogRead(GasSensor);
   Blynk.virtualWrite(V0, gasValue);  // Send gas value to the Blynk app
   Serial.print("Gas Value: ");
   Serial.println(gasValue);

   // Display real-time gas value on OLED
   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0, 0);
   display.print("Gas Value: ");
   display.print(gasValue);

   display.setCursor(0, 10);
   display.print("Threshold: ");
   display.print(sensorThreshold);

   // Check gas level against the threshold
   if (gasValue < sensorThreshold) {
       // Normal Condition
       display.setCursor(0, 20);
       display.print("Status: Normal");
       if (!buzzerActive) {
           digitalWrite(Buzzer, LOW); // Ensure buzzer is off
       }
       Serial.println("Gas Normal");
   } else {
       // High Gas Level
       display.setCursor(0, 20);
       display.print("Status: HIGH ALERT");
       Serial.println("Gas is High");

       // Activate the buzzer for 3 seconds if not already active
       if (!buzzerActive) {
           buzzerActive = true;
           digitalWrite(Buzzer, HIGH);  // Buzzer ON
           Serial.println("Buzzer Activated for 3 seconds");
           Blynk.logEvent("gas_alert", "Gas is High");
           timer.setTimeout(3000L, stopBuzzer);  // Schedule buzzer to stop after 3 seconds
       }
   }

   display.display();  // Update the display
}

void setup() {
   Serial.begin(115200);

   // Set Pin Modes
   pinMode(GasSensor, INPUT);
   pinMode(Buzzer, OUTPUT);

   // Initialize Blynk
   Blynk.begin(auth, ssid, pass);

   // Set Timer Interval for Sensor Readings
   timer.setInterval(1000L, sendSensor);

   // Initialize OLED Display
   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
      Serial.println(F("SSD1306 allocation failed"));
      while (true);  // Stop if initialization fails
   }

   display.clearDisplay();
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(20, 20);
   display.print("Calibrating...");
   display.display();
   delay(2000);
   display.clearDisplay();
}

void loop() {
   Blynk.run();
   timer.run();
}
