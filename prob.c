#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

char *binsh = "/bin/sh";

void init() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
    init();
    void *handle;
    void *a;

    handle = dlopen("/lib/x86_64-linux-gnu/libc.so.6", 1);
    a = dlsym(handle, "system");

    char buf[30];

    printf("system : %p\n", a);
    printf("binsh : %p\n", binsh);

    printf("input : ");
    scanf("%s", buf);
    return 0;
}
