
#include <exception>

#include "LED.h"

bool isFrozen = false;

LED::LED()
{
	// LED
	pinMode(pinNum, OUTPUT);
	digitalWrite(pinNum, HIGH);

	digitalLeds_initStrands(&pStrand, 1);
	digitalLeds_resetPixels(&pStrand);
}

void LED::UpdatePixels()
{
	if (!isFrozen)
	{
		digitalLeds_updatePixels(&pStrand);
	}
}

void LED::WriteToAllLeds(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
	RGBW rgbw;
	rgbw.r = r;
	rgbw.g = g;
	rgbw.b = b;
	rgbw.w = w;
	WriteToAllLeds(rgbw);
}

void LED::WriteToAllLeds(RGBW rgbw)
{
	try
	{
		for (uint8_t i = 0; i < numberOfLeds; i++)
		{
			(&pStrand)->pixels[i] = pixelFromRGBW(rgbw.r, rgbw.g, rgbw.b, rgbw.w);
		}

		UpdatePixels();
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}

void LED::WriteToLed(uint8_t i, uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
	RGBW rgbw;
	rgbw.r = r;
	rgbw.g = g;
	rgbw.b = b;
	rgbw.w = w;

	WriteToLed(i, rgbw);
}

void LED::WriteToLed(uint8_t i, RGBW rgbw)
{
	try
	{
		(&pStrand)->pixels[i] = pixelFromRGBW(rgbw.r, rgbw.g, rgbw.b, rgbw.w);
		UpdatePixels();
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}

void LED::TurnLedOff()
{
	WriteToAllLeds(0, 0, 0, 0);
}

void LED::Show()
{
	isFrozen = false;
	UpdatePixels();
}

void LED::Freeze()
{
	isFrozen = true;
}

// LED Show
RGBW LED::Wheel(uint8_t pos)
{
	RGBW color;
	if (pos < 85)
	{
		color.r = pos * 3;
		color.g = 255 - pos * 3;
		color.b = 0;
		color.w = 0;
	}
	else if (pos < 170)
	{
		pos -= 85;
		color.r = 255 - pos * 3;
		color.g = 0;
		color.b = pos * 3;
		color.w = 0;
	}
	else
	{
		pos -= 170;
		color.r = 0;
		color.g = pos * 3;
		color.b = 255 - pos * 3;
		color.w = 0;
	}

	return color;
}

void LED::RainbowCycle(uint8_t wait_ms, uint8_t iteration)
{
	try
	{
		for (uint8_t j = 0; j < 256 * iteration; j++)
		{
			Freeze();
			for (uint8_t i = 0; i < 150; i++)
			{
				WriteToLed(i, Wheel(((i * 256 / 150) + j) & 255));
			}
			Show();
			delay(wait_ms);
		}
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}

void LED::TheaterChaseRainbow(uint8_t wait_ms)
{
	for (uint8_t j = 0; j < 256; j++)
	{
		for (uint8_t q = 0; q < 3; q++)
		{
			Freeze();
			for (uint8_t i = 0; i < 150; i += 3)
			{
				WriteToLed(i + q, Wheel((i + q) % 255));
			}
			Show();
			delay(wait_ms);

			for (uint8_t i = 0; i < 150; i += 3)
			{
				WriteToLed(i + q, 0, 0, 0, 0);
			}
		}
	}
}
