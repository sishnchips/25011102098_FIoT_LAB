EXPERIMENT DETAILS
EXP: CONTINUOUS ASSESMENT 11
DATE: 14/10/2026
NAME OF EXP: STM32F401RE Cortex-M4: GPIO and User Input Programming
HARDWARE SETUP / PLATFORM: STM32F401RB development board (physical board unconfirmed) + STM32F401RBT6 + GPIO LED and input + STM32CubeMX (MDK-ARM project)
TASK 11C : Short-Press and Long-Press Detection

1. Circuit Diagram
Service the half-second blink interval while continuing to read the switch to demonstrate 11C with the shown signals.

* Microcontroller / Board: STM32F401RB development board (physical board unconfirmed) + STM32F401RBT6.
* GPIO / Peripheral pins: PC13 / GPIOC GPIO_PIN_13 -> B1 button to GND, pull-up [NEEDS CUBEMX]; PA5 / GPIOA GPIO_PIN_5 -> LED + 330 ohm to GND [NEEDS CUBEMX].
* Clock: IOC assigns HSE 25 MHz on PH0/PH1; application runs HSI 16 MHz PLL to 84 MHz.
* External components / Peripheral: B1 button to GND, pull-up [NEEDS CUBEMX]; LED + 330 ohm to GND [NEEDS CUBEMX].
* Power Supply: 3.3 V board logic, common ground; board regulator / USB supply.

![Circuit Diagram](circuit.png)

2. Core Logic / Pseudocode / Code Base
Working Principle: This USER CODE measures the interval between stable PC13 press and release events. It starts a timed PA5 blink after a long press and stops blinking with a toggle after a short press.

Pseudocode:

1. Qualify the button level with elapsed ticks.
2. Save started on a low input event.
3. Use a one-second threshold on release.
4. Service the half-second blink interval while continuing to read the switch.

Code Base:
The program is written in Embedded C using STM32 HAL (STM32CubeMX).

* `main.h` provides the project HAL declarations in this program.
* `HAL_GetTick()` returns the millisecond time used for event comparisons here.
* `HAL_GPIO_ReadPin()` reads the application switch level here.
* `HAL_GPIO_TogglePin()` changes the stored LED output state here.

3. Inference
The intended behavior combines press classification with a separate blink timer. CubeMX must supply the PA5 and PC13 GPIO setup before this loop can control a board.

NEEDS CUBEMX: Confirm physical board MCU: own scaffold is STM32F401RBT6, paper names NUCLEO-F401RE. Select actual MCU/board in CubeMX (NUCLEO-F401RE if that is fitted), PA5 GPIO_Output push-pull/no pull/low speed initial LOW, PC13 GPIO_Input pull-up for B1 active LOW (B/C only), SYS Serial Wire, HSI16MHz PLL M=8 N=84 P=2 ->84MHz, APB1 /2 APB2 /1. Disable unused USART1 and unused external HSE pins if using HSI. MDK-ARM; Keep User Code.
