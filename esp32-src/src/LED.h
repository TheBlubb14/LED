#pragma once

#ifndef _LED_H_
#define _LED_H_

#include <Arduino.h>
#include "esp32_digital_led_lib.h"
#include "RGBW.h"

class LED
{
	const uint8_t pinNum = 13;
	const uint8_t numberOfLeds = 150;

	strand_t pStrand = {.rmtChannel = 0, .gpioNum = pinNum, .ledType = led_types::LED_SK6812W_V1, .brightLimit = 255, .numPixels = numberOfLeds, .pixels = nullptr, ._stateVars = nullptr};

	public:
		LED();

	void WriteToAllLeds(RGBW rgbw);
	void WriteToAllLeds(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
	void WriteToLed(uint8_t i, RGBW rgbw);
	void WriteToLed(uint8_t i, uint8_t r, uint8_t g, uint8_t b, uint8_t w);

	void TurnLedOff();
	void Show();
	void Freeze();

	void RainbowCycle(uint8_t wait_ms = 20, uint8_t iteration = 1);
	void TheaterChaseRainbow(uint8_t wait_ms = 50);

	private:
		void UpdatePixels();
		RGBW Wheel(uint8_t pos);
};

#endif /* _LED_H_ */