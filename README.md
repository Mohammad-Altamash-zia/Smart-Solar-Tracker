# ☀️ Single-Axis Smart Solar Tracker

A hardware prototype designed to maximize the energy efficiency of solar panels. Unlike static panels that lose potential power as the light source moves, this system actively monitors its environment and physically reorients itself to ensure peak light absorption.

## 🚀 Demo
[Demo link](https://www.linkedin.com/posts/mohammad-altamash-zia-398a9a301_robotics-arduino-embeddedsystems-ugcPost-7478041985174573056-JwGU/?utm_source=share&utm_medium=member_desktop&rcm=ACoAAE05pqQBWP28VEA7EOhHNlAFtzIjqFqSsP8)

## 🛠️ Hardware Stack
*   **Microcontroller:** Arduino Uno
*   **Sensors:** 2x Light Dependent Resistors (LDRs)
*   **Actuator:** SG90 Micro Servo Motor
*   **Power Supply:** 7.4V Li-ion Battery Pack (2S)
*   **Circuitry:** 2x 10K Resistors, Breadboard, Jumper Wires

## ⚡ Engineering Note: Circuitry & Control Logic

**The Voltage Divider:**
To convert the changing physical light intensity into readable data, the two LDRs are paired with two 10K resistors to create a standard voltage divider circuit. The LDRs are powered directly from the Arduino's 5V pin. As light hits the LDRs, their resistance changes, allowing the Arduino to read varying analog voltage signals.

**Power Distribution:**
To ensure a stable system, a 2S Li-ion battery pack is used to power both the Arduino and the SG90 servo motor. The USB cable is kept plugged in exclusively to monitor serial data for debugging purposes.

**The Control Loop:**
The Embedded C/C++ code continuously compares the analog readings from the left and right LDRs. If one sensor detects a higher light intensity, the microcontroller calculates the difference and commands the servo to tilt the panel toward the stronger light source until both sensors read an equal value (equilibrium). 

## 💻 Software Stack
*   **Embedded C/C++:** Runs on the Arduino IDE to handle analog sensor parsing, the comparative control loop, and servo PWM signaling.

## ⚙️ How to Run the Project
1.  **Hardware Assembly:** Mount the LDRs on opposite sides of the solar panel. Connect the servo signal pin to a PWM-enabled digital pin on the Arduino. 
2.  **Circuit Setup:** Wire the LDRs and 10K resistors into a voltage divider configuration connected to the Arduino's Analog pins (e.g., A0 and A1). 
3.  **Upload:** Open the `Smart_Solar.ino` file in the Arduino IDE, compile, and upload it to the Arduino Uno.
4.  **Debug:** Open the Serial Monitor to view the raw LDR values and observe the control loop in action.

## 👨‍💻 About the Developer
**Mohammad Altamash Zia** 
Computer Science Engineering (Class of 2028) at Invertis University. 
Documenting my journey of bridging software and the physical world through Robotics, IoT, and Embedded Systems.
