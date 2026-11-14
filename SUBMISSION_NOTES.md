# Submission preparation notes

Originals were read and copied; no commit or push was made. The reference was used for folder names and its raw .gitignore only; no reference README or application was copied.

## New code or missing task features

- 8051/CAT4/TASK4A/seg_display.c: Added missing LED actions using own CAT3 functions; retained keypad and display logic
- 8051/CAT5/TASK5A/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.1/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.2/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.3/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5C/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT6/TASK6A/taskA.c: Enable SMOD so existing FA reload gives 9600 baud at 11.0592MHz; original gives no intelligible output at required terminal setting; A transmission logic absent, reuse own uart_init
- 8051/CAT7/TASK7A/lad.c: Add HD44780 power-on 3/3/3/2 nibble sequence so LCD reliably enters four-bit mode; preserve lcd_cmd/data/delay; missing string/second-row demonstration added
- 8051/CAT7/TASK7B/lad.c: Add HD44780 power-on 3/3/3/2 nibble sequence so LCD reliably enters four-bit mode; preserve lcd_cmd/data/delay; new cursor/number demonstration
- 8051/CAT7/TASK7C/lad.c: Add HD44780 power-on 3/3/3/2 nibble sequence so LCD reliably enters four-bit mode; preserve lcd_cmd/data/delay; new movement logic uses own keypad scanner
- STM32/CAT8/TASK8B/Core/Src/main.c: Task B/C has no own implementation; retain GPIO project and add event timing in USER CODE
- STM32/CAT8/TASK8C/Core/Src/main.c: Task B/C has no own implementation; retain GPIO project and add event timing in USER CODE
- STM32/CAT9/TASK9B/Core/Src/main.c: Repair undefined UART_Transmit and unfinished assignment; use own existing transmit/receive helpers; command parser absent, add bounded line parsing and LED commands
- STM32/CAT10/TASK10B/Core/Src/main.c: Split AT command stages into standalone task; remove unrelated commented stages; B command exploration absent; C activates own station/join/CIFSR commands
- STM32/CAT11/TASK11A/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT11/TASK11B/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT11/TASK11C/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT13/TASK13/Core/Src/main.c: Split combined BME280/HTTP project; retain own Bosch wrappers and sensor setup; sensor+MQTT integration absent: combine own working sensor API and ESP library, publish live JSON
- STM32/CAT12/TASK12C/flows.json: No own Node-RED flow supplied; compute actual min/max/average from live HTTP sensor data
- STM32/CAT13/TASK13/flows.json: No own MQTT analytics flow supplied; subscribe to real JSON and calculate statistics

## Changes to existing code

- 8051/CAT4/TASK4A/seg_display.c: Added missing LED actions using own CAT3 functions; retained keypad and display logic
- 8051/CAT5/TASK5A/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.1/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.2/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5B/TASK5B.3/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT5/TASK5C/task1.c: No PWM, waveform or stepper implementation exists; new task program uses own P1^2 and timer register style
- 8051/CAT6/TASK6A/taskA.c: Enable SMOD so existing FA reload gives 9600 baud at 11.0592MHz; original gives no intelligible output at required terminal setting; A transmission logic absent, reuse own uart_init
- 8051/CAT6/TASK6B/taskA.c: Enable SMOD so existing FA reload gives 9600 baud at 11.0592MHz; original gives no intelligible output at required terminal setting
- STM32/CAT8/TASK8B/Core/Src/main.c: Task B/C has no own implementation; retain GPIO project and add event timing in USER CODE
- STM32/CAT8/TASK8C/Core/Src/main.c: Task B/C has no own implementation; retain GPIO project and add event timing in USER CODE
- STM32/CAT9/TASK9A/Core/Src/main.c: Repair undefined UART_Transmit and unfinished assignment; use own existing transmit/receive helpers
- STM32/CAT9/TASK9B/Core/Src/main.c: Repair undefined UART_Transmit and unfinished assignment; use own existing transmit/receive helpers; command parser absent, add bounded line parsing and LED commands
- STM32/CAT10/TASK10A/Core/Src/main.c: Split AT command stages into standalone task; remove unrelated commented stages
- STM32/CAT10/TASK10B/Core/Src/main.c: Split AT command stages into standalone task; remove unrelated commented stages; B command exploration absent; C activates own station/join/CIFSR commands
- STM32/CAT11/TASK11A/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT11/TASK11B/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT11/TASK11C/Core/Src/main.c: No CAT11 GPIO program exists; use own F401 generated scaffold and new USER CODE only
- STM32/CAT12/TASK12A/Core/Src/main.c: Split combined BME280/HTTP project; retain own Bosch wrappers and sensor setup; add omitted UART init call and absent measurement output
- STM32/CAT12/TASK12B/Core/Src/main.c: Split combined BME280/HTTP project; retain own Bosch wrappers and sensor setup; initialize UART omitted by original, preserve HTTP response helper, wait for complete HTTP headers
- STM32/CAT12/TASK12C/Core/Src/main.c: Split combined BME280/HTTP project; retain own Bosch wrappers and sensor setup; initialize UART omitted by original, preserve HTTP response helper, wait for complete HTTP headers
- STM32/CAT13/TASK13/Core/Inc/ESPLib.h: Portable HAL include; enlarge packet buffers to hold sensor JSON under uint8 length limit
- STM32/CAT13/TASK13/Core/Src/main.c: Split combined BME280/HTTP project; retain own Bosch wrappers and sensor setup; sensor+MQTT integration absent: combine own working sensor API and ESP library, publish live JSON
- STM32/CAT15/TASK15/Core/Src/main.c: Repair old Bosch API calls to match own supplied modern driver; add prototypes before function-pointer assignments; assignment unverified
- 8051/CAT7/TASK7A/lad.c: Preserve LCD transfer code; add reliable power-on sequence and missing task features; discard unused helpers from split copy
- 8051/CAT7/TASK7C/lad.c: Preserve LCD transfer code; add reliable power-on sequence and missing task features; discard unused helpers from split copy
- 8051/CAT7/TASK7B/lad.c: Add LCD power-on sequence, clear command, cursor and numeric update demonstration
- STM32/CAT13/TASK13/Core/Src/ESPLib.c: Prevent response underflow and receive-buffer overwrite; reject publish payload beyond library single-byte MQTT length support
- STM32/CAT10/TASK10C/Core/Src/main.c: Activate own saved station/join/CIFSR sequence verbatim, remove unused server stages rather than leave comments
- STM32/CAT10/TASK10D/Core/Src/main.c: Move own website declarations/helpers/includes and unchanged loop statements into protected USER CODE regions so required CubeMX regeneration preserves them; no application logic or MX init changes
- STM32/CAT14/TASK14/Core/Src/main.c: Add extern declaration for missing UART handle; relocate own MQTT statements into USER CODE regions for required CubeMX regeneration; no UART init fabricated and assignment still unverified

Exact before/after lines and project path changes are saved outside the repo in _submission_work/CODE_CHANGES.diff.

## NEEDS CUBEMX

- STM32/CAT10/TASK10D: IOC specifies USART1 PA9/PA10 but generated application uses USART2 PA2/PA3. In CubeMX disable USART1; enable USART2 asynchronous 115200 baud, 8 data bits, no parity, 1 stop bit, TX/RX, PA2 TX/PA3 RX; retain HSE 8MHz PLL x9 SYSCLK72MHz APB1 36MHz. Regenerate MDK-ARM with Keep User Code.
- STM32/CAT11/TASK11A: Confirm physical board MCU: own scaffold is STM32F401RBT6, paper names NUCLEO-F401RE. Select actual MCU/board in CubeMX (NUCLEO-F401RE if that is fitted), PA5 GPIO_Output push-pull/no pull/low speed initial LOW, PC13 GPIO_Input pull-up for B1 active LOW (B/C only), SYS Serial Wire, HSI16MHz PLL M=8 N=84 P=2 ->84MHz, APB1 /2 APB2 /1. Disable unused USART1 and unused external HSE pins if using HSI. MDK-ARM; Keep User Code.
- STM32/CAT11/TASK11B: Confirm physical board MCU: own scaffold is STM32F401RBT6, paper names NUCLEO-F401RE. Select actual MCU/board in CubeMX (NUCLEO-F401RE if that is fitted), PA5 GPIO_Output push-pull/no pull/low speed initial LOW, PC13 GPIO_Input pull-up for B1 active LOW (B/C only), SYS Serial Wire, HSI16MHz PLL M=8 N=84 P=2 ->84MHz, APB1 /2 APB2 /1. Disable unused USART1 and unused external HSE pins if using HSI. MDK-ARM; Keep User Code.
- STM32/CAT11/TASK11C: Confirm physical board MCU: own scaffold is STM32F401RBT6, paper names NUCLEO-F401RE. Select actual MCU/board in CubeMX (NUCLEO-F401RE if that is fitted), PA5 GPIO_Output push-pull/no pull/low speed initial LOW, PC13 GPIO_Input pull-up for B1 active LOW (B/C only), SYS Serial Wire, HSI16MHz PLL M=8 N=84 P=2 ->84MHz, APB1 /2 APB2 /1. Disable unused USART1 and unused external HSE pins if using HSI. MDK-ARM; Keep User Code.
- STM32/CAT14/TASK14: Paper missing. Own F401 IOC lists USART1 PA9 TX / PA10 RX, but main lacks generated handle and MX_USART1_UART_Init. Regenerate actual MCU with USART1 asynchronous 115200 8-N-1, TX/RX, no flow control, HSI16 PLL84MHz as original clock. Then ensure generated init is called before ESP8266_Init. Confirm assignment scope first.

## Values to confirm

- Physical 8051 crystal: original projects specify a 33 MHz simulator clock. CAT5/6 now use the paper example 11.0592 MHz assumption; timer timing and 9600 baud depend on it. Other 8051 project clocks remain unchanged.
- Circuit resistor and capacitor values are nominal suggested wiring values, not measured original components: LED 330 ohm, input pull-up 10k, I2C/P0 pull-up 4.7k and crystal capacitors 22pF. Match the physical board and crystal load.
- CAT11 scaffold is F401RB, while paper requests NUCLEO-F401RE. Confirm actual hardware and B1 polarity; prepared switch code assumes active LOW.
- CAT14/CAT15 titles and scope are unverified; dates use original file last-modified date 14/11/2026.
- TASK10D is a reference HTTP extension; no separate task title appears in supplied CAT10 paper. CAT12 A/B/C labels follow evaluator progression, not printed letters.
- CAT3 and CAT6 preserve polling logic despite interrupt wording in their papers.
- Saved Wi-Fi network strings are from the original sources. Confirm them on the test network.

## Validation limits

All 79 STM32 Core source files passed native GCC syntax checking. ARM GCC and Keil C51 were unavailable; no ARM link, target build or hardware behavior was verified. The eleven changed/new 8051 task copies intentionally have no fabricated HEX.
