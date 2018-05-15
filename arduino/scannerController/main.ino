// main.ino

char incomingByte, outgoingByte = 0;   // for incoming serial data

int pinA1dir = 7;
int pinA1step = 10;
int pinA2dir = 6;	// swap with B2?
int pinA2step = 8;	// swap with B2?

int pinB1dir = 3;   	
int pinB1step = 11;  	 
int pinB2dir = 5;
int pinB2step = 9;

int pinCdir = 4;
int pinCstep = 12;
//int pinR = ;
//int pinG = ;
//int pinB = ;
//int pinIR = ;

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
	
	// configure
	pinMode(pinA1dir, OUTPUT);
	pinMode(pinA1step, OUTPUT);
	pinMode(pinA2dir, OUTPUT);
	pinMode(pinA2step, OUTPUT);

	pinMode(pinB1dir, OUTPUT);
	pinMode(pinB1step, OUTPUT);
	pinMode(pinB2dir, OUTPUT);
	pinMode(pinB2step, OUTPUT);

	pinMode(pinCdir, OUTPUT);
	pinMode(pinCstep, OUTPUT);


	// initial states
	digitalWrite(pinA1dir, HIGH);
	digitalWrite(pinA1step, LOW);
	digitalWrite(pinA2dir, LOW);
	digitalWrite(pinA2step, LOW);

	digitalWrite(pinB1dir, HIGH);
	digitalWrite(pinB1step, LOW);
	digitalWrite(pinB2dir, LOW);
	digitalWrite(pinB2step, LOW);

	digitalWrite(pinCdir, HIGH);
	digitalWrite(pinCstep, LOW);


}

void loop() {
  	// send data only when you receive data:
  	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

		switch (incomingByte)
		{
		case '7': // focus A+
			outgoingByte = 'A';
			// set direction to +
			digitalWrite(pinA1dir, HIGH);
			digitalWrite(pinA2dir, LOW);

			// move a little
			jog(1000, 100, pinA1step, pinA2step);

			break;

		case '4': // focus A-
			outgoingByte = 'a';
			break;

		case '8': // focus B+
			outgoingByte = 'B';
			break;

		case '5': // focus B-
			outgoingByte = 'b';
			break;

		case '9': // motion C+
			outgoingByte = 'C';
			break;

		case '6': // motion C-
			outgoingByte = 'c';
			break;

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

		// feedback to user
		Serial.print(incomingByte);
		Serial.print(' ');
		Serial.print(outgoingByte);
		Serial.println(' ');
    }
}

int jog(int delms, int iter, int pin1, int pin2){
// delms is not too accurate re. clock limits, pinwrite overhead, etc
	for (int i=0; i < iter; i++) {
		digitalWrite(pin1, HIGH);
		digitalWrite(pin1, HIGH);
		delayMicroseconds(delms);
		digitalWrite(pin2, LOW);
		digitalWrite(pin2, LOW);
		delayMicroseconds(delms);
	}
	return 1;
}

