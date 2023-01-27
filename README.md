# 2 Minipulses Generator

Easy to use _signal generator_ in Nucleo board with STM32F446RE chip, produces two **width** and **delay** variable pulses. Both values can be setted by rotary encoders, additionaly the interface and values are shown in a TFT LCD display. 
This project is a cheap way to produce test signals for [TDR](https://en.wikipedia.org/wiki/Time-domain_reflectometer) implementations and [OTDR](https://en.wikipedia.org/wiki/Optical_time-domain_reflectometer)
implementations if a Optic layer is added.

## Advantages 
Having test signals for TDR projects is not easy, beacuse you need expensive bench equipment, this idea beind this project help you creating the test signals using only one board, two rotary encoders and LCD display.  
The principle of function can be recreated almost any board with timers and interrupts, but keep in mind that the pulse width and its granularity depends on the clock frequency of the chipset, so it is highly recommended to use the fastest yet acccurate clock available in your board.

## Principle of function 
The basic idea behind this signal genarator is to map the value setted on a first rottary encoder on a pulse width using a **timer** linked to an output square waveform _a)_. The RISING EDGE of the signal will also act as an input to an **interrupt** wich triggers another timer that counts from zero to a value mapped from the second rotary encoder. Once  the timer overflows, a second output produce an indentical square waveform that the first output.

### Timer 
Every timer counts from zero to a designated value in a frequency obtained from the clock divided by a prescaler, in STM32 chipsets we can generate a PWM signal associated with those events.

<p align="center">
	<img alt="Timer" width="382" src="https://user-images.githubusercontent.com/22565959/214214673-25162a70-bec2-4fcd-b882-32467db8874a.png">
	<img alt="Timer" width="348" src="https://user-images.githubusercontent.com/22565959/215180019-97258815-aaa1-483c-9898-3a4c40a8e4a6.png">
</p>


### Interrupt
One interrupt is used 

<p align="center">
	<img alt="Nucleo pinout" width="730" src="https://user-images.githubusercontent.com/22565959/214214885-94d88550-0c6a-4726-b208-6a7802e5bbbd.png">
</p>

### LCD Display
As we discusse before, this project was written using the peripherals: Digital input, interrupts and timmers of **Nucleo board**, so there is not a polling routine.  The void loop is used to refresh  the display with the value of the potentiometers. An 3,5 inch TFT LCD display with **ILI9488** driver IC is connected throught SPI interface with the Nucleo board to ensure that users can track their setted delay and pulses width.
<p align="center">
	<img alt="Nucleo pinout" width="480" src="https://user-images.githubusercontent.com/22565959/214215515-b64c2e0b-1136-4dd1-8ae6-204e58d63ceb.png">
	<img alt="Nucleo pinout" width="220" src="https://user-images.githubusercontent.com/22565959/215190415-99fce0df-bb1e-46e6-8058-57e286c8f638.png">

</p>

## Breadboard
