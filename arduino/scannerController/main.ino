// main.ino

#include <AccelStepper.h>

char incomingByte, outgoingByte = 0;   // for incoming serial data

int pinAdir = 5;
int pinAstep = 4;
int pinBdir = 7;   	
int pinBstep = 6;  	 
int pinCdir = 2;
int pinCstep = 3;
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

	stepperB.setMaxSpeed(2000.0);
    stepperB.setAcceleration(100.0);

    stepperC.setMaxSpeed(2000.0);
    stepperC.setAcceleration(100.0);
}

void loop() {
  	// send data only when you receive data:
  	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

		switch (incomingByte)
		{

		/// STEPPER MOTOR CONTROL

		case '7': // focus A+
			outgoingByte = 'A';

			// move a little
			stepperA.runToNewPosition(stepperA.currentPosition()+1);
			break;

		case '4': // focus A-
			outgoingByte = 'a';
			stepperA.runToNewPosition(stepperA.currentPosition()-1);
			break;

		case '8': // focus B+
			outgoingByte = 'B';
			stepperB.runToNewPosition(stepperB.currentPosition()+1);
			break;

		case '5': // focus B-
			outgoingByte = 'b';
			stepperB.runToNewPosition(stepperB.currentPosition()-1);
			break;

		case '9': // motion C+
			outgoingByte = 'C';
			stepperC.runToNewPosition(stepperC.currentPosition()+20);
			break;

		case '6': // motion C-
			outgoingByte = 'c';
			stepperC.runToNewPosition(stepperC.currentPosition()-20);
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
/*
int jog(AccelStepper* pStepper, signed int dir, int steps){
	motionsDone(); // wait for prev motion to finish
	pStepper->moveTo(pStepper->currentPosition()+steps*dir); // move one step

	return 1;
}

int motionsDone() {
	do {
		stepperA.run();
		stepperB.run();
		stepperC.run();
	} while ( !( (stepperA.distanceToGo()==0)&&(stepperB.distanceToGo()==0)&&(stepperC.distanceToGo()==0) ) );

	return 1;
}
*/
