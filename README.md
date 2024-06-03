# LaneVac
This project involves developing a prototype for an automated road-cleaning vacuum.
Components Required:-
1. Arduino UNO
2. L298 Motor Driver set
3. Rain water sensor
4. 12V Power Adapter
5. Female Jack
6. 12V DC Fan
7. LEDs
8. Breadboard
   
Theory:-
First provide 12V to the L298 Motor Driver using the 12V adapter. The L298 Motor Driver has two ports to enable two motors simultaneously. But in this project we need to power 1 motor so we need one port for it. Furthermore, we need to provide 5V from the driver to the Arduino UNO. So the Arduino controls most of the operation by the use of a toggle switch. The rain sensor is also connected to the analog pin of Arduino UNO. Till now, the major limitation of the project has been the potential damage to the circuit if water enters the vent. To mitigate this issue, we have employed a servo motor and a rain sensor. When water droplets fall on the rain sensor, it measures the intensity and relays a signal to the Arduino Uno. Subsequently, the Arduino sends a signal to the servo motor, which acts as a latch for the vent. If the measured value exceeds a predetermined threshold, the servo motor engages, closing the vents. After a certain period, the rain sensor rechecks for water presence. If it is still raining, the vents remain closed. If the rain has ceased, the vents open again. Thus, this mechanism focuses on safeguarding the circuit. Looking towards the future, we aim to enhance the project to not only protect the circuit but also effectively drain water from the roads using a radial drainage system. The integration involves connecting the control mechanism for the radial drainage system with the Arduino Uno and the rain sensor circuit. This integration enables the system to respond to rainfall and drain the collected water accordingly. Here is a step-by-step breakdown of its operation. When the rain sensor detects water, it triggers the circuit to close the vents, thereby protecting the circuit from potential damage. Simultaneously, the control mechanism receives the signal from the rain sensor and initiates the closure of the drainage openings. This prevents water from entering the system and instead diverts it to the collection points. The water accumulates in the storage tank until the rain subsides or reaches a predefined level. Once the rain stops or the water level decreases below a specific threshold, the control mechanism opens the drainage openings, facilitating the flow and drainage of water from the roads.

Pin Configuration:-
Arduino 5V Power Pin and Ground Pin are connected to the power rails of the breadboard.
Arduino Digital Pin 2 is connected to terminal 2 of the switch 2.
Terminal 1 of switch 2 is connected to Ground.
Arduino Digital Pin 4 is connected to terminal 2 of switch 1
Terminal 1 of switch 1 is connected to Ground.
Arduino Digital Pin 12 is connected to the Anode of Green LED.
Cathode of Green LED is connected to Ground.
Both the anodes of the LEDs are connected to the ground through 1kΩ resistors each.
Arduino Digital Pin 13 is connected to the Anode of Red LED.
Cathode of Red LED is connected to Ground.
Power 1 Pin and Power 2 Pin of the L293D are connected to the Positive Supply of 5V.
Ground Pin of L293D is connected to Ground.
Input 1 of L293D is connected to Digital Pin 8.
Input 2 of L293D is connected to Digital Pin 7.
Enable 1 & 2 Pin is connected to Digital Pin 11.
Output 1 Pin & Output 2 Pin are connected to the terminals of the DC Motor.
Arduino Code
