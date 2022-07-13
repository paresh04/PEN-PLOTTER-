char datap;
#include <dummy.h>
#include <Arduino.h>
#include <stdint.h>
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
#include "Wire.h"
SCMD myMotorDriver;
void setup()
{
Serial.begin(9600);
}
void loop()
#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
{
 if (Serial.available())
   {
    datap = Serial.read();
    Serial.println(datap);
    }
 if (datap=='1')
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Starting sketch.");
//** Configure the Motor Driver's Settings **//
// .commInter face is I2C_MODE
myMotorDriver.settings.commInterface = I2C_MODE;
// set address if I2C configuration selected with the config jumpers
myMotorDriver.settings.I2CAddress = 0x5D; //config pattern is "1000" (default) on board for address 0x5D
// set chip select if SPI selected with the config jumpers
myMotorDriver.settings.chipSelectPin = 10;
//**initialize the driver get wait for idle**//
while ( myMotorDriver.begin() != 0xA9 ) //Wait until a valid ID word is returned
{
Serial.println( "ID mismatch, trying again" );
delay(500);
}
Serial.println( "ID matches 0xA9" );
// Check to make sure the driver is done looking for peripherals before beginning
Serial.print("Waiting for enumeration...");
while ( myMotorDriver.ready() == false );
Serial.println("Done.");
Serial.println();
//**Set application settings and enable driver**//
//Uncomment code for motor 0 inversion
//while( myMotorDriver.busy() );
//myMotorDriver.inversionMode(0, 1); //invert motor 0
//Uncomment code for motor 1 inversion
while ( myMotorDriver.busy() ); //Waits until the SCMD is available.
myMotorDriver.inversionMode(1, 1); //invert motor 1
while ( myMotorDriver.busy() );
myMotorDriver.enable(); //Enables the output driver hardware
}
void main()
{
 SCMD myMotorDriver;
//bottom horizontal right to left (point 1 to 2)
myMotorDriver.setDrive( LEFT_MOTOR, 0 , 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);
//top to bottom right vertical (point 2 to 3)
myMotorDriver.setDrive( LEFT_MOTOR,0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 170);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);
// right to left horizonatl top (point 3 to 4)
myMotorDriver.setDrive( LEFT_MOTOR, 1 , 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000); 
//left roof(point 4 to 5)
myMotorDriver.setDrive( LEFT_MOTOR,0, 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 170);
delay(500);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);
//right roof(point 5 to 6)
myMotorDriver.setDrive( LEFT_MOTOR, 0, 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 1, 170);
delay(500);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);    
// right to left diagonal top to bottom (point 6 to 7)
myMotorDriver.setDrive( LEFT_MOTOR, 1, 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 1, 170);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);
// right to left horizonatl top (point 7 to 8)
myMotorDriver.setDrive( LEFT_MOTOR, 0 ,0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 170);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);      
// right to left diagonal top to bottom (point 8 to 9)
myMotorDriver.setDrive( LEFT_MOTOR, 0, 170);
myMotorDriver.setDrive( RIGHT_MOTOR, 1, 170);
delay(1000);
myMotorDriver.setDrive( LEFT_MOTOR, 0, 0);
myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0);
delay(2000);
}
else if (datap=='0')
 Serial.println("Welcome to pen plotter TEAM 15");   
}
