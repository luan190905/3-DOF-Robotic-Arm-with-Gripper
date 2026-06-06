# ESP32-Based Teach-and-Repeat Robotic Arm

## Overview

This project presents a 3-DOF robotic arm with a servo-driven gripper, controlled by an ESP32 microcontroller and four 180° servo motors.

The robotic arm supports both manual control and automatic playback. Users can control each joint and the gripper through a web-based interface, record motion sequences, and replay the recorded actions automatically.

The system demonstrates the implementation of embedded control, web-based human-machine interaction, and a Teach-and-Repeat robotic automation method commonly used in industrial applications.

---

## Project Demonstration

### Robotic Arm Prototype

![Robotic Arm](images/search.jpg)

### Web Control Interface

![Web Interface](images/web_interface.jpg)

### Motion Recording and Playback

![Motion Playback](images/playback_demo.jpg)

### System Architecture

![System Architecture](images/system_architecture.png)

---

## Key Features

- 3 Degrees of Freedom (3-DOF)
- Servo-Driven Gripper
- Four 180° Servo Motors
- ESP32-Based Embedded Control
- Web-Based User Interface
- Real-Time Joint Control
- Motion Recording Function
- Automatic Motion Playback
- Teach-and-Repeat Operation
- Wi-Fi Communication
- Expandable System Architecture

---

## Hardware Components

- ESP32 Development Board
- 3 × 180° Servo Motors for Arm Joints
- 1 × 180° Servo Motor for Gripper
- Robotic Arm Structure
- External Power Supply
- Wi-Fi Network

---

## Software Technologies

- Embedded C / Arduino Framework
- ESP32 Web Server
- HTML
- CSS
- JavaScript
- PWM Servo Control
- Motion Recording Algorithm
- Wi-Fi Communication

---

## System Architecture

```text
Web Browser
      │
      ▼
ESP32 Web Server
      │
      ▼
Motion Controller
      │
 ┌────┼────┬────┐
 ▼    ▼    ▼    ▼
Base Shoulder Elbow Gripper
Servo  Servo   Servo  Servo
```

---

## Control Modes

### 1. Manual Control Mode

Users connect to the ESP32 web interface through a browser.

The interface allows independent control of:

- Base rotation
- Shoulder joint
- Elbow joint
- Gripper open/close

All servo positions are updated in real time.

---

### 2. Motion Recording Mode

During manual operation, every movement is recorded sequentially.

The system stores:

- Base servo angle
- Shoulder servo angle
- Elbow servo angle
- Gripper state
- Motion sequence order

This allows the robotic arm to learn a complete task directly from user demonstrations.

---

### 3. Automatic Playback Mode

After recording, the robotic arm can automatically reproduce the stored sequence.

The arm executes every recorded movement in the original order without user intervention.

This functionality implements a simple Teach-and-Repeat robotic control system.

---

## Working Principle

1. User accesses the web interface.
2. User manually controls the robotic arm.
3. Servo positions and gripper actions are recorded.
4. Motion data is stored in memory.
5. Playback mode is activated.
6. The robotic arm automatically repeats the demonstrated task.

---

## Applications

- Pick-and-Place Systems
- Educational Robotics
- Industrial Automation Demonstrations
- Smart Manufacturing Research
- Embedded Systems Training
- Robotics Learning Platforms

---

## Project Highlights

- Designed and built a robotic arm with three motion joints and a servo-driven gripper.
- Developed a web-based control interface for real-time robotic operation.
- Implemented a Teach-and-Repeat system capable of recording and replaying user demonstrations.
- Integrated ESP32 Wi-Fi communication and PWM-based servo control.
- Demonstrated automated pick-and-place operations using recorded motion sequences.
- Created a low-cost robotic automation platform for education and research purposes.

---

## Future Improvements

- Save motion sequences to Flash Memory
- EEPROM-Based Data Storage
- Inverse Kinematics Implementation
- Object Detection Using OpenCV
- YOLO-Based Object Recognition
- Automatic Object Tracking
- Mobile Application Control
- ROS2 Integration
- MQTT-Based Remote Monitoring

---

## Repository Structure

```text
ESP32-Based-Teach-and-Repeat-Robotic-Arm/
│
├── README.md
│
├── src/
│   └── main.ino
│
├── web/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── images/
│   ├── robotic_arm.jpg
│   ├── web_interface.jpg
│   ├── playback_demo.jpg
│   └── system_architecture.png
│
└── docs/
```

---

## Skills Demonstrated

- Embedded Systems Development
- ESP32 Programming
- Servo Motor Control
- PWM Signal Generation
- Web-Based Device Control
- Human-Machine Interface (HMI)
- Wireless Communication
- Robotics Fundamentals
- Motion Recording and Playback
- System Integration

---

## Author

Le Van Luan

Electronics Engineering | Embedded Systems | IoT | Robotics | Computer Vision
