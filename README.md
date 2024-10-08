# Smoke-Detection-IOT
# Quick Start Guide
Problem Type : Binary Classification
Target Variable : Fire Alarm

# Context
A smoke detector is a device that senses smoke, typically as an indicator of fire. Smoke detectors are usually housed in plastic enclosures, typically shaped like a disk about 150 millimetres (6 in) in diameter and 25 millimetres (1 in) thick, but shape and size vary.

--> Types of Smoke Detectors

# Photoelectric Smoke Detector
A photoelectric smoke detector contains a source of infrared, visible, or ultraviolet light, a lens, and a photoelectric receiver. In some types, the light emitted by the light source passes through the air being tested and reaches the photosensor. The received light intensity will be reduced due to scattering from particles of smoke, air-borne dust, or other substances; the circuitry detects the light intensity and generates an alarm if it is below a specified threshold, potentially due to smoke. Such detectors are also known as optical detectors.

# Ionization Smoke Detector
An ionization smoke detector uses a radioisotope to ionize air. If any smoke particles enter the open chamber, some of the ions will attach to the particles and not be available to carry the current in that chamber. An electronic circuit detects that a current difference has developed between the open and sealed chambers, and sounds the alarm

# About the dataset
Collection of training data is performed with the help of IOT devices since the goal is to develop a AI based smoke detector device.
Many different environments and fire sources have to be sampled to ensure a good dataset for training. A short list of different scenarios which are captured:

Normal indoor
Normal outdoor
Indoor wood fire, firefighter training area
Indoor gas fire, firefighter training area
Outdoor wood, coal, and gas grill
Outdoor high humidity
etc.
The dataset is nearly 60.000 readings long. The sample rate is 1Hz for all sensors. To keep track of the data, a UTC timestamp is added to every sensor reading.

# Features
UTC: Time Stamp<br>
Temperature: Air Temperature<br>
Humidity%: Air Humidity<br>
TVOC[ppb]: Total Volatile Organic Compounds; measured in parts per billion<br>
eCO2[ppm]: co2 equivalent concentration; calculated from different values like TVCO<br>
Raw H2: raw molecular hydrogen; not compensated (Bias, temperature, etc.)<br>
Raw Ethanol: raw ethanol gas<br>
Pressure[hPa]: Air Pressure<br>
PM1.0: particulate matter size < 1.0 µm (PM1.0). 1.0 µm < 2.5 µm (PM2.5)<br>
PM2.5: particulate matter size < 1.0 µm (PM1.0). 1.0 µm < 2.5 µm (PM2.5)<br>
NC0.5: Number concentration of particulate matter. This differs from PM because NC gives the actual number of particles in the air<br>
NC1.0: Number concentration of particulate matter. This differs from PM because NC gives the actual number of particles in the air<br>
Number concentration of particulate matter. This differs from PM because NC gives the actual number of particles in the air<br>
CNT: Sample counter.<br>
Fire Alarm: Ground truth is "1" if a fire is there.<br>
