# 2 Minipulses Generator

Easy to use signal generator in Nucleo STM32 F4 xxx, that produces two width and delay variable pulses. Both values can be setted by a rotary encoder, additionaly the values are shown in a LCD display. 
This project is a cheap way to produce test signals for [TDR](https://en.wikipedia.org/wiki/Time-domain_reflectometer) implementations and [OTDR](https://en.wikipedia.org/wiki/Optical_time-domain_reflectometer)
implementations if a Optic layer is added.

## Advantages 


## Principle of function 

### Timer 

<p align="center">
	<img alt="Timer" width="430" src="">
	<img alt="Timer" width="300" src="">
</p>

### Interrupt
This project was written using the peripherals: Digital input, interrupts and timmers of **Nucleo board**, so there is not a polling routine.  
The void loop is used to refresh  the display with the value of the potentiometers.

<p align="center">
	<img alt="Nucleo pinout" width="730" src="">
</p>

### LCD Display
An LCD display model **part.number** is connected throught SPI interface with the board to ensure the user can track the delay time between the riding edge of both pulses.
<p align="center">
	<img alt="Nucleo pinout" width="730" src="">
</p>



## Breadboard
