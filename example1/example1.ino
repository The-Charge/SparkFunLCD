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
  
  LCD.write("    The-Charge      ");
  LCD.write("   FRC Team 2619    ");
  LCD.write("                    ");
  LCD.write("                    ");
   
  LCD.write(254); // move cursor to beginning of the fourth line
  LCD.write(212);  
  delay(2000);
  
  LCD.write(" Begin Encoder Test ");
  delay(2000);

}

long clicks = 0;
long oldPosition  = -1;    // define encoder clicks
bool movingForward = true;
long newPosition = 1;
int isHolding =0;

void loop()

{ 
  LCD.write(254); // move cursor to beginning of first line
  LCD.write(128);
  
  newPosition = rotaryEncoder1.read();
  clicks = newPosition - oldPosition;
  
  if (newPosition != oldPosition)
  {
    if (newPosition > oldPosition)    // Forward
    {
      isHolding = 0;
      movingForward = true;
      oldPosition = newPosition;
      Serial.println(newPosition);
      LCD.write("Forward:            ");
      LCD.write(254); // move cursor to the 10th character of fourth line
      LCD.write(222);
      LCD.print(clicks, DEC);

    }
    else                            // Backward
    {
       isHolding = 0;
       movingForward = false;
       oldPosition = newPosition;
       Serial.println(newPosition);
       LCD.write("Backward:           ");
       LCD.write(254); // move cursor to the 10th character of fourth line
       LCD.write(222);
       LCD.print(clicks, DEC);

    }
    long clicks = 0 ;

  }
  else
  {
    isHolding++;
    if (isHolding > 10) LCD.write("   Holding Still    ");
  }
  delay(100);      // wait for 100 msec.

}

void clearScreen()
{
  //clears the screen, you will use this a lot!
  LCD.write(0xFE);
  LCD.write(0x01); 
}
