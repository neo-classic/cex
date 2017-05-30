all: exe lib

exe: main.c lib
	gcc main.c -fPIC -ldl -o hello

lib: hello.c
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	rm hello libHello.so 2>/dev/null
