CC              := gcc
CFLAGS          := -I/usr/local/include/opencv -L/usr/local/lib
OBJECTS         :=
LIBRARIES       := -lopencv_core -lopencv_imgproc -lopencv_highgui

.PHONY: all clean

all: test

test:
	$(CC) $(CFLAGS) -o hello hello.c $(LIBRARIES)

clean:
	rm -f *.o
