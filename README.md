# 🚗 IoT-Integrated Smart Rover With Live Surveillance

An Arduino-based smart robotic car capable of performing multiple autonomous and manual operations including:

* 🔍 Obstacle Avoidance
* 🛣️ Line Following
* 📱 Bluetooth Manual Control
* 📹 Live Video Surveillance using ESP32-CAM

This project demonstrates embedded systems integration, robotics automation, and IoT-based surveillance using low-cost and efficient hardware components.

---

# 👨‍💻 Team Members

* Palkrutwar Onkar Ravikiran (350)
* MD. Rehan MD. Gous (357)
* Suryawanshi Shubham Satish (371)
* Hage Prem Dnyaneshwar (376)

🎓 **School of Computer Engineering**
📚 **AY 2025-26**

### 👩‍🏫 Project Guide

Mrs. Rohini Banait

---

# 📌 Introduction

This project involves developing an Arduino-controlled smart rover with four major functionalities:

✅ Line Following
✅ Obstacle Avoidance
✅ Bluetooth Remote Control
✅ Live Video Streaming using ESP32-CAM

The robot uses IR sensors for line tracking and ultrasonic sensors for obstacle detection.
An HC-05 Bluetooth module allows wireless manual control through a smartphone, while the ESP32-CAM module streams live video over Wi-Fi.

The Arduino UNO acts as the central controller managing sensors, motors, and communication modules.

---

# ❗ Problem Statement

Traditional remote-controlled cars rely completely on manual operation and lack intelligent automation features. Existing autonomous robotic systems are often expensive and complex for beginners.

This project aims to develop an affordable and efficient Arduino-based smart rover integrating:

* IR Sensors for line following
* Ultrasonic Sensor for obstacle detection
* Bluetooth module for remote control
* ESP32-CAM for live surveillance

This provides a beginner-friendly and educational robotics platform for learning automation and IoT concepts.

---

# 🎯 Objectives

* Develop a smart rover with multiple operating modes
* Implement:

  * 🛣️ Line Following
  * 🚧 Obstacle Avoidance
  * 📱 Bluetooth Control
  * 📹 Live Surveillance
* Integrate Arduino UNO, sensors, Bluetooth, and ESP32-CAM
* Design a low-cost and expandable robotic system
* Achieve real-time response and efficient navigation

---

# 🌍 Applications

* 🤖 Educational Robotics
* 🚔 Surveillance Vehicles
* 📦 Delivery Systems
* 🌐 IoT Prototypes
* 🔬 Research and Experimentation

---

# ⚙️ Features

## 🛣️ Line Following Mode

The robot follows a predefined path using IR sensors.

## 🚧 Obstacle Avoidance Mode

Ultrasonic sensors detect nearby obstacles and automatically avoid collisions.

## 📱 Bluetooth Control Mode

Users can manually control the rover using a mobile Bluetooth controller app.

## 📹 Live Video Surveillance

ESP32-CAM streams real-time video over Wi-Fi to any browser.

---

# 🧠 Working Algorithm

1. Initialize Arduino UNO, sensors, Bluetooth module, motor driver, and ESP32-CAM.
2. Start video streaming using ESP32-CAM.
3. Select operating mode:

   * Line Following
   * Obstacle Avoidance
   * Bluetooth Control
4. Read sensor values continuously.
5. Execute movement based on selected mode.
6. Detect and avoid obstacles automatically.
7. Stream live video continuously.
8. Repeat until stopped.

---

# 🔩 Hardware Components

| Component                   | Description          |
| --------------------------- | -------------------- |
| Arduino UNO                 | Main controller      |
| IR Sensors                  | Line detection       |
| Ultrasonic Sensor (HC-SR04) | Obstacle detection   |
| HC-05 Bluetooth Module      | Wireless control     |
| ESP32-CAM                   | Live video streaming |
| L298N Motor Driver          | Motor control        |
| DC Motors & Wheels          | Robot movement       |
| Li-ion Battery              | Power supply         |

---

# 💻 Software Requirements

* Arduino IDE
* Embedded C/C++
* Bluetooth Controller App
* Serial Monitor

---

# 🧰 Technologies Used

* Arduino Programming
* Embedded Systems
* IoT
* Robotics
* Sensor Integration
* Wi-Fi Video Streaming

---

# 📂 Project Structure

```bash
Sy-Minor-Project/
│
├── code/
│   └── robot_car.ino
│
├── videos/
│   └── working_demo.mp4
│
├── ppt/
│   └── Final_Review_Project_implementation.pptx
│
├── images/
│   └── rover_image.jpg
│
└── README.md
```

---

# ▶️ How to Run the Project

1. Open Arduino IDE
2. Upload the `.ino` file to Arduino UNO
3. Connect all sensors and modules properly
4. Pair HC-05 Bluetooth module with mobile
5. Open ESP32-CAM stream IP in browser
6. Select operating mode
7. Run the robot 🚀

---

# 📸 Project Demo

🎥 Demo videos are available in the `videos/` folder.

📑 Presentation PPT is available in the `ppt/` folder.

---

# 🔮 Future Scope

* ☁️ Cloud-based IoT integration
* 🧠 AI-based object detection
* 📍 GPS navigation
* 📡 Mobile application integration
* 🤖 Advanced autonomous navigation

---

# 📚 References

* Arduino UNO Documentation
* HC-SR04 Ultrasonic Sensor Datasheet
* L298N Motor Driver Documentation
* HC-05 Bluetooth Module Guide
* ESP32-CAM Documentation

---

# 🙏 Acknowledgement

We sincerely thank our guide **Mrs. Rohini Banait** and the **School of Computer Engineering** for their valuable support and guidance throughout the project.

---

# ⭐ Thank You

If you like this project, give it a ⭐ on GitHub!
