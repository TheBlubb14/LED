#include "BLE.h"
#include "RGBW.h"
#include <cstdio>
#include <string>
#include <cstdlib>

#define SERVICE_UUID "67555B1C-DF9A-4E51-842C-B9D02692D6CA"
#define FULLCOLOR_CHARACTERISTIC_UUID "D6441569-DEAC-4F6B-A7B6-C95EFFB2CC45"
#define COLORGRADIENT_CHARACTERISTIC_UUID "55A5527C-E720-4294-A3AD-FB46DCB00AAE"

BLE::BLE(LED &led)
{
	// bluetooth
	BLEDevice::init("LED Streifen");
	pServer = BLEDevice::createServer();
	pService = pServer->createService(SERVICE_UUID);
	pCallbacks = std::unique_ptr<MyCallbacks>(new MyCallbacks(led));

	pFullColorCharacteristic = pService->createCharacteristic(FULLCOLOR_CHARACTERISTIC_UUID,
															  BLECharacteristic::PROPERTY_READ |
																  BLECharacteristic::PROPERTY_WRITE |
																  BLECharacteristic::PROPERTY_NOTIFY);

	pColorGradientCharacteristic = pService->createCharacteristic(COLORGRADIENT_CHARACTERISTIC_UUID,
																  BLECharacteristic::PROPERTY_READ |
																	  BLECharacteristic::PROPERTY_WRITE |
																	  BLECharacteristic::PROPERTY_NOTIFY);

	// set callback
	pFullColorCharacteristic->setCallbacks(pCallbacks.get());
	pColorGradientCharacteristic->setCallbacks(pCallbacks.get());

	// set default value
	pFullColorCharacteristic->setValue("00000000");
	pColorGradientCharacteristic->setValue("0000000000000000");

	pService->start();

	pAdvertising = pServer->getAdvertising();
	pAdvertising->start();
}

// callback
BLE::MyCallbacks::MyCallbacks(LED &led)
	: _led(led)
{
}

void BLE::MyCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
	std::string uuid = pCharacteristic->getUUID().toString();

	Serial.println("uuid:");
	Serial.println(uuid.c_str());

	std::string value = pCharacteristic->getValue();

	if (value.length() < 1)
		return;

	std::string vvv = "67555B1C-DF9A-4E51-842C-B9D02692D6CA";
	if (uuid == vvv)
	{
		Serial.println("JUP");
	}

	if (uuid == FULLCOLOR_CHARACTERISTIC_UUID)
	{
		Serial.println("if full");
		FullColor(value);
	}
	else if (uuid == COLORGRADIENT_CHARACTERISTIC_UUID)
	{
		Serial.println("if grad");
		ColorGradient(value);
	}

	// Serial.print("recieved: ");
	// for (int i = 0; i < value.length(); i++)
	//     Serial.print(value[i]);

	// Serial.println();
}

void BLE::MyCallbacks::FullColor(std::string value)
{
	RGBW rgbw = {static_cast<uint32_t>(std::strtoul(value.c_str(), nullptr, 16))};
	_led.WriteToAllLeds(rgbw.r, rgbw.g, rgbw.b, rgbw.w);
}

void BLE::MyCallbacks::ColorGradient(std::string value)
{
	std::string value1 = value.substr(0, 7);
	std::string value2 = value.substr(7, 15);

	Serial.print("value1: ");
	Serial.println(value1.c_str());

	Serial.print("value2: ");
	Serial.println(value2.c_str());
}