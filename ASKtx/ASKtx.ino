#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
int i = 0;

void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    String number = String(i);
    char msg[16];
    number.toCharArray(msg, 16);
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    i++;
    delay(1000);
}
