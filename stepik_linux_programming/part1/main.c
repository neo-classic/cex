#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>

void (*hello_message)(const char *);

bool init_library()
{
	void *hdl = dlopen("./libHello.so", RTLD_LAZY);
	if (NULL == hdl) {
		return false;
	}

	hello_message = (void (*)(const char *))dlsym(hdl, "hello_message");
	if (NULL == hello_message) {
		return false;
	}

	return true;
}

int main() {
	if (init_library()) {
		hello_message("Yuriy");
	} else {
		printf("Library not found\n");
	}

	return 0;
}
