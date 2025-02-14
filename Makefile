all:
	platformio -f  run

upload:
	platformio -f  run --target upload

clean:
	platformio -f  run --target clean

program:
	platformio -f  run --target program

uploadfs:
	platformio -f  run --target uploadfs

update:
	platformio -f  update

debug:
	platformio -f  run -v

monitor:
	platformio run -t upload -t monitor
