Overview

FortiLocker is an ARM7 LPC2129-based bank locker security system that provides secure access through Two-Factor Authentication (2FA). The system verifies the user using a password and a One-Time Password (OTP) sent via a GSM module.

Features

* Password-based authentication using a 4x4 keypad
* OTP generation and verification
* GSM-based SMS notification using SIM900
* Two-Factor Authentication (2FA)
* LCD display for user interaction
* Buzzer alert for invalid access attempts
* DC motor-based locker control
* Automatic system lock after three incorrect password attempts
* SMS alert for unauthorized access attempts

 Hardware Components

* LPC2129 ARM7 Microcontroller
* 4x4 Matrix Keypad
* 16x2 LCD Display
* SIM900 GSM Module
* DC Motor
* Buzzer
* Motor Driver Circuit
* Power Supply Unit

 Software Requirements

* Keil µVision
* Embedded C
* Flash Magic

 Working Principle

1. System initializes all peripherals.
2. User enters the password through the keypad.
3. Password is verified by the LPC2129.
4. If the password is correct, an OTP is generated.
5. OTP is sent to the registered mobile number via GSM.
6. User enters the received OTP.
7. OTP is verified by the controller.
8. If OTP is correct, the locker is opened using the DC motor.
9. After a predefined time, the locker is closed automatically.
10. If the password or OTP is incorrect, the buzzer is activated.
11. After three incorrect password attempts, the system is locked and an alert SMS is sent.

 Block Diagram

4x4 Keypad
|
v
+------------------+
| LPC2129 ARM7 MCU |
+--+----+----+-----+
|    |    |
|    |    +------> DC Motor
|    |
|    +-----------> Buzzer
|
+--> LCD Display
|
+--> SIM900 GSM
|
v
OTP SMS

 Applications

* Bank Locker Security
* Smart Safe Lockers
* Office Security Systems
* Home Security Lockers
* Access Control Systems
