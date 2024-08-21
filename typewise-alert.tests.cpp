#include <gtest/gtest.h>
#include "typewise-alert.h"


BreachType breachTypeMock;
BreachType classifyTemperatureBreachMock(CoolingType coolingType, double temperatureInC) {
  int lowerLimit = lower_limit[coolingType];
  int upperLimit = upper_limit[coolingType];
  BreachType breachTypeMock = inferBreach(temperatureInC, lowerLimit, upperLimit);
  return inferBreach(temperatureInC, lowerLimit, upperLimit);
}

TEST(TypeWiseAlertTestSuite, test_alert_low_breach) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
  checkAndAlert(TO_CONTROLLER,batteryChar,-10);
  ASSERT_EQ(breachTypeMock ,expected_breach)
}
