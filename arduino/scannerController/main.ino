// main.ino

#include <AccelStepper.h>

char incomingByte, outgoingByte = 0;   // for incoming serial data

int pinAdir = 5;
int pinAstep = 4;
int pinBdir = 7;   	
int pinBstep = 6;  	 
int pinCdir = 3;
int pinCstep = 2;
//int pinR = ;
//int pinG = ;
//int pinB = ;
//int pinIR = ;

AccelStepper stepperA(AccelStepper::DRIVER, pinAstep, pinAdir);
AccelStepper stepperB(AccelStepper::DRIVER, pinBstep, pinBdir);
AccelStepper stepperC(AccelStepper::DRIVER, pinCstep, pinCdir);

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps

	// configure steppers
    stepperA.setMaxSpeed(2000.0);
    stepperA.setAcceleration(100.0);
    stepperA.moveTo(0);

	stepperB.setMaxSpeed(2000.0);
    stepperB.setAcceleration(100.0);
    stepperB.moveTo(0);

    stepperC.setMaxSpeed(2000.0);
    stepperC.setAcceleration(100.0);
    stepperC.moveTo(0);

}

void loop() {
  	// send data only when you receive data:
  	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

		// implement stepper motion
		stepperA.run();
		stepperB.run();
		stepperC.run();

		switch (incomingByte)
		{

		/// STEPPER MOTOR CONTROL

		case '7': // focus A+
			outgoingByte = 'A';

			// move a little
			jog(&stepperA, 1, 1);
			break;

		case '4': // focus A-
			outgoingByte = 'a';
			jog(&stepperA, -1, 1);
			break;

		case '8': // focus B+
			outgoingByte = 'B';
			jog(&stepperB, 1, 1);
			break;

		case '5': // focus B-
			outgoingByte = 'b';
			jog(&stepperB, -1, 1);
			break;

		case '9': // motion C+
			outgoingByte = 'C';
			jog(&stepperC, 1, 1);
			break;

		case '6': // motion C-
			outgoingByte = 'c';
			jog(&stepperC, -1, 1);
			break;

		/// LED ILLUMINATION AND FRAME CAPTURE CONTROL

		case '1': // LED R
			outgoingByte = 'R';
			break;

		case '2': // LED G
			outgoingByte = 'G';
			break;

		case '3': // LED B
			outgoingByte = 'B';
			break;

		case '0': // LED IR
			outgoingByte = 'i';
			break;			

		default:
			outgoingByte = '0';
			break;
		}

		// FEEDBACK TO USER
		Serial.print(incomingByte);
		Serial.print(' ');
		Serial.print(outgoingByte);
		Serial.println(' ');
    }
}

int jog(AccelStepper* pStepper, signed int dir, int steps){
	if(pStepper->distanceToGo() == 0){ // if finished last motion
		pStepper->moveTo(pStepper->currentPosition()+steps*dir); // move one step
	}
	return 1;
}

