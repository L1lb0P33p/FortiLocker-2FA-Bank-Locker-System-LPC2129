# FortiLocker-2FA-Bank-Locker-System-LPC2129
FortiLocker is an ARM7 LPC2129-based secure bank locker access control system that uses Two-Factor Authentication (Password + OTP) for enhanced security. The system integrates a 4x4 keypad, 16x2 LCD, SIM900 GSM module, buzzer, and DC motor to provide secure locker access, OTP verification, intrusion alerts, and automated locker operation.
✔ Password Authentication
✔ OTP Verification using GSM SIM900
✔ Two-Factor Authentication (2FA)
✔ 4x4 Matrix Keypad Interface
✔ 16x2 LCD Display
✔ Intrusion Detection Alert
✔ Buzzer Security Alarm
✔ DC Motor Based Locker Control
✔ 3 Wrong Attempts Protection
✔ SMS Alert on Unauthorized Access
✔ ARM7 LPC2129 Microcontroller

Working Principle
Step 1: System Initialization
LPC2129 initializes LCD, Keypad, GSM module, Buzzer, and Motor.
Project title "FORTILOCKER" is displayed on the LCD.
Step 2: Password Authentication
User enters a 4-digit password using the keypad.
LCD displays * instead of actual digits.
If password is incorrect:
Attempt count increases.
Remaining attempts are displayed.
Buzzer sounds.
Step 3: OTP Generation
If the password is correct:
LPC2129 generates a 4-digit OTP.
OTP is sent to the registered mobile number via SIM900 GSM.
Step 4: OTP Verification
User enters the received OTP.
System compares entered OTP with generated OTP.
Step 5: Access Granted
If OTP matches:
LCD displays "ACCESS GRANTED".
DC motor rotates to unlock the locker.
After a predefined time, the motor rotates back to lock the locker.
Step 6: Security Protection
If OTP is incorrect:
Buzzer activates for 10 seconds.
If password is entered incorrectly three times:
LCD displays "TRY AFTER 24 HRS".
Alert SMS is sent.
System enters lock mode.


                 +------------------+
                 |  4x4 KEYPAD      |
                 +--------+---------+
                          |
                          v
+------------------------------------------------+
|            LPC2129 ARM7 CONTROLLER             |
|                                                |
|  Password Verification                         |
|  OTP Generation                                |
|  Access Control Logic                          |
+----+------------+------------+------------+----+
     |            |            |            |
     v            v            v            v

+---------+  +---------+  +---------+  +---------+
|  LCD    |  | SIM900  |  | BUZZER  |  | DC MOTOR|
| Display |  |   GSM   |  | Security|  | Locker  |
| Status  |  |  Module |  |  Alert  |  | Control |
+---------+  +---------+  +---------+  +---------+
