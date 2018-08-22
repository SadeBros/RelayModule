# RelayModule Library for Arduino
![RelayModule](Photos/RelayModule.gif)<br><br><br>

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
## 1. Adding RelayModule Library to the Arduino Libraries Folder
After downloading RelayModule folder, you should place it to the **libraries** folder which should be located in the Arduino folder.
<br>
<br>
For me, this libraries folder is located in: <br>
**/Users/safakakinci/Documents/Arduino/libraries/RelayModule** <br>
![Adding_RelayModule_Library](Photos/Adding_RelayModule_Library_To_The_Arduino_Libraries_Folder.png)<br><br><br>
<br><br><br>
## 2. Importing RelayModule Library to the Arduino Project Source Code
On the menu bar, you are going to see **Include Library** which is located under the **Sketch** tab.<br>
Click **RelayModule** which is at the bottom of **Include Library** pane.<br>

![Importing_RelayModule_Library](Photos/Importing_RelayModule_Library_To_The_Arduino_Source_Code.png)<br><br><br>


After clicking it, those two lines below automatically will be added to the source code.<br>
![Importing_RelayModule_Library](Photos/Importing_RelayModule_Library_To_The_Arduino_Source_Code_2.png)<br><br><br>

## 3. How to use RelayModule Library ?
### 3.1 Creating RelayModule Instance
`RelayModule module(4, LOW);`<br>
We have specified that there are **4 relays** on this Relay Module and it is working with **LOW** logic.<br>
Working with **LOW logic** specifies that **relays will be activated** when `digitalWrite(pin, LOW)` is executed.<br>
<br>
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

### 3.3 All Functions of RelayModule

<table>
    <tr>
        <th width=30%><b>Functions</b></th>
        <th width=40%><b>Explanation</b></th>
        <th><b>Example</b></th>
    </tr>
    <tr>
        <td> module( channelNumber, logic ); </td>
        <td> Initiates the relay module. </td>
        <td> module( 4 , LOW );<br> It is 4 channel relay module which is working with LOW logic. </td>
    </tr>
    <tr>
        <td> module.active( relayNumber ); </td>
        <td> Activates the relay.</td>
        <td> module.active(3);<br>Activates the third relay. </td>
    </tr>
    <tr>
        <td> module.activeAll(); </td>
        <td> Activates all relays on the Relay Module.</td>
    </tr>
    <tr>
        <td> module.deactive( relayNumber ); </td>
        <td> Deactivates the relay.</td>
        <td> module.deactive(1);<br>Deactivates the first relay. </td>
    </tr>
    <tr>
        <td> module.deactiveAll(); </td>
        <td> Deactivates all relays on the Relay Module. </td>
    </tr>
    <tr>
        <td> module.getStatus(); </td>
        <td> Returns the status of relays as integer. </td>
        <td> Status: 7 <br> 7 = 0 + 4 + 2 + 1 <br> Specifies that Relay 1,2, 3 are active and Relay4 is deactive. </td>
    </tr>
    
</table>

## 4 Talk Is Cheap, Show Me The Code
![RelayModuleExample](Photos/Talk_Is_Cheap_Show_Me_The_Code.png)<br><br><br>

