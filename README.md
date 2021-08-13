# Robot Pioneer 3-AT and ARIA
---

This repository contains some examples of using the Pioneer 3-AT with [ARIA library](https://github.com/srmq/ARIA).

<div align="center">
<img src="/Images/robot.png" width="300" height="250" alt="robot" />
</div>

+ **Call_ARIA_Function**: Demonstrate how to create ARIA classes and functions and use the robot to realize tasks. 

+ **Manual_Drive**: Manual control of the robot using the keyboard. 

+ **Manual_Automatic_Drive**: Control the robot in manual and automatic form. When you use the manual control, you can drive the robot using the keyboard, and when you press the letter **a** in the terminal, the code switches to automatic control.

## How to Use:

+ Dependences (mandatory):
    + **ARIA**
    + Connect robot to USB port

+ Download any folder and open a terminal _`ctrl+t`_:
    ```
    $ cd path 
    $ mkdir build & cd build 
    $ cmake .. 
    $ make
    ```
+ Run
    ```
    $ ./manual_drive -rp /dev/ttyUSB0
    ```

## NOTE:

| If you find any of these codes helpful, please share my __[GitHub](https://github.com/LuisOrtizF)__ and __*STAR*__ :star: this repository to help other enthusiasts to find these tools. Remember, the knowledge must be shared. Otherwise, it is useless and lost in time. |
| :----------- | control the robot in manual and automatic form. When you use the manual control, you can drive the robot using the keyboard, and when you press the letter **a** in the terminal, the code switches to automatic control.