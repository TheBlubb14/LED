#pragma once

#ifndef _BLE_H_
#define _BLE_H_

#include <BLEServer.h>
#include <Arduino.h>
#include <BLEDevice.h>
#include <memory>

#include "LED.h"

class BLE
{
  public:
    BLE(LED &led);
  private:
  
    class MyCallbacks : public BLECharacteristicCallbacks
    {
      private:
        LED &_led;

      public:
        MyCallbacks(LED &led);

        void onWrite(BLECharacteristic *pCharacteristic);
    };
    BLEServer *pServer;
    BLEService *pService;
    BLECharacteristic *pCharacteristic;
    BLEAdvertising *pAdvertising;
    std::unique_ptr<MyCallbacks> pCallbacks;
};

#endif /*_BLE_H_*/