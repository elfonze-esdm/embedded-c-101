# DAC (Digital to Analog Converter)

A Digital-to-Analog Converter (DAC) is a device that converts a digital signal into an analog signal. The input signal to a DAC is typically a sequence of binary values that represent the amplitude of a digital signal at different points in time. The output of a DAC is a continuous analog signal that can be used to drive an analog device, such as a speaker or motor.

## DAC Square

When the digital input signal to a DAC is a square wave, the resulting analog output signal will be a waveform that alternates between two voltage levels, corresponding to the high and low levels of the square wave. This waveform will have a constant amplitude and a frequency that is equal to the frequency of the square wave input signal.

One application of DACs with square wave input signals is in pulse-width modulation (PWM), a technique used to control the power output of devices such as motors, LED lights, and audio amplifiers. By varying the duty cycle of a square wave input signal to a DAC, the resulting analog output signal can be used to control the amount of power delivered to a device, thereby allowing for precise control of its output.

## DAC Triangle

When a Digital-to-Analog Converter (DAC) is fed with a digital input signal in the form of a triangle wave, the resulting analog output signal will be a waveform that rises and falls linearly between two voltage levels, corresponding to the peaks of the triangle wave.

The frequency of the resulting analog signal will be the same as that of the triangle wave input signal, and the amplitude of the output signal will depend on the voltage levels of the digital input signal.

DACs with triangle wave input signals are used in a variety of applications, including waveform generation for audio and video signals, and in motor control systems where a smooth analog signal is required to control the speed and position of a motor. The linear nature of the triangle wave output signal makes it well-suited for these applications, as it provides a smooth and continuous signal that can be easily processed by analog circuits.

## About the example

### DAC square.cpp

C program written for an LPC1768 microcontroller to generate an analog signal using a digital-to-analog converter (DAC) and a timer. Here's a breakdown of what the code does:

The program includes the header file "lpc17xx.h", which provides access to the LPC1768's hardware registers.

Two functions are defined: "initTimer0()" and "delayMS(unsigned int milliseconds)".

The "main()" function begins by calling "SystemInit()", which sets up the microcontroller's clock and PLL configuration.

"initTimer0()" is then called to initialize Timer0, which will be used to create a delay in "delayMS()".

The PINSEL1 register is set so that pin P0.26 is configured for the AOUT function. This pin will output the analog signal generated by the DAC.

The program enters an infinite loop that repeatedly generates a sawtooth wave using the DAC.

Inside the loop, a for-loop increments the binary value used for the DAC conversion from 0 to 1022, setting the DACR register with a 10-bit binary value shifted left by 6.

Then, another for-loop decrements the binary value used for the DAC conversion from 1023 to 1, again setting the DACR register with a 10-bit binary value shifted left by 6.

The "delayMS()" function is used to provide a delay between changes in the DAC value. It uses Timer0 to wait for the specified number of milliseconds.

The program repeats this process indefinitely.

### DAC triangle.cpp

A C code sample for an LPC1768 microcontroller. It includes two functions, initTimer0() and delayMS(), and a main() function that uses the two functions.

The initTimer0() function initializes Timer 0 with a 1ms period. It does this by setting the Clock/Timer Control Register (CTCR) to 0x0 to use Timer mode, setting the Prescale Register (PR) to 25000-1 to divide the clock frequency by 25000, and setting the Timer Control Register (TCR) to 0x02 to reset the timer.

The delayMS() function waits for a specified number of milliseconds using Timer 0. It does this by resetting the timer and enabling it, waiting in a loop until the timer counter reaches the desired delay, and then disabling the timer.

The main() function initializes Timer 0 using initTimer0(). It then selects the analog output (AOUT) function for pin P0.26 using the PINSEL1 register. The function then enters an infinite loop that uses a for loop to output a ramp signal on the DAC (Digital-to-Analog Converter) using values from 0 to 1023 and then back down to 0. The delay between each value output is currently commented out, so it will run as fast as possible.

This code is intended to be used with an oscilloscope to observe the ramp signal output on pin P0.26. The CRO positive probe should be connected to pin P0.26, and the CRO negative probe should be connected to ground.
