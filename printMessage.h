#include <stdio.h>
#include <string.h>

void printMsg(const char *message) {
    printf("%s\n", message);
}

void (*printMessage)(const char *message) = printMsg;
