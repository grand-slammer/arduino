


void setup() {
  int  pin2 = 2;
  int pin3 = 3;
  int pin4 = 4;
  int pin5 = 5;
  int pin6 = 6;
  int pin7 = 7;
  int pin8 = 8;
  int pin9 = 9;
  int pin10 = 10;
  int pin11 = 11;
  // put your setup code here, to run once:
  analogRead(pin2);
  analogRead(pin3);
  analogRead(pin4);
  analogRead(pin5);
  analogRead(pin6);
  analogRead(pin7);
  analogRead(pin8);
  analogRead(pin9);
  analogRead(pin10);
  analogRead(pin11);
}


void loop() {
  analogWrite(2, 100);
  analogWrite(3, 100);
  analogWrite(4, 100);
  analogWrite(5, 100);
  analogWrite(6, 100);
  analogWrite(7, 100);
  analogWrite(8, 100);
  analogWrite(9, 100);
  analogWrite(10, 100);
  analogWrite(11, 100);
}

/*
#include <SPI.h>
#include <SD.h>
File myFile;
void setup() {
// Open serial communications and wait for port to open:
Serial.begin(9600);
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
*/
