#include <gtest/gtest.h>
#include "typewise-alert.h"


TEST(TypeWiseAlertTestSuite, test_alert_low_breach) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
  checkAndAlert(TO_CONTROLLER,batteryChar,-10);
  ASSERT_EQ(,expected_breach)
}
