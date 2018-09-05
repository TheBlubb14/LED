#include "BLE.h"
#include "RGBW.h"
#include <cstdio>
#include <string>
#include <cstdlib>

// UUID HAVE TO BE LOWER CASE
#define SERVICE_UUID "67555b1c-df9a-4e51-842c-b9d02692d6ca"
#define FULLCOLOR_CHARACTERISTIC_UUID "d6441569-deac-4f6b-a7b6-c95effb2cc45"
#define COLORGRADIENT_CHARACTERISTIC_UUID "55a5527c-e720-4294-a3ad-fb46dcb00aae"

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
	pFullColorCharacteristic->setCallbacks(pCallbacks.get());
	pFullColorCharacteristic->setValue("00000000");

	pColorGradientCharacteristic = pService->createCharacteristic(COLORGRADIENT_CHARACTERISTIC_UUID,
																  BLECharacteristic::PROPERTY_READ |
																	  BLECharacteristic::PROPERTY_WRITE |
																	  BLECharacteristic::PROPERTY_NOTIFY);
	pColorGradientCharacteristic->setValue("0000000000000000");
	pColorGradientCharacteristic->setCallbacks(pCallbacks.get());

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
	std::string value = pCharacteristic->getValue();

	Serial.println(uuid.c_str());

	if (value.length() < 1)
		return;

	if (uuid == FULLCOLOR_CHARACTERISTIC_UUID)
	{
		FullColor(value);
	}
	else if (uuid == COLORGRADIENT_CHARACTERISTIC_UUID)
	{
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