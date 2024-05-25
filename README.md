#
 SSR

All the work carried out on this repository was done as part of the final project for FEUP's Security of Systems and Networks course ([M.EEC047]).

## [Initial Demo](Intermediate_Presentation)

This initial Python demo is a very crude simulation of how a timing attack should work. 
Before you run this demo you should have Python installed on your PC.
To run the demo you just have to run the following command:

```python python3 Demo.py```

Please note that this demo was run on Ubuntu 22.04 on Windows you may need to increase the artificially inserted delay.


## ESP Demonstrations

All demonstrations on ESPs took place on the Windows operating system (OS), so minor adjustments may be necessary for different OSes.

The first step in carrying out these demonstrations is to have a method of communicating and sending a script to be run on the ESPs. To do this, you need to install the Arduino IDE from the following [link](https://www.arduino.cc/en/software).

After installing the Arduino IDE, we need to add the library that will enable communication with our ESP8266.

![File->Preferences->Additional boards manager URLs](Images/add_URL.png?raw=true)

Here you need to add the following link: `https://arduino.esp8266.com/stable/package_esp8266com_index.json`.


### [Timing Attack ESP-ESP via Wi-Fi](ESP-ESP_Timing_attack)

For this demonstration, you will need two 8266 ESPs.
After connecting both to the PC on different USB ports, you need to open 2 Arduino IDE apps and choose the COM that identifies each ESP: `Tools->Port`.
Then you need to compile and upload script [Attacker](ESP-ESP_Timing_attack/Attack/Attacker.ino) and [Host](ESP-ESP_Timing_attack/Host/Host.inoHost.ino) for the ESP you want to serve as the attacker and the one that will be the victim.



### [Demonstration of Spectre Attack ESP-PC](ESP-PC_Spectre_attack)

For this last demonstration, we will only need an ESP 8266 and the PC that will be connected to the AP created by this ESP. Start by compiling and uploading the [script](ESP-PC_Spectre_attack/SpectreESP.ino) to the ESP, then connect the computer to the ESP's AP, then on a browser of choice input the ESP's IP on the search bar and connect to the Webpage. After entering the Website open the browser's console to see the attack's result.



[M.EEC047]: https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=516519
