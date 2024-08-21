#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

 bool checkActiveHi(CoolingType coolingType){
   if(coolingType == HI_ACTIVE_COOLING){
      lowerLimit = 0;
      upperLimit = 45;
     return true;
    }
     return false;
   }

 bool checkPassiveCooling(CoolingType coolingType){
   if(coolingType == PASSIVE_COOLING){
      lowerLimit = 0;
      upperLimit = 35;
     return true;
    }
     return false;
   }

 bool checkActiveMed(CoolingType coolingType){
   if(coolingType == MED_ACTIVE_COOLING){
      lowerLimit = 0;
      upperLimit = 40;
     return true;
    }
     return false;
   }

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = 0;
  int upperLimit = 0;

  checkActiveHi(coolingType);
  checkPassiveCooling(coolingType);
  checkActiveMed(coolingType);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

void checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

bool lowTempMsg(BreachType breachType){
  if(breachType == 1) {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
  }
}

void sendToEmail(BreachType breachType) {
    const char* recepient = "a.b@c.com";
    const char* messages[] = {"Hi, the temperature is too low\n","Hi, the temperature is too high\n"};
    
    if (breachType == TOO_LOW || breachType == TOO_HIGH) {
        printMessage("To: %s\n", recepient);
        printMessage("%s", messages[breachType]);
    }
}
