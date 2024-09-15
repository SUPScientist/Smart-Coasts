# Lecture 3
Today's lecture is dedicated to learning about your parameters and sensors of interest.

# Lab Notes
## From now on...
**All code and other design files for this class must be tracked using git and uploaded to GitHub**. This will allow for real-time collaboration across your teams, file sharing for open science/engineering, and the creation and curation of a portfolio that you can show potential employers or graduate advisors. Not all companies and grad programs utilize git/GitHub, but many will be very impressed if you bring this skillset.

## Code Structure
### Background
Particle hardware runs C++ and, more specifically, a type of C++ that originated from Arduino's Wiring language. Arduino is a very powerful ecosystem of hardware (e.g., development boards that you can buy), firmware (the Wiring language is also sometimes referred to as "Arduino"), and software (Arduino provides a program you can download for coding, compiling, and flashing, called the Arduino IDE (integrated development environment)). Our versions are: hardware (Particle Argon), firmware (Particle's Device OS), and software (Microsoft's VS Code with Particle's Workbench extension). Because Particle's Device OS firmware (code) is so close to Arduino's Wiring firmware, we can often find solutions to our code-based issues by looking up solutions to Particle or Arduino. 

### Structure
Your code, which is in the your_project_name/src folder in a file named your_project_name.cpp, starts with a bunch of header information and global variables (variables that can be accessed throughout the entire code). This is followed typically by a `void setup()` code chunk and then by a `void loop()` code chunk. `setup()` executes (runs) once every time the device wakes up, is powered, or flashed with new code. The code then enters the `loop()` which it continues running indefinitely (or until it crashes). 

By the way, anything preceded by a `//` is considered a comment and is not compiled/executed, so you can use this to make notes to yourself, which is a VERY wise practice as you will frequently forget why you did something/what you intended it to do.

Let's examine the [Blink_LED script](../Class-01-Intro/Blink_LED.cpp) together for some examples.

### Frequently Used Code
There are a few things that we are using quite regularly in our header information, so get used to copying and pasting them from old to new projects every time. From the [Blink_LED script](../Class-01-Intro/Blink_LED.cpp), these are 
```
/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

// The following line is optional, but recommended in most firmware. It
// allows your code to run before the cloud is connected. In this case,
// it will begin blinking almost immediately instead of waiting until
// breathing cyan,
SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);
```

Note that the stuff at the very top preceded by the `/*` and then `*` on each line of text is a comment block, so you can fill in that section with your info so that you remember some key details from class to class and project to project.

As mentioned in [Class 1 Notes](../Class-01-Intro/readme.md), we are using `SYSTEM_MODE(SEMI_AUTOMATIC);` to take partial control of the wireless connectivity parts of the code that are buried under the layer of code that we are writing (more on this in a moment). If we didn't take this partial control, the Particle device might try to connect to the internet via WiFi (e.g., Argon) or cellular (e.g., Boron) before it lets us do anything we want (like blink an LED). This would be especially problematic if the internet connection didn't work, so we take control to prevent this. What it means to say "buried under the layer of code that we are writing" is that Particle's Device OS (or Arduino's Wiring) are powerful for a wide range of users because they don't force us to write code that executes at the lowest level (closest to the microcontroller). Instead, there is a low layer of code upon which Device OS and Wiring are built that operate the microcontroller so that we can focus on higher level tasks. 

An analog for this is with personal vehicles. There are so many parts of vehicle operation that human drivers (high-level) don't need to think about because there are lower level systems taking care of this for us, so we can focus on accelerating, braking, and steering (pro tip: don't text while driving). For example, you don't have to worry about how fuel is injected into the engine and how much air is allowed to mix with it because your car's low-level systems handle this. The critical thing to note about this way of operation is that it means that there are things happening "under the hood" on our microcontrollers, too, so we sometimes have to manually deactivate or take control of certain elements. It might also mean that we don't have access to the full power of the microcontroller on our board if the low-level code doesn't make it accessible to us. However, it's an extremely beneficial element because it allows us to focus on big tasks rather than every minute detail about how those tasks are execute.

## Hardware
We'll discuss this in more detail later in the semester, but it is at this point useful to examine the key parts and functions of our boards. Whenever you feel these class notes are lacking and you need more info, turn first to the [Particle documentation website](https://docs.particle.io/) which has tons of information about the Particle hardware, firmware, and software. For now, we'll briefly examine what is referred to as the Argon's pinout, which shows us core functions of buttons and connectors on the board and what all the stuff on the pins on the sides of the board is capable of.

![Particle Argon microcontroller pinout](../assets/images/Argon%20Pinout.png "Argon pinout")

## Lab Exercise
Today's lab is designed to take a small step forward with Particle coding and to combine it with last week's GitHub introduction. 

Form teams of two. Work together on all of the following steps, but have a different person lead each step using their own GitHub account.
- Person 1: Create a GitHub repository for your LED blinking code from last class. Commit your code and push it to the main branch of the repository.
- Person 2: Fork the repository created by Person 1. Create a branch called "SOS." Begin working on (i.e., "check out" that branch). Change the code to make the LED blink out an "SOS" signal. Look up Morse code if needed. (Hint: there may be (definitely is!!) example code out there on the web already; you would likely have to modify it for your microcontroller, but may not have to write all of it yourself). Commit changes to your new branch as appropriate. Once the SOS code is fully functional, create a Pull Request (PR) on the original repository. 
- Person 1: Review the PR and merge it into your main repository's main branch if appropriate.