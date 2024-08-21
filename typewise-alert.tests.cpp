#include <gtest/gtest.h>
#include <cassert.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, test_alert_low_breach) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
   ASSERT_EQ(checkAndAlert(TO_CONTROLLER,batteryChar,-10),expected_breach);

}
