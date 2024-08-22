#include <stdio.h>
#include <string.h>

void printMsg(const char *message) {
    printf("%s\n", message);
}
void printtoMsg(const char *message) {
    printf("To: %s\n", message);
}

void printcontroller(const char *header,const char *message) {
    printf("%x : %x\n", message);
}


void (*printMessage)(const char *message) = printMsg;
void (*printToMessage)(const char *message) = printtoMsg;
void (*printtocontroller)(const char *header,const char *message) = printcontroller;
