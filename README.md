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

 Step 1: System Initialization
  - LPC2129 initializes the LCD, Keypad, GSM module, Buzzer, and DC Motor.
  - The project title **"FORTILOCKER"** is displayed on the LCD.

 Step 2: Password Authentication
  - The user enters a 4-digit password using the 4x4 keypad.
  - The LCD displays `*` characters instead of the actual password digits.
  - The entered password is compared with the stored password.
  - If the password is incorrect:
  - The attempt counter is incremented.
  - The remaining attempts are displayed on the LCD.
  - The buzzer is activated as a warning.

Step 3: OTP Generation and Transmission
  - If the password is correct:
  - The LPC2129 generates a random 4-digit OTP.
  - The OTP is sent to the registered mobile number through the SIM900 GSM module.
  - The LCD displays **"OTP SENDING"**.

 Step 4: OTP Verification
- The user enters the received OTP through the keypad.
- The system compares the entered OTP with the generated OTP.
- Access is granted only if both OTPs match.

 Step 5: Locker Access Control
- If OTP verification is successful:
  - The LCD displays **"ACCESS GRANTED"**.
  - The DC motor rotates in the forward direction to unlock the locker.
  - The locker remains open for a predefined duration.
  - The DC motor then rotates in the reverse direction to lock the locker automatically.
  - The LCD displays **"LOCKER CLOSED"**.

 Step 6: Security Protection
- If an incorrect OTP is entered:
  - The LCD displays **"INVALID OTP"**.
  - The buzzer is activated for 10 seconds.

- If an incorrect password is entered:
  - The system displays the number of remaining attempts.
  - The buzzer is activated.

- After three consecutive incorrect password attempts:
  - The LCD displays **"TRY AFTER 24 HRS"**.
  - An alert SMS is sent to the registered mobile number.
  - The buzzer is activated.
  - The system enters lock mode to prevent unauthorized access.

 Applications

* Bank Locker Security
* Smart Safe Lockers
* Office Security Systems
* Home Security Lockers
* Access Control Systems
