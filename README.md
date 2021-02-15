# Hacking wireless doorbell with Arduino & HackRF

To complete this project I had to do the following:
- ring a doorbell and discover the radio frequency and modulation used by it
- reverse engineer the signal in order to interpret it
- build a device capable of replaying the doorbell signal 

## Arduino replay attack
At first, I had to find out what frequency the signal was on so I used SDRSharp and HackRF One to find the frequency. After that
I had to analyze signal in Audacity, write the code and create Arduino.

![alt text](https://github.com/avukov02/Hacking-Wireless-Doorbell-With-Arduino-HackRF/blob/master/arduinoattack.png)


![alt text](https://github.com/avukov02/Hacking-Wireless-Doorbell-With-Arduino-HackRF/blob/master/arduinoscheme.png)

## HackRF replay attack
I used Universal Radio Hacker to capture and replay the signal.

![alt text](https://github.com/avukov02/Hacking-Wireless-Doorbell-With-Arduino-HackRF/blob/master/hackrfreplayattack.png)


