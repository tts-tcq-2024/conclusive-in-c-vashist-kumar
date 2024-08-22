er#include <gtest/gtest.h>
#include "typewise-alertUtils.h"


extern BreachType breachTypeMock;
extern void checkAndAlertMock(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
extern sendToControllerMock();
extern 

TEST(TypeWiseAlertTestSuite, test_alert_low_breach_to_controller) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
  checkAndAlert(TO_CONTROLLER,batteryChar,-10);
  checkAndAlertMock(TO_CONTROLLER,batteryChar,-10);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

TEST(TypeWiseAlertTestSuite, test_alert_hi_breach_to_controller) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = TOO_HIGH;
  checkAndAlert(TO_CONTROLLER,batteryChar,50);
  checkAndAlertMock(TO_CONTROLLER,batteryChar,50);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

TEST(TypeWiseAlertTestSuite, test_alert_normal_to_email) {
  BatteryCharacter batteryChar = {PASSIVE_COOLING," "};
  BreachType expected_breach = NORMAL;
  checkAndAlert(TO_EMAIL,batteryChar,25);
  checkAndAlertMock(TO_EMAIL,batteryChar,25);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

TEST(TypeWiseAlertTestSuite, test_alert_low_breach_to_email) {
  BatteryCharacter batteryChar = {HI_ACTIVE_COOLING," "};
  BreachType expected_breach = TOO_LOW;
  checkAndAlert(TO_EMAIL,batteryChar,-10);
  checkAndAlertMock(TO_EMAIL,batteryChar,-10);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

TEST(TypeWiseAlertTestSuite, test_alert_normal_to_controller_hiactivecooling) {
  BatteryCharacter batteryChar = {HI_ACTIVE_COOLING," "};
  BreachType expected_breach = NORMAL;
  checkAndAlert(TO_CONTROLLER,batteryChar,25);
  checkAndAlertMock(TO_EMAIL,batteryChar,25);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

TEST(TypeWiseAlertTestSuite, test_alert_hi_breach_to_email) {
  BatteryCharacter batteryChar = {MED_ACTIVE_COOLING," "};
  BreachType expected_breach = TOO_HIGH;
  checkAndAlert(TO_EMAIL,batteryChar,50);
  checkAndAlertMock(TO_EMAIL,batteryChar,50);
  ASSERT_EQ(breachTypeMock ,expected_breach);
}

