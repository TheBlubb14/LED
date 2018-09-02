#include "BLE.h"
#include "LED.h"

std::unique_ptr<LED> led;
std::unique_ptr<BLE> ble;

void setup()
{
	Serial.begin(115200);
	// Serial.setDebugOutput(true);
	pinMode(22, OUTPUT);

	try
	{
		led = std::unique_ptr<LED>(new LED());
		ble = std::unique_ptr<BLE>(new BLE(*led));
	}
	catch (const std::exception &e)
	{
		Serial.println("error class initialisation: ");
		Serial.println(e.what());
	}

	try
	{
		led->WriteToAllLeds(0, 0, 10, 1);
		digitalWrite(22, HIGH);
		// led->RainbowCycle(10, 20);
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}

	Serial.println("intialized");
}

void loop()
{
	// put your main code here, to run repeatedly:
	// digitalWrite(22, HIGH);
	// led->WriteToAllLeds(0, 0, 80, 0);
	// delay(5000);
	// digitalWrite(22, LOW);
	// led->TurnLedOff();
	// delay(5000);
}
