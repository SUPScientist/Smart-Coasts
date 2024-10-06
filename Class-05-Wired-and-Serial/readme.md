# Lab 5
## Two-Way Serial Communications

This week's lab focuses on two-way serial communications. Specifically, we will use one Argon to send data using UART and we will use another Argon to receive that data and acknowledge receipt.

## Breadboard setup
**CRITICAL SAFETY MESSAGE**: *for your and the electronics' safety, do not change circuitry while the board is powered! Instead, always disconnect your power supply (either battery or USB cable) before changing anything on the breadboard. Don't touch positive and ground wires/pins to each other directly or via breadboard connections (i.e., "short circuit").*

This exercise requires two teams, each with their own Argon. One team will be the transmitter and the other will be the receiver. To receive full credit, regardless of team, the transmission and receipt of data must be achieved. 

Three wire connections should be used. First, "share" the ground between the two devices by using a jumper wire from ground of Transmitter Argon to the ground of Receiver Argon. Next, connect the relevant UART pins. Read the documentation at https://docs.particle.io/reference/device-os/api/serial/serial/ to learn more about UART code and wiring. **Hint: Pay special attention to `Serial1` as this is what we will use.**

## Lab Exercise
Large teams: two teams of two. Both teams should immediately begin coding their respective devices and not wait for the other team to think they're ready. Note that many details for execution are left out of these instructions and must be found on the web, especially through Particle's documentation.  
1. Team 1, or Team Transmitter, should write code to have their Argon transmit data over UART (specifically `Serial1`) in the `loop()` function. Every time it sends data, it should blink the LED on for 500 ms, then turn it back off. It should send data every 2 seconds. (HINT: look up the `delay()` function to configure your device's timing).
2. Team 2, or Team Receiver, should write code to have their Argon receive data from Transmitter Argon using Team Receiver Argon's UART (i.e., also their `Serial1`). Upon receiving data from Transmitter Argon, Receiver Argon should print the data to the serial monitor (i.e., they should use a `Serial.println([BLANK])` where `[BLANK]` will be replaced by the appropriate code corresponding to data coming from Transmitter Argon.
3. Successful execution of the full project will result in one Argon that is blinking an LED every 2 seconds for 500 ms and sending data to another Argon which is displaying those data on the second Argon's serial monitor (Team Receiver's computer screen) every two seconds.
4. Team 1/Team Transmitter: create a GitHub repository. Push to it your entire Particle project as well as your circuit diagram. Add a README.md file to the main repository/folder that describes what we can find in the repo (e.g., code and a circuit diagram) and provides instructions on how to build the circuit. For instructions, you may copy and paste from these notes as long as you reference this repository (note that the [repository's license](../LICENSE.txt) is very permissive). 
5. Team 2/Team Receiver: fork the repository, add your code (the entire Particle project) to it, and submit a pull request to have Team 1 pull the changes. Make sure you also update the readme so that it clearly distinguishes between the two folders corresponding to Team 1's transmission code and Team 2's receiver code.
6. Each team member: submit a link to your full, final GitHub repo in Canvas.