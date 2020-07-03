# work-status-indicator
workstatusindicator is a Particle Photon-based IoT device for displaying work status. When working from home, sometimes it's important for other members of the household to know whether the person working from home is in a meeting, working but does not want to be disturbed, or is available. The workstatusindicator uses a Particle Photon to control an industrial tower lamp to display the worker's status as red, yellow, or green. Since the Photon use's wifi to connect to the home wifi network, the lamp can be placed anyplace where there is a wifi signal. The circuit is easy to build and the software is straightforward. The status can be changed with the Particle app (Android or iOS), from the command line of a Linux or Mac using the CURL command or via Python. 

## How it works
workstatusindicator uses a simple C program to monitor the state of the worker via Particle cloud functions and variables. When a function to change the color of tower lamp is called, workstatusindicator turns off the lamp LEDs for current color and turns on the lamp LEDs for the new status. 
The overall wiring for the workstatusindicator hardware is shown in the [Photon-Work-Status-Light-Schematic.pdf](https://github.com/makeralchemy/work-status-indicator/blob/master/Photon-Work-Status-Light-Schematic.pdf)

## Getting Started
These instructions will show how to setup and use the workstatusindicator. Understanding how to use the Particle web IDE is assumed. Instructions for using the Particle Web IDE can be found [here](https://docs.particle.io/tutorials/developer-tools/build/).

### Parts Required
- 1 Particle Photon WiFi Development Board
- 2 Pin headers
- 1 LTV-847 Optocoupler. 
- 1 16-pin IC socket (optional depending on how comfortable you are directly soldering ICs)
- 3 Resistors (180 Ohm)
- 1 [Adafruit](https://www.adafruit.com/) Perma-Proto Half-sized Breadboard PCB (Product ID: (1609)[https://www.adafruit.com/product/1609])
- 1 USB Power Supply with micro USB cable
- 1 12VDC 1Amp Power Supply
- Hookup wire (green, yellow, red, and black)

### Assembly Instructions
Details to be added
The wiring diagram for the circuit board is shown in the [Photon-Work-Status-Light-Circuit-Board-Layout.pdf](https://github.com/makeralchemy/work-status-indicator/blob/master/Photon-Work-Status-Light-Circuit-Board-Layout.pdf)

### Installing the Software
Details to be added

## Using the work status indicator
The status can be changed one of three ways:
- Via the command line using the CURL command
- Via Python
- Via the Particle app

### CURL
The *curl* folder contains bash shell scripts that use the CURL command to change the color illuminated by the tower lamp. 
The JSON output returned from the Particle cloud after executing the request is displayed after the command completes.
The shell scripts must be edited before running them:
- *bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb* must be replaced by your Particle authorization token which can be found in Particle IDE.
- *dddddddddddddddddddddddd* must be replaced by the device id for the Photon running the workstatusindicator firmware. The device ID can also be found in the Particle IDE.

The shell scripts provided are:
- *get-last-status.sh* displays the penultimate status
- *get-version.sh* displays the version of the workstatusindicator firmware
- *get-work-status.sh* displays current status being displayed by the lamp  
- *set-status-available.sh* will turn the lamp color to green  
- *set-status-working.sh* will turn the lamp color to yellow  
- *set-status-in-meetings.sh* will turn the lamp color to red 
- *set-status-off.sh* will turn off the lamp 

Executing the set-status-in-meetings script and it's output would look like:
```
$ ./set-status-in-meetings.sh
{"id":"dddddddddddddddddddddddd","connected":true,"return_value":0}
```
Executing the get-work-status script and it's output would look like:
```
$ ./get-work-status.sh
{"cmd":"VarReturn","name":"work_status","result":"In Meetings","coreInfo":{"last_heard":"2020-07-03T04:40:58.413Z","connected":true,"last_handshake_at":"2020-06-28T18:56:57.474Z","deviceID":"dddddddddddddddddddddddd","product_id":6}}
```

### Python
The *python* folder contains Python programs that can used to change the color illuminated by the tower lamp. 
The HTTP request return code and the JSON output returned from the Particle cloud after executing the request is displayed after the command completes.
The Python programs must be edited before running them:
- *bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb* must be replaced by your Particle authorization token which can be found in Particle IDE.
- *dddddddddddddddddddddddd* must be replaced by the device id for the Photon running the workstatusindicator firmware. The device ID can also be found in the Particle IDE.

The Python programs provided are:
- *get-last-status.py* displays the penultimate status
- *get-version.py* displays the version of the workstatusindicator firmware
- *get-work-status.py* displays current status being displayed by the lamp  
- *set-status-available.py* will turn the lamp color to green  
- *set-status-working.py* will turn the lamp color to yellow  
- *set-status-in-meetings.py* will turn the lamp color to red 
- *set-status-off.py* will turn off the lamp 

Executing the set-status-working Python program and it's output would look like:
```
$ python set-status-working.py
200
{"id":"dddddddddddddddddddddddd","connected":true,"return_value":0}
```
Executing the get-work-status Python Program and it's output would look like:
```
$ python get-work-status.py
200
{"cmd":"VarReturn","name":"work_status","result":"Working","coreInfo":{"last_heard":"2020-07-03T04:46:02.576Z","connected":true,"last_handshake_at":"2020-06-28T18:56:57.474Z","deviceID":"dddddddddddddddddddddddd","product_id":6}}
```

### Particle App
The work status can be changed in the Particle app by selecting the Photon running the workstatusindicator code and going to the functions tab.
Selecting on the one of the functions will change which color is illuminating on the tower lamp:
- *available* will turn the lamp color to green
- *working* will turn the lamp color to yellow
- *in_meetings* will turn the lamp color to red
- *off* will turn off the lamp

<table>
<tr><td>
<img src="https://raw.githubusercontent.com/makeralchemy/work-status-indicator/master/particle-app-functions.png" alt="Particle App Functions" width="400"/>
</td></tr>
</table>

The work status can be seen in the Particle app by selecting the Photon running the workstatusindicator code and going to the variables tab.
The current values of the variables are displayed:
- *last_status* is the penultimate status
- *version* is the version of the workstatusindicator firmware
- *work_status* is the current status being displayed by the lamp

<table>
<tr><td>
<img src="https://raw.githubusercontent.com/makeralchemy/work-status-indicator/master/particle-app-variables.png" alt="Particle App Variables" width="400"/>
</td></tr>
</table>

## License

This project is licensed under the MIT license.
