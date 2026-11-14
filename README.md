# 25011102098_FIoT_LAB

## Fundamentals of Internet of Things Lab

| Field | Details |
|---|---|
| Student Name | Sishira A.V. |
| Registration Number | 25011102098 |
| Course | 25CS2741 - Fundamentals of Internet of Things + Lab |
| Institution | Shiv Nadar University Chennai |
| Programme | B.Tech CSE (IoT) |
| Semester | III |

## Repository Overview

This repository contains laboratory experiments involving 8051 and STM32 microcontrollers, embedded C programming, peripheral interfacing, wireless communication, sensor data acquisition and IoT analytics using Node-RED.

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
    TASK5B/
      TASK5B.1/
      TASK5B.2/
      TASK5B.3/
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
  CAT11/
    TASK11A/
    TASK11B/
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

### 8051 Experiments

- [CAT2](8051/CAT2/README.md): 8051 Tool Chain Setup - Development Board - AT89S52.
- [CAT3](8051/CAT3/README.md): Timer-Based LED Pattern Generator and Button Interrupt Controller.
- [CAT4](8051/CAT4/README.md): Human-Machine Interface using Matrix Keypad, LEDs and Seven-Segment Display.
- [CAT5](8051/CAT5/README.md): Hardware Timer and Interrupt-Based Timing for LED Fading, Pulse Generation and Stepper Motor Control.
- [CAT6](8051/CAT6/README.md): UART Driver and Serial Debugging.
- [CAT7](8051/CAT7/README.md): 16x2 LCD Driver Development and Dynamic Display Control.

### STM32 Experiments

- [CAT8](STM32/CAT8/README.md): STM32 GPIO Bring-Up and Switch-Controlled LED.
- [CAT9](STM32/CAT9/README.md): STM32 UART Command Controlled LED.
- [CAT10](STM32/CAT10/README.md): STM32-Wemos Wi-Fi Modem Interface Using AT Commands.
- [CAT11](STM32/CAT11/README.md): HTTP Server - STM32-Wemos Wi-Fi Modem Using AT Commands.
- [CAT12](STM32/CAT12/README.md): STM32F401RE Cortex-M4: GPIO and User Input Programming.
- [CAT13](STM32/CAT13/README.md): Sensor Interfacing (BME280) - STM32 (Debug) - ESP8266 (Wi-Fi) HTTP - Node Analytics.
- [CAT14](STM32/CAT14/README.md): MQTT Client Publishing and Node-RED Integration.
- [CAT15](STM32/CAT15/README.md): Smart Dryer and Weather Monitoring System.

## Tools and Technologies

- Keil uVision
- STM32CubeMX
- Embedded C
- STM32 HAL
- UART and I2C
- ESP8266 / Wemos D1 Mini
- BME280 Environmental Sensor
- HTTP and MQTT
- Node-RED
- OpenWeather API

## Verification Notes

Experiment files have been reorganized and documented. Target compilation and hardware execution remain to be verified where applicable.

The current 8051 HEX files have not been verified against the latest source. CubeMX regeneration, official assignment numbering and requirements, and physical MCU compatibility remain to be confirmed. Live Node-RED integration and hardware behavior have not been independently verified.
