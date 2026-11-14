# TASK14 – MQTT Client Publishing & Node-RED Integration

## Experiment Details

| Field | Details |
|---|---|
| Assessment | Continuous Assessment 14 |
| MCU target | STM32F401RBT6 (ARM Cortex-M4) |
| Wi-Fi module | ESP8266 |
| Development tools | STM32CubeMX, Keil MDK-ARM |
| Communication | USART1, TCP/IP, MQTT |

## Aim

Configure the STM32 and ESP8266 as an MQTT publisher to send a text message periodically to an MQTT broker and configure a Node-RED subscriber to receive it.

## 1. Hardware Setup and Circuit Diagram

| STM32 pin | ESP8266 connection |
|---|---|
| PA9 (USART1_TX) | RX |
| PA10 (USART1_RX) | TX |
| GND | GND |

Use a suitable 3.3 V supply for the ESP8266 and a common ground. USART1 is configured for 115200 baud, 8 data bits, no parity and 1 stop bit. The project system clock is configured for 84 MHz.

![Circuit Diagram](circuit.png)

## 2. Working Principle

The STM32 communicates with the ESP8266 using the ESP library. The firmware establishes a TCP connection to the MQTT broker, connects an MQTT client and publishes the message repeatedly.

| MQTT parameter | Value |
|---|---|
| Broker | broker.emqx.io |
| Port | 1883 |
| Topic | stm32/data |
| Message | Good Morning |
| QoS | 0 |
| Delay between publish calls | 1000 ms |

Configure Wi-Fi credentials locally before running the project. The public broker and shared topic are intended for a demonstration; do not transmit private data.

## 3. Pseudocode

1. Initialize HAL, system clock, GPIO and USART1.
2. Initialize the ESP8266 in station mode.
3. Connect to the configured Wi-Fi network.
4. Open a TCP connection to the MQTT broker on port 1883.
5. Configure the MQTT client and connect to the broker.
6. Publish `Good Morning` to `stm32/data` with QoS 0.
7. Wait 1000 ms and repeat.

### Core Code

```c
while (1)
{
    MQTT_publishTopic("stm32/data", "Good Morning", QoS0);
    HAL_Delay(1000);
}
```

## 4. Node-RED Subscriber Setup

1. Add an MQTT In node and configure the server as `broker.emqx.io` with port `1883`.
2. Set the subscription topic to `stm32/data` and QoS to 0.
3. Connect the MQTT In node to a Debug node.
4. Deploy the flow and observe the debug sidebar.

Expected output after a successful connection: `Good Morning` approximately once per second. A dashboard text widget may also be connected to display the message.

These are subscriber setup instructions; live Node-RED execution is not demonstrated by the files in this task.

## 5. Inference

MQTT enables lightweight publish-subscribe communication between embedded devices and applications such as Node-RED. The publisher sends messages to a broker without needing a direct connection to the subscriber. Successful reception depends on Wi-Fi connectivity, broker access and matching topic configuration.

## Project Files

- [Main firmware](Core/Src/main.c)
- [ESP and MQTT library](Core/Src/ESPLib.c)
- [Library header](Core/Inc/ESPLib.h)
- [STM32CubeMX configuration](lab%2013.ioc)
- [Keil project](MDK-ARM/lab%2013.uvprojx)
- [Circuit diagram](circuit.png)
