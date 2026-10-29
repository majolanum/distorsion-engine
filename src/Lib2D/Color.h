#pragma once

#include <cstdint>

using namespace std;

struct Color
{
	uint8_t r = 255.f;
	uint8_t g = 255.f;
	uint8_t b = 255.f;
	uint8_t a = 255.f;

	Color(uint8_t red, uint8_t blue, uint8_t green, uint8_t alpha = 255);

	 static const Color Black;
	 static const Color White;
	 static const Color Red;
	 static const Color Blue;
	 static const Color Green;
	 static const Color Purple;
	 static const Color Yellow;
	 static const Color Orange;
};