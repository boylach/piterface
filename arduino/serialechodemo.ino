// serialechodemo.ino

char incomingByte = 0;   // for incoming serial data

void setup() {
	Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
  	// send data only when you receive data:
  	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

		switch (incomingByte)
		{
		case '1':
			outgoingByte = '1';
			break;

		case '2':
			outgoingByte = '2';
			break;

		case '3':
			outgoingByte = '3';
			break;

		default:
			outgoingByte = '0';
			break;
		}



		Serial.println(incomingByte);
		Serial.print(' ');
		Serial.print(outgoingByte);
		Serial.println(' ');
    }
}