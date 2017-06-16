#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>
#include <stdlib.h>

int (*someSecretFunctionPrototype)(int);

// ./solution libShared.so someSecretFunctionPrototype 8

bool init_library(char *argv[])
{
	void *hdl = dlopen(argv[1], RTLD_LAZY);
	if (NULL == hdl) {
        printf("%s\n", dlerror());
		return false;
	}

	someSecretFunctionPrototype = (int (*)(int))dlsym(hdl, argv[2]);
	if (NULL == someSecretFunctionPrototype) {
        printf("%s\n", dlerror());
		return false;
	}

	return true;
}

int main(int argc, char *argv[]) {
    int i = 0;
	if (init_library(argv)) {
		i = someSecretFunctionPrototype(atoi(argv[3]));
        printf("%d\n", i);
	} else {
		printf("Library not found\n");
	}

	return 0;
}
