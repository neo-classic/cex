LD_LIBRARY_PATH=.

all: lib exe

lib: solution.c
	gcc -o libSolution.so -shared -fPIC solution.c

exe: libSolution.so main.c
	gcc main.c -L. -lSolution -o test

clean:
	rm libSolution.so test 2>/dev/null
