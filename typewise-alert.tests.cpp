#include <gtest/gtest.h>
#include "typewise-alertUtils.h"

#define BUFFER_SIZE 2048
char buffer[BUFFER_SIZE];
extern BreachType breachTypeMock;
extern void checkAndAlertMock(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);
extern void sendToControllerMock(BreachType breachType);
extern  void sendToEmailMock(BreachType breachType);

void testprintsendtoemail() {
    // memset(buffer, 0, sizeof(buffer));
    // BreachType breachType = TOO_HIGH;
    // sendToEmailMock(breachType);
    // const char* expected = "To: a.b@c.com\nHi, the temperature is too high\n";
    // assert(strcmp(buffer, expected) == 0);

    memset(buffer, 0, sizeof(buffer));
    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
    BreachType breachType = TOO_LOW;
    sendToEmailMock(breachType);
    fflush(stdout);
    const char* expected = "To: a.b@c.com\nHi, the temperature is too low";
    assert(strcmp(buffer, expected) == 0);
    
    
    // memset(buffer, 0, sizeof(buffer));
    // sendToEmailMock(TOO_LOW);
    // expected = "To: a.b@c.com\nHi, the temperature is too low\n";
    // assert(strcmp(buffer, expected) == 0);

    // memset(buffer, 0, sizeof(buffer));
    // sendToEmailMock(NORMAL);
    // expected = "";
    // assert(strcmp(buffer, expected) == 0);
}

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

TEST(TypeWiseAlertTestSuite, test_send_to_email) {
  testprintsendtoemail();
}



