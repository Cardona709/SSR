# SSR

All the work carried out on this repository was done as part of the final project for FEUP's Security of Systems and Networks course ([M.EEC047]).

## [Initial Demo](Intermediate_Presentation)

This initial python demo is a very crude simulation of how a timing attack should work. 
Before you run this demo you should have python installed in your PC.
To run the demo you just have to run the following command:

```python python3 Demo.py```

Please note that this demo was run on Ubuntu 22.04 on Windows you may need to increase the artificially inserted delay.


## ESP Demonstrations

All demonstrations on ESPs took place on the Windows operating system (OS), so minor adjustments may be necessary for different OSes.

The first step in carrying out these demonstrations is to have a method of communicating and sending a script to be run on the ESPs. To do this, you need to install the Arduino IDE from the following [link](https://www.arduino.cc/en/software).

After installing the arduino, we need to add the library that will enable communication with our ESP8266.

![File->Preferences->Additional boards manager URLs](https://imgur.com/a/ZDsGyHd)

Here you need to add the following [link](https://arduino.esp8266.com/stable/package_esp8266com_index.json).


### [Timing Attack ESP-ESP via Wi-Fi](ESP-ESP_Timing_attack)




### [Demonstration of Spectre Attack ESP-PC](ESP-PC_Spectre_attack)





[M.EEC047]: https://sigarra.up.pt/feup/en/UCURR_GERAL.FICHA_UC_VIEW?pv_ocorrencia_id=516519
