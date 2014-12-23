// SparkFun Serial LCD example 1
// Clear the display and say "Hello World!"

// This sketch is for Arduino versions 1.0 and later
// If you're using an Arduino version older than 1.0, use
// the other example code available on the tutorial page.

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial LCD(3,2); // pin 2 = TX, pin 3 = RX (unused)

void setup()
{
  LCD.begin(9600);  // set up serial port for 9600 baud
  delay(2000);      // wait for display to boot up
  
}

void loop()
{
  clearScreen();
  
  LCD.write(254); // move cursor to beginning of first line
  LCD.write(128);

  LCD.write("12345678901234567890"); // clear display
  LCD.write("1                  1");
  LCD.write("2   The-Charge     2");
  LCD.write("3  FRC Team 2619   3"); // clear display

  LCD.write(254); // move cursor to beginning of first line
  LCD.write(192);
 
  delay(2000);      // leave splash screen up for 2 sec.

  LCD.write("1  Hello, World!   1");

  while(1); // wait forever
}

void clearScreen()
{
  //clears the screen, you will use this a lot!
  LCD.write(0xFE);
  LCD.write(0x01); 
}
