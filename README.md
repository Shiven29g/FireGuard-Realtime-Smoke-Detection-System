Smoke Detection System with IoT Integration

Overview
This project implements a Smoke Detection System using an ESP8266 microcontroller, a gas sensor, a buzzer, and an OLED display. It integrates with the Blynk platform to allow real-time monitoring of gas levels and sends alerts if dangerous gas levels are detected.

Features
Real-time monitoring of gas levels via the gas sensor.
Display gas values and status (Normal/High Alert) on an OLED screen.
Visual alert using an OLED display.
Sound alert through a buzzer when high gas levels are detected.
IoT integration with Blynk for real-time status monitoring and control.
Components Required
ESP8266 (NodeMCU or similar): Microcontroller for WiFi connectivity.
MQ Gas Sensor (or equivalent): To detect gas concentrations.
Buzzer: To sound an alert when gas levels exceed the threshold.
OLED Display (SSD1306): To display the gas levels and status.
Jumper Wires: For connecting components.
Breadboard: For prototyping the circuit.
Software Libraries Used
Blynk: For IoT integration and app interface.
Adafruit SSD1306: For controlling the OLED display.
Adafruit GFX: Graphics library for the OLED display.
ESP8266WiFi: To connect the ESP8266 to a WiFi network.
Project Setup
Hardware Connections
Gas Sensor (MQ Sensor)
Connect the analog output (A0) pin of the gas sensor to the A0 pin on the ESP8266.
Buzzer
Connect the buzzer to D6 pin on the ESP8266.
OLED Display
Connect the OLED display to the I2C pins (SCL, SDA) of the ESP8266.
Software Setup
Install Libraries: Ensure the following libraries are installed in your Arduino IDE:

Blynk: For IoT functionality.
Adafruit SSD1306: For OLED display support.
Adafruit GFX: For display graphics handling.
ESP8266WiFi: For WiFi communication.
Blynk Setup:

Create a project in the Blynk App on your smartphone.
Set up a button on Virtual Pin V1 to control the buzzer manually (0 or 1).
Use the provided Auth Token in the code to authenticate with the Blynk app.
WiFi Setup:

Set your WiFi credentials in the ssid[] and pass[] variables.
Threshold Adjustment:

You can adjust the gas detection threshold by modifying the sensorThreshold variable to suit your sensor's sensitivity.
Code Explanation
Initialization
WiFi: The ESP8266 connects to your WiFi network using the ssid and pass provided.
OLED Display: The OLED screen displays real-time gas values and system status (Normal or High Alert).
Buzzer: If the gas level exceeds the threshold, the buzzer will sound for 3 seconds.
Blynk Integration
Virtual Pin V1: This pin allows you to control the buzzer from the Blynk app. A press of the button sends a signal to stop the buzzer if it is active.
Gas Detection
The system continuously reads the gas sensor and compares the value to a predefined threshold. If the threshold is exceeded, the system displays "High Alert" on the OLED and triggers the buzzer. Otherwise, it shows "Normal" on the display.
Buzzer Control
The buzzer automatically stops after 3 seconds, or you can manually stop it from the Blynk app.
Troubleshooting
OLED not displaying: Make sure the I2C connection is correct and the correct I2C address (0x3C) is used for your OLED.
Gas Sensor: If the sensor isn't responding properly, calibrate it or adjust the threshold to a more suitable value.
Blynk App Not Connecting: Double-check your auth token and WiFi credentials.
Future Improvements
Push Notifications: Integrate with services like IFTTT for notifications on mobile or email.
Multiple Sensors: Add more sensors (e.g., smoke, temperature) for more robust detection.
Web Dashboard: Create a web interface for monitoring the system remotely.
