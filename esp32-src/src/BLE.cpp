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
	// getting the same uuid????? wtf
	std::string uuid = pCharacteristic->getUUID().toString();
	std::string value = pCharacteristic->getValue();

	Serial.print("uuid: ");
	Serial.println(uuid.c_str());

	Serial.print("value: ");
	Serial.println(value.c_str());

	if (value.length() < 1)
		return;

	// if (uuid == FULLCOLOR_CHARACTERISTIC_UUID)
	if (value.length() == 8)
	{
		FullColor(value);
	}
	// else if (uuid == COLORGRADIENT_CHARACTERISTIC_UUID)
	else if (value.length() == 16)
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
	try
	{
		RGBW rgbw = {static_cast<uint32_t>(std::strtoul(value.c_str(), nullptr, 16))};
		_led.WriteToAllLeds(rgbw.r, rgbw.g, rgbw.b, rgbw.w);
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}

void BLE::MyCallbacks::ColorGradient(std::string value)
{
	try
	{
		std::string value1 = value.substr(0, 8);
		std::string value2 = value.substr(8, 8);

		Serial.print("value1: ");
		Serial.println(value1.c_str());

		Serial.print("value2: ");
		Serial.println(value2.c_str());

		RGBW rgbw1 = {static_cast<uint32_t>(std::strtoul(value1.c_str(), nullptr, 16))};
		RGBW rgbw2 = {static_cast<uint32_t>(std::strtoul(value2.c_str(), nullptr, 16))};

		_led.Freeze();

		double_t stepr = static_cast<double_t>((rgbw1.r - rgbw2.r)) / 150;
		double_t stepg = static_cast<double_t>((rgbw1.g - rgbw2.g)) / 150;
		double_t stepb = static_cast<double_t>((rgbw1.b - rgbw2.b)) / 150;
		double_t stepw = static_cast<double_t>((rgbw1.w - rgbw2.w)) / 150;

		for (uint8_t i = 0; i < 150; i++)
		{
			_led.WriteToLed(i, rgbw1.r - static_cast<uint8_t>(stepr * (i + 1)),
							rgbw1.g - static_cast<uint8_t>(stepg * (i + 1)),
							rgbw1.b - static_cast<uint8_t>(stepb * (i + 1)),
							rgbw1.w - static_cast<uint8_t>(stepw * (i + 1)));
		}

		_led.Show();
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}