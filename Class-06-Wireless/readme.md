# Lab 6
This week's lab borrows heavily from a "how-to" guide written for a low-cost water level sensor that interfaces with a Particle Boron. The Particle Boron is very similar to the Argon, except that it has the ability to send data over cellular networks rather than over WiFi.

## Lab exercise
Complete the [Getting Started with Cell-Enabled Water Level Sensing exercise](https://github.com/COAST-Lab/Open-Water-Level/blob/main/Firmware/Getting_Started%20with%20Cell-Enabled%20Water%20Level%20Sensing.md). Read but do not execute steps that we have done in prior labs in this class (e.g., learn how to use Particle Workbench and VS Code, learn how to blink an LED). When you get to the new material, read closely, and pay special attention to code/VS Code settings that look like they might be specific to the Particle Boron. As one immediate example, anywhere that the exercise notes linked above tell you to configure VS Code to use a Particle Boron, change to use your Particle Argon.

Some soldering will also be required. This will take place in another laboratory with a subset of the team, and rotating to give everyone an opportunity to practice soldering skills (perhaps not all today, but all by the end of the semester!)

## Submission
This week's code is mostly written for you; however, it is much more complex than other code we have utilized. As such, this week's submission is to be a flowchart created in computer software of your choosing (e.g., powerpoint, google slides, etc.) that documents your understanding of how the firmware operates. Specifically, we have learned that Particle code first executes the `setup()` function and then moves onto the `loop()` function indefinitely. Draw this, and then what steps happen inside the `loop()` function with a modest* amount of detail (*by modest, we mean that it would be insufficient to say only that it enters a so-called `DATALOG_STATE` and then a `PUBLISH_STATE`, etc., but nor is it necessary to describe every line of code in detail; describe the major steps that you can see in the code). Some googling/chatgpting/careful reading will be required to understand the code chunks. 

Break it up among team members to understand smaller chunks (maybe a dozen to a couple dozen lines of code that look like they're focused on one function) and then come back to piece your understanding together.

## Extra Credit
For extra credit, submit an Issue in GitHub in [the main repository for the code we're using](https://github.com/COAST-Lab/Open-Water-Level/) that first states that the water level monitoring code does not work for the Argon, and then in subsequent posts details what needs to be changed in the script to make it work on the Argon.