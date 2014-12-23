// SparkFun Serial LCD example 1
// Clear the display and say "Hello World!"

// This sketch is for Arduino versions 1.0 and later
// If you're using an Arduino version older than 1.0, use
// the other example code available on the tutorial page.

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 2
SoftwareSerial mySerial(3,2); // pin 2 = TX, pin 3 = RX (unused)

void setup()
{
  mySerial.begin(9600); // set up serial port for 9600 baud
  delay(2000); // wait for display to boot up
//  mySerial.write(124);    // set display
//  mySerial.write(3);      //     20 Characters
//  mySerial.write(124);    // set display
//  mySerial.write(5);      //     4 lines
  
  
}

void loop()
{
  mySerial.write(254); // move cursor to beginning of first line
  mySerial.write(128);

  mySerial.write("12345678901234567890"); // clear display
  mySerial.write("1                  1");
  mySerial.write("2   The-Charge     2");
  mySerial.write("3  FRC Team 2619   3"); // clear display

  mySerial.write(254); // move cursor to beginning of first line
  mySerial.write(192);
 
  //mySerial.write("1  Hello, World!   1");

  while(1); // wait forever
}

