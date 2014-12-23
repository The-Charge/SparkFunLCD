#include <Encoder.h>

// This sketch is for Arduino versions 1.0 and later

// Use the softwareserial library to create a new "soft" serial port
// for the display. This prevents display corruption when uploading code.
#include <SoftwareSerial.h>

// Attach the serial display's RX line to digital pin 5
SoftwareSerial LCD(5,6);  // pin 5 = TX, pin 6 = RX (unused)

Encoder rotaryEncoder1 (2, 3);      // Connect encoder to Interupt Pins (2, 3)

void setup()
{
  Serial.begin(9600);  // prepare to wirte to the console
  Serial.println("Begin Encoder Test");
  LCD.begin(9600);  // set up serial port to LCD
  delay(1500);      // wait for display to boot up
  clearScreen();  
  LCD.write(254); // move cursor to beginning of first line
  LCD.write(128);
  
  LCD.write("12345678901234567890"); 
  LCD.write("                    ");
  LCD.write("    The-Charge      ");
  LCD.write("   FRC Team 2619    "); // clear display
  LCD.write(254); // move cursor to beginning of first line
  LCD.write(128);  
  delay(2000);
  
  LCD.write(" Begin Encoder Test ");
  delay(2000);

}

long oldPosition  = -999;    // define encoder clicks

void loop()
{
  clearScreen();
 
  LCD.write(254); // move cursor to beginning of first line
  LCD.write(128);

  bool movingForward;
  
  long newPosition = rotaryEncoder1.read();
  if (newPosition != oldPosition)
  {
    if (newPosition > oldPosition)    // Forward
    {
      movingForward = true;
    }
    long clicks = 0 ;
    oldPosition = newPosition;
    Serial.println(newPosition);
  }

 
  delay(2000);      // leave splash screen up for 2 sec.


//  while(1); // wait forever
}

void clearScreen()
{
  //clears the screen, you will use this a lot!
  LCD.write(0xFE);
  LCD.write(0x01); 
}
