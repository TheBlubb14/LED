#include "BLE.h"
#include "RGBW.h"
#include <cstdio>
#include <string>
#include <cstdlib>

#define SERVICE_UUID "67555B1C-DF9A-4E51-842C-B9D02692D6CA"
#define CHARACTERISTIC_UUID "D6441569-DEAC-4F6B-A7B6-C95EFFB2CC45"

BLE::BLE(LED &led)
{
    // bluetooth
    BLEDevice::init("LED Streifen");
    pServer = BLEDevice::createServer();
    pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,
                                                     BLECharacteristic::PROPERTY_READ |
                                                         BLECharacteristic::PROPERTY_WRITE |
                                                         BLECharacteristic::PROPERTY_NOTIFY);

    // set callback
    pCallbacks = std::unique_ptr<MyCallbacks>(new MyCallbacks(led));
    pCharacteristic->setCallbacks(pCallbacks.get());

    // set default value
    pCharacteristic->setValue("000000000");

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
    std::string value = pCharacteristic->getValue();
    std::string mode = value.substr(0, 1);
    value = value.substr(1, value.length());

    if (value.length() > 0)
    {
        // Serial.print("recieved: ");
        // for (int i = 0; i < value.length(); i++)
        //     Serial.print(value[i]);

        // Serial.println();

        if (mode == "0")
        {
            RGBW rgbw = {static_cast<uint32_t>(std::strtoul(value.c_str(), nullptr, 16))};

            // Serial.println("converted: " + String(rgbw.r) + " " + String(rgbw.g) + " " + String(rgbw.b) + " " + String(rgbw.w));
            _led.WriteToAllLeds(rgbw.r, rgbw.g, rgbw.b, rgbw.w);
        }
    }
}