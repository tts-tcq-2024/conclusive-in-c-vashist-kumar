#include <stdio.h>
#include <string.h>

void printMsg(const char *message) {
    printf("%s", message);
}
void printtoMsg(const char *message) {
    printf("To: %s", message);
}

void printcontroller(const unsigned short header,BreachType breachtype) {
    printf("%x : %x\n", header, breachtype);
}


void (*printMessage)(const char *message) = printMsg;
void (*printToMessage)(const char *message) = printtoMsg;
void (*printtocontroller)(const unsigned short header,BreachType breachtype) = printcontroller;
