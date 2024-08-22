#include <gtest/gtest.h>
#include "typewise-alert.h"


extern BreachType breachTypeMock;
extern void checkAndAlertMock(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

TEST(TypeWiseAlertTestSuite, test_alert_low_breach) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
  checkAndAlert(TO_CONTROLLER,batteryChar,-10);
  checkAndAlertMock(TO_CONTROLLER,batteryChar,-10);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}
