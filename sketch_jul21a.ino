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

#include <SPI.h>
#include <SD.h>

//PROGRAMMER NOTES:
//    Initialized variables here for larger scope, will change if requested.
//    Unable to provide private function in code, please detail further via arduino documentation on what you want used

//Analog Input Variables
const int pinTwo = 2;     //A2
const int pinThree = 3;   //A3
const int pinFour = 4;    //A4

//LED is connected on pin 13
int ledPin = 13;
int blinkDelay = 2000;

//Relay number that user chooses
int relay = 2;

void setup() {
  //Send and receive at 9600 baud
  Serial.begin(9600); 
  //Sets up variable ledPin as output
  pinMode(ledPin, OUTPUT);
  //Sets up variable relay as output
  pinMode(relay, OUTPUT);
}

void loop() {
  //Checked analog pin 2
  analogCheckMod(pinTwo);
  //Checked analog pin 3
  analogCheckMod(pinThree);
  //Checked analog pin 4
  analogCheckMod(pinFour);
  delay(60000);
  //Turn on user selected relay for 10 seconds
  Serial.println("Which relay would you like to use (0 - 8)?");
  relay = Serial.read();
  relayControl(relay,0);
  delay(10000);
  //Turn off relay 2
  relayControl(relay,1);
}

void analogCheckMod(int pinNumber){
     // reads the analog
     int PinRead = analogRead(pinNumber);
  
     // Prints the values
     //Serial.println("Pin " + pinNumber + " value is " + PinRead);
    
    //Blinks led if condition is met
    if (PinRead > 50){
       digitalWrite(ledPin, HIGH);
       //Possible upgrade, try blink method
       delay(2000);
       digitalWrite(ledPin, LOW);
    }
}

//Controls relay shield.  Parameters accepted are relay number and relay state.
//0 = ON, 1 = OFF
//Should add additional check to make sure correct relay is referenced and not beyond relay maximum
void relayControl(int relayNumber, int OnAndOff){
    if (OnAndOff == 0){
      pinMode(relayNumber, HIGH);
    }
    else if (OnAndOff == 1){
      pinMode(relayNumber, LOW);
    }
    else{
      Serial.println("Incorrect state passed to method.");
    }
}






File myFile;
void FileSave(String sampleText){ 
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
myFile.println("Testing 1,2,3");
for (int i = 0; i < 20; i++) {
myFile.println(i);
}
// close the file:
myFile.close();
Serial.println("0.");
} else {
// if the file didn't open, print an error:
if (myFile.size() == 0){
Serial.println("1.");
}

 myFile = SD.open("test.txt");
  if (myFile) {
    if (myFile.size() == 0){
        Serial.println("(1) File is empty");
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
}
}
