# 25011102098_FIoT_LAB

## Fundamentals of Internet of Things Lab

| Field | Details |
| --- | --- |
| Student Name | Sishira A.V. |
| Registration Number | 25011102098 |

## Repository Overview

The task projects are organized from my saved lab files and the CAT papers. New missing-task code and repairs are identified in [SUBMISSION_NOTES.md](SUBMISSION_NOTES.md).

## Verification & Preparation Notes

The current repository contains 33 task projects with README files, circuit images and Keil project files. All 15 8051 tasks have HEX files, but their correspondence to the latest source has not been established. CAT10D UART configuration, CAT11 GPIO setup and CAT14 UART initialization have been corrected in source and IOC files. CAT15 was replaced with the Smart Dryer & Weather Monitoring System. Target compilation, CubeMX regeneration and hardware testing remain unverified. Confirm the physical MCU for CAT11/CAT14 and the CAT14/CAT15 assignment scope against the original papers. See [SUBMISSION_NOTES.md](SUBMISSION_NOTES.md) for historical details and current limitations.

## Repository Structure

```text
8051/
  CAT2/
    TASK2A/
    TASK2B/
    TASK2C/
  CAT3/
    TASK3A/
  CAT4/
    TASK4A/
  CAT5/
    TASK5A/
    TASK5B/TASK5B.1/
    TASK5B/TASK5B.2/
    TASK5B/TASK5B.3/
    TASK5C/
  CAT6/
    TASK6A/
    TASK6B/
  CAT7/
    TASK7A/
    TASK7B/
    TASK7C/
STM32/
  CAT8/
    TASK8A/
    TASK8B/
    TASK8C/
  CAT9/
    TASK9A/
    TASK9B/
  CAT10/
    TASK10A/
    TASK10B/
    TASK10C/
    TASK10D/
  CAT11/
    TASK11A/
    TASK11B/
    TASK11C/
  CAT12/
    TASK12A/
    TASK12B/
    TASK12C/
  CAT13/
    TASK13/
  CAT14/
    TASK14/
  CAT15/
    TASK15/
```

## Continuous Assessment Index

- [8051/CAT2](8051/CAT2/README.md): 8051 Tool Chain setup – Development Board – AT89S52.
- [8051/CAT3](8051/CAT3/README.md): Timer-Based LED Pattern Generator and Button Interrupt Controller.
- [8051/CAT4](8051/CAT4/README.md): Human-Machine Interface using Matrix Keypad, LEDs, and Seven-Segment Display.
- [8051/CAT5](8051/CAT5/README.md): Hardware Timer and Interrupt-Based Timing for LED Fading, Pulse Generation, and Stepper Motor Control.
- [8051/CAT6](8051/CAT6/README.md): UART Driver and Serial Debugging.
- [8051/CAT7](8051/CAT7/README.md): 16×2 LCD Driver Development and Dynamic Display Control.
- [STM32/CAT8](STM32/CAT8/README.md): STM32 GPIO Bring-Up and Switch-Controlled LED.
- [STM32/CAT9](STM32/CAT9/README.md): STM32 UART Command Controlled LED.
- [STM32/CAT10](STM32/CAT10/README.md): STM32–Wemos Wi-Fi Modem Interface Using AT Commands.
- [STM32/CAT11](STM32/CAT11/README.md): STM32F401RE Cortex-M4: GPIO and User Input Programming.
- [STM32/CAT12](STM32/CAT12/README.md): Sensor Interfacing(BME280) – STM32(Debug) – ESP8266(Wi-Fi) HTTP – Node Analytics.
- [STM32/CAT13](STM32/CAT13/README.md): Sensor Interfacing(BME280) – (MQTT) – Node Analytics.
- [STM32/CAT14](STM32/CAT14/README.md): CAT14 paper not supplied.
- [STM32/CAT15](STM32/CAT15/README.md): Smart Dryer & Weather Monitoring System (assignment paper not supplied).
