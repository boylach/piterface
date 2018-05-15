readme.txt

For tips on how to work with the arduino

to set up arduino command to link to the installed arduino program
	alias arduino='/usr/share/arduino-nightly/arduino'

to verify code is valid
	 arduino --verify --board arduino:avr:uno --port /dev/ttyACM0 serialechodemo.ino

to uplode code to board
	 arduino --upload --board arduino:avr:uno --port /dev/ttyACM0 serialechodemo.ino

to access serial in/out
	screen /dev/ttyACM0 9600
	(and to exit from screen, ctrl-a then ctrl-d)



