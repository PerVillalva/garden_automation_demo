## 🌱 Self-Watering Garden Automation Project - BHCC STEM Club

The **Self-Watering Garden Automation Project** is a **project** developed by the **BHCC STEM Club** to design and implement an **automated plant watering system**. The project aims to create an efficient, **data-driven irrigation system**, starting with an **indoor prototype** before expanding to a **fully scalable outdoor solution**.

To ensure **structured development**, the project is divided into **three specialized teams**, each responsible for a particular aspect of the system:

### 🛠 **Hardware Team**

**Responsibilities:**

-   Select appropriate **sensors** (e.g., soil moisture sensors, temperature sensors) for monitoring environmental conditions.
-   Design and build **circuitry** for connecting the microcontroller, pumps, and actuators.
-   Ensure **hardware resilience** by creating a weatherproof **enclosure** for future outdoor deployment.
-   Use **Tinkercad** or similar tools for initial circuit simulations before moving to real-world assembly.

**Collaboration:**

-   Works closely with the **Embedded Systems Team** to test **sensor calibration** and ensure smooth communication between the hardware and software.

---

### 💻 **Embedded Systems Team**

**Responsibilities:**

-   Write firmware to **read sensor data** from soil moisture, humidity, and temperature sensors.
-   Develop the logic for **triggering water valves and pumps** based on sensor thresholds.
-   Optimize **power consumption** and ensure the system is **responsive and reliable**.
-   Use **Tinkercad** for simulating code before moving to real microcontrollers (e.g., Arduino, ESP32).

**Collaboration:**

-   Works closely with the **Hardware Team** to ensure accurate **sensor readings** and **hardware-software integration**.
-   Communicates with the **Database Team** to **send sensor data** for storage and further analysis.

---

### 🗄 **Database Team**

**Responsibilities:**

-   Store and manage sensor data in a **cloud database** for long-term tracking.
-   Create **real-time monitoring dashboards** for visualizing soil moisture levels, temperature trends, and system activity.
-   Implement **data logging** to analyze historical trends and improve watering efficiency.
-   Develop an **API** to allow external applications (e.g., mobile apps, web dashboards) to access the system’s data.

**Collaboration:**

-   Works with the **Embedded Systems Team** to ensure a **uninterrupted data flow** from the microcontroller to the cloud.
-   Integrates with a **Dashboard Team** (if expanded) to allow **remote monitoring and control**.

---

### 📊 **Dashboard for Remote System Monitoring**

The **dashboard** acts as the main interface for monitoring the automated garden system remotely. It allows users to:

-   View **real-time sensor data** (moisture, temperature, pump activity).
-   Receive **alerts and notifications** if soil moisture levels are too low or if system malfunctions occur.

**Collaboration:**

-   The **Database Team** sends sensor data to the dashboard for **real-time visualization**.
-   The **Embedded Systems Team** receives **adjustments based on insights** from the dashboard.

---

### 🔄 **How Everything Connects**

1. **The Hardware Team** builds the physical infrastructure and ensures sensors work correctly.
2. **The Embedded Systems Team** programs the logic for automation and sends data to storage.
3. **The Database Team** stores the collected data and enables remote access via a dashboard.
4. **The Dashboard allows users** to monitor the system health remotely.

## 🌿 Automation System Flowchart

```mermaid
graph TD;
    A[Garden Automation Project]:::project -->|Hardware Selection, Circuit Design, and System Integration| B[Hardware Team]:::team
    A -->|Automation Logic, Microcontroller Programming, and Sensor Calibration| C[Embedded Systems Team]:::team
    A -->|Data Storage, Processing, and Visualization| D[Database Team]:::team

    D -->|Continuous Data Updates| F[Dashboard for Remote System Monitoring]:::dashboard
    F -.->|System Adjustments Based on Data Insights| C:::automation
    B <-.->|Collaboration on Sensor Calibration and Hardware Testing| C:::collaboration
    C <-.->|Collaboration on Data Integration| D:::dataflow

    %% Styling Adjustments
    classDef project fill:#4682B4,stroke:#333,stroke-width:2px,color:#000;  %% Steel blue for project
    classDef team fill:#2F4F4F,stroke:#333,stroke-width:1px,color:#FFF; %% Dark slate gray for teams
    classDef automation fill:#6A5ACD,stroke:#333,stroke-width:2px,color:#000; %% Soft purple for automation logic
    classDef collaboration fill:#D2691E,stroke:#333,stroke-width:2px,color:#000; %% Muted orange for hardware-software collaboration
    classDef dataflow fill:#8B4513,stroke:#333,stroke-width:2px,color:#FFF; %% Saddle brown for data flow
```

## Group Members

-   ...
-   ...
-   ...
-   ...
