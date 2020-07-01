# work-status-indicator
workstatusindicator is a Particle Photon-based IoT device for displaying work status. When working from home, sometimes it's important for other members of the household to know whether the person working from home is in a meeting, working but does not want to be disturbed, or is available. The workstatusindicator uses a Particle Photon to control an industrial tower lamp to display the worker's status as red, yellow, or green. Since the Photon use's wifi to connect to the home wifi network, the lamp can be placed anyplace where there is a wifi signal. The circuit is easy to build and the software is straightforward. The status can be changed with the Particle app (Android or iOS), from the command line of a Linux or Mac using the CURL command or via Python. 

## How it works
workstatusindicator uses a simple C program to monitor the state of the worker via Particle cloud functions and variables. When a function to change the color of tower lamp is called, workstatusindicator turns off the lamp LEDs for current color and turns on the lamp LEDs for the new status. 

## Getting Started
These instructions will show how to setup and use the workstatusindicator. Understanding how to use the Particle web IDE is assumed. Instructions for using the Particle Web IDE can be found [here](https://docs.particle.io/tutorials/developer-tools/build/).

### Parts Required
- 1 Particle Photon WiFi Development Board
- 2 Pin headers
- 1 LTV-847 Optocoupler
- 3 Resistors (180 Ohm)
- 1 # Adafruit Perma-Proto Half-sized Breadboard PCB - Product ID:  1609
- USB Power Supply with micro USB cable
- 12VDC 1Amp Power Supply
- Hookup wire

### Assembly Instructions
To be added

### Installing the Software
To be added

## Using the work status indicator
The status can be changed one of three ways:
- Via the command line using the CURL command
- Via Python
- Via the Particle app

### CURL

### Python

### Particle App

## License

This project is licensed under the MIT license.
