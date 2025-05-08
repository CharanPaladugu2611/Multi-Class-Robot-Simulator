# 🤖 Multi-Class Robot Simulator

In this project, we built a C++ simulation framework for diverse mobile robot types, each with unique locomotion strategies. The system models aerial, aquatic, legged, and wheeled robots — each extending from a base ```MobileRobot class``` — and integrates sensor feedback and battery management to simulate realistic robot behavior.

From flying drones that take off and land, to underwater bots that dive and surface, and robots that kick, brake, and recharge — this system captures diverse robotic interactions within a unified, extensible OOP architecture.

## 🧱 Core Classes & Behaviors
* ```MobileRobot```:
Abstract base class containing position, orientation, battery, and speed logic. All robots inherit from this.

* ```AerialRobot```:
Takes off, lands, rotates, and simulates altitude-based flight with charging triggers.

* ```AquaticRobot```:
Dives and surfaces based on fins, with time-based simulation and battery discharge.

* ```WheeledRobot ```:
Accelerates, decelerates, and brakes with speed constraints and wheel-based attributes.

* ```LeggedRobot```:
Kicks, jumps, and rotates — motion is scaled by leg strength and height.

* ```Sensor```:
Aggregated into robots, simulates data reading over time (e.g., temperature, pressure, etc.)

* ```Battery```:
Supports model-specific charging/discharging behavior and recharge delay logic.

## ⚙️ How It Works
Each robot implements its own version of the move() and rotate() methods. Robots perform actions based on internal state and constraints, such as:

* Low battery → triggers recharge

* Altitude or depth → controls duration of flight/dive

* Desired speed → triggers acceleration or deceleration
  
* Leg strength or height → influences movement energy

Robots print detailed status reports, including position, battery state, and current action status.

## 🛠 Technologies Used
* 🧠 C++ (Object-Oriented Programming)

* 🧮 STL: vectors, threads, chrono, math

* 🔋 Custom battery logic

* 🧪 Threaded simulation of real-time behaviors (sleep/delay)

* 🧼 Clear separation between headers and source files

