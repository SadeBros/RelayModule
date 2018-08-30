# Table of contents
0. [What is RelayModule Library? If I use it, how easier life will be ?](#title0)
1. [Adding RelayModule Library to the Arduino Libraries Folder](#title1)
2. [Importing RelayModule Library to the Arduino Project Source Code](#title2)
3. [How to use RelayModule Library ?](#title3)
      1. [Creating RelayModule Instance](#title3sub1)
      2. [Setting Pins and Modes of Relays](#title3sub2)
      3. [All Functions of RelayModule](#title3sub3)
4. [Talk Is Cheap, Show Me The Code](#title4)

# RelayModule Library for Arduino
![RelayModule](Photos/RelayModule.gif)<br><br><br>

<a name="title0"></a>
## O. What is RelayModule Library? If I use it, how easier life will be ? 
If you have made some Arduino project with Relay Modules, you probably wrote some **scattered code** for relays.<br>

**Scattered Code Example 1:** You should initalize all the pins and modes for each relay.<br>

    //Those below codes will help you to see how bad and untidy the code looks.
    int Relay1 = 5;
    int Relay2 = 4;
    int Relay3 = 3;
    int Relay4 = 2;
    pinMode(Relay1, OUTPUT);
    pinMode(Relay2, OUTPUT);
    pinMode(Relay3, OUTPUT);
    pinMode(Relay4, OUTPUT);
**Scattered Code Example 2:** You should know *logic type* of the Relay Module.<br>
**"When a relay is activated?"** question will give the answer about *logic type.*<br>
If a relay is activated with `digitalWrite(pin, LOW)`, that means Relay Module is working with **LOW** logic.<br>

    //As an example, if you want to activate all relays on the Relay Module, you should write:
    digitalWrite(Relay1, LOW);
    digitalWrite(Relay2, LOW);
    digitalWrite(Relay3, LOW);
    digitalWrite(Relay4, LOW);
**Scattered Code Example 3:** <br>
What if you have 8 Relay Module, you must do all the above stuffs for each relay.<br>
What if you are working with more than one Relay Module, how many relay numbers will be waiting you to initalize them?<br>
The more relay you have, the more scattered your source code will be.<br><br>

## If I use it, how easier life will be ?
RelayModule Library will help you to write **neat code** for relay modules.<br>
It will reduce the confusion and enhance the code readability .<br>
You can create RelayModule instance in your Arduino source code, and **initalize each relay easily.**<br>
Without thinking about "**Should I write LOW or HIGH to activate it?**", you will make relays activate or deactivate easily.<br>
<br>
<br>
<a name="title1"></a>
## 1. Adding RelayModule Library to the Arduino Libraries Folder
After downloading RelayModule folder, you should place it to the **libraries** folder which should be located in the Arduino folder.
<br>
<br>
For me, this libraries folder is located in: <br>
**/Users/safakakinci/Documents/Arduino/libraries/RelayModule** <br>
![Adding_RelayModule_Library](Photos/Adding_RelayModule_Library_To_The_Arduino_Libraries_Folder.png)<br><br><br>
<br><br><br>
<a name="title2"></a>
## 2. Importing RelayModule Library to the Arduino Project Source Code
On the menu bar, you are going to see **Include Library** which is located under the **Sketch** tab.<br>
Click **RelayModule** which is at the bottom of **Include Library** pane.<br>

![Importing_RelayModule_Library](Photos/Importing_RelayModule_Library_To_The_Arduino_Source_Code.png)<br><br><br>


After clicking it, those two lines below automatically will be added to the source code.<br>
![Importing_RelayModule_Library](Photos/Importing_RelayModule_Library_To_The_Arduino_Source_Code_2.png)<br><br><br>

<a name="title3"></a>
## 3. How to use RelayModule Library ?
<a name="title3sub1"></a>
### 3.1 Creating RelayModule Instance
`RelayModule module(4, LOW);`<br>
We have specified that there are **4 relays** on this Relay Module and it is working with **LOW** logic.<br>
Working with **LOW logic** specifies that **relays will be activated** when `digitalWrite(pin, LOW)` is executed.<br>
<br>
<a name="title3sub2"></a>
### 3.2 Setting Pins and Modes of Relays
**module** which we have created above(3.1) has 4 relays. We should set pin number and pin mode for each relay.<br>
As an example, look at the figure below! **Arduino Uno and 4 Relay Module are connected.**<br>
![Arduino_Uno_4_RelayModule_Example](Photos/Arduino_Uno_and_4Relay_Module.png)<br>
<br>
If we have those connections, we need to set the Relay Module's pins as:<br>
`module[1].setPinNumber(5).setPinMode(OUTPUT);` &nbsp;&nbsp;&nbsp;&nbsp;1st relay **(IN1)** is connected to the Arduino's **Digital5** pin. Green.<br>
`module[2].setPinNumber(4).setPinMode(OUTPUT);` &nbsp;&nbsp;&nbsp;&nbsp;2nd relay **(IN2)** is connected to the Arduino's **Digital4** pin. Brown.<br>
`module[3].setPinNumber(3).setPinMode(OUTPUT);` &nbsp;&nbsp;&nbsp;&nbsp;3rd relay **(IN3)** is connected to the Arduino's **Digital3** pin. Yellow.<br>
`module[4].setPinNumber(2).setPinMode(OUTPUT);` &nbsp;&nbsp;&nbsp;&nbsp;4th relay **(IN4)** is connected to the Arduino's **Digital2** pin. Orange.<br>

`module[1].setPinNumber(5).setPinMode(OUTPUT);` <br>
**module[1]** specifies the module's first relay. (Be careful not try to reach first relay with **module[0]** )<br>
**setPinNumber(5)** specifies that relay is connected with Arduino's **Digital5** pin.<br>
**setPinMode(OUTPUT)** specifies that Arduino's **Digital5** pin will be used on **OUTPUT** mode.<br>
<br>
<a name="title3sub3"></a>
### 3.3 All Functions of RelayModule

| Functions  &nbsp; &nbsp; &nbsp;  | Example  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| Explanation  |
|--------------------------------------- | :---------------------: | :-----------:    |
| ` module(channelNumber, logic);`          |    RelayModule module(4,LOW);           |     It is **4 channel relay module** which is working with **LOW logic**. |  
| ` module.activate(relayNumber);`          |    module.activate( 1 ) ;                             |     Activates the **first relay (IN1)**.  | 
| ` module.activateAll();`                               |    module.activateAll();                         |     Activates all relays on the Relay Module.  |
| ` module.deactivate(relayNumber);`      |    module.deactivate( 4 ) ;                         |     Deactivates the **fourth relay. (IN4)**  |
| ` module.deactivateAll();`                           |    module.deactivateAll( ) ;                   |     Deactivates all relays on the Relay Module. |
|` module.getStatus();`                                    |    module.getStatus( ) ;                        |     Status: 7 <br> 7 = 0 + 4 + 2 + 1 <br> Specifies that Relay **1,2, 3 are active** and Relay4 is deactive.  |
|` module[relayNumber].getStatus();`     |    module[3].getStatus( ) ;                       |     Returns the status of **third relay (IN3)** as integer.  |


<a name="title4"></a>
## 4. Talk Is Cheap, Show Me The Code
![RelayModuleExample](Photos/Talk_Is_Cheap_Show_Me_The_Code.png)
<br><br><br>

