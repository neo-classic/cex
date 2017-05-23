all: hello

hello: main.c hello.h libHello.so
	gcc main.c -L. -lHello -o hello

libHello.so: hello.c hello.h
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null
