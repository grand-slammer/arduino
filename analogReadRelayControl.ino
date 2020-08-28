//Notes:
//1.  Please use setup to only initialize the constants used for each pin, do not read analog inputs during setup.
//2.  There are only three analog inputs, not all pins should be used as reading analog.  Pick 3 pins and only use those pins to call analogRead()
//3.  Create a private function and call this function from loop to read analog inputs, setup a delay to call this function only once every minute.
//4.  New function needs to do the following:
//      Use analogRead to get the value from each of the three pins used
//      Show value from analogRead onto the screen
//      If analogRead value is over 50, we want an LED on the Arduino to light up.  Please figure out how best to have an LED light from any pin you choose.
//5.  Create another new function for the SD card code you included, add library files up at the top of the solution.  Keep code commented until ready for use.
//6.  We need to control relays and would like a new function that will handle all relay activity.  The function needs to work as follows:
//      We want to pass in a parameter for relay number (integer), this will control the relay we want to use
//      We want to pass in a state value (integer) as a parameter, this will control if we want the relay ON or OFF.  ON = 0, OFF = 1 
//7.  Comment all of your code as good as the comments shows for the SD Card code, notice that about every line has a description of what is its intention
//8.  If you have a relay board, please test turning on and off relays after your code is created to make sure it works as expected.
//#include <SPI.h>
//#include <SD.h>
// Initialized variables here for larger scope, will change if requested.
int pinTwo = 2;
int pinThree = 3;
int pinFour = 4;
int ledPin;
int relay;
void setup() {
  Serial.begin(9600); // send and receive at 9600 baud
   pinMode(ledPin, OUTPUT);
   pinMode(relay, OUTPUT);
}


void analogCheck(){
 
 // reads the analog
 int PinTwoRead = analogRead(pinTwo);
 int PinThreeRead = analogRead(pinThree);
 int PinFourRead = analogRead(pinFour);

  // Prints the values
  Serial.println("Pin Two's value is " + PinTwoRead);
  Serial.println("Pin Three's value is " + PinThreeRead);
  Serial.println("Pin Four's value is " + PinFourRead);
  
  //Turns on led if condition is met
  if (PinTwoRead > 50){
    int ledPin = 2;
     digitalWrite(ledPin, HIGH);
     delay(2000);
     digitalWrite(ledPin, LOW);
  }

     else if (PinThreeRead > 50){
    int ledPin = 3;
     digitalWrite(ledPin, HIGH);
     delay(2000);
     digitalWrite(ledPin, LOW);
     }

     else if (PinFourRead > 50){
    int ledPin = 4;
     digitalWrite(ledPin, HIGH);
     delay(2000);
     digitalWrite(ledPin, LOW);
     }
  }
  
void relayControl(int relayNumber, int OnAndOff){
  Serial.println("What relay do you want to use. Please enter 2,3,or 4.");
 int userAnswer = Serial.read();

  if (userAnswer == 2){
    relay = 2;
    Serial.println("Do you want it on or off?  ON = 0, OFF = 1 ");
    int OnOrOff = Serial.read();
    if (OnOrOff == 0){
      pinMode(relay, HIGH);
    }
      if (OnOrOff == 1){
      pinMode(relay, LOW);
    }
  }

  if (userAnswer == 3){
    relay = 3;
    Serial.println("Do you want it on or off?  ON = 0, OFF = 1 ");
    int OnOrOff = Serial.read();
    if (OnOrOff == 0){
      pinMode(relay, HIGH);
    }
      if (OnOrOff == 1){
      pinMode(relay, LOW);
    }
  }

  if (userAnswer == 4){
    relay = 4;
    Serial.println("Do you want it on or off?  ON = 0, OFF = 1 ");
    int OnOrOff = Serial.read();
    if (OnOrOff == 0){
      pinMode(relay, HIGH);
    }
      if (OnOrOff == 1){
      pinMode(relay, LOW);
    }
  }
  
}

void loop() {
analogCheck();
delay(60000);
}

/*
#include <SPI.h>
#include <SD.h>
File myFile;
void FileSave{ 
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
Serial.print("Initializing SD card...");
if (!SD.begin(10)) {
Serial.println("initialization failed!");
while (1);
}
Serial.println("initialization done.");
// open the file. note that only one file can be open at a time,
// so you have to close this one before opening another.
myFile = SD.open("test.txt", FILE_WRITE);
// if the file opened okay, write to it:
if (myFile) {
Serial.print("Writing to test.txt...");
myFile.println("This is a test file :)");
myFile.println("testing 1, 2, 3.");
for (int i = 0; i < 20; i++) {
myFile.println(i);
}
// close the file:
myFile.close();
Serial.println("done.");
} else {
// if the file didn't open, print an error:
Serial.println("error opening test.txt");
}
}
}
*/
