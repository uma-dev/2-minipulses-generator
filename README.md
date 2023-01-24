# 2 Minipulses Generator

Easy to use signal generator in Nucleo STM32 F4 xxx, that produces two width and delay variable pulses. Both values can be setted by a rotary encoder, additionaly the values are shown in a LCD display. 
This project is a cheap way to produce test signals for [TDR](https://en.wikipedia.org/wiki/Time-domain_reflectometer) implementations and [OTDR](https://en.wikipedia.org/wiki/Optical_time-domain_reflectometer)
implementations if a Optic layer is added.

## Advantages 


## Principle of function 

### Timer 

<p align="center">
	<img alt="Timer" width="430" src="https://user-images.githubusercontent.com/22565959/214214673-25162a70-bec2-4fcd-b882-32467db8874a.png">
	<img alt="Timer" width="300" src="">
</p>

### Interrupt

This project was written using the peripherals: Digital input, interrupts and timmers of **Nucleo board**, so there is not a polling routine.  
The void loop is used to refresh  the display with the value of the potentiometers.

<p align="center">
	<img alt="Nucleo pinout" width="730" src="https://user-images.githubusercontent.com/22565959/214214885-94d88550-0c6a-4726-b208-6a7802e5bbbd.png">
</p>

### LCD Display
An 3,5 inch TFT LCD display with **ILI9488** driver IC is connected throught SPI interface with the Nucleo board to ensure that users can track their setted delay and pulses width.
<p align="center">
	<img alt="Nucleo pinout" width="300" src="https://user-images.githubusercontent.com/22565959/214215515-b64c2e0b-1136-4dd1-8ae6-204e58d63ceb.png">
</p>



## Breadboard
