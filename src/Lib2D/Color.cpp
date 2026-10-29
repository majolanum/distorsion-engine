#include "Color.h"

const Color Black{ 0,  0, 0,255 };
const Color White{ 255, 255,  255, 255 };
const Color Red{ 255,0,  0, 255 };
const Color Blue{ 0,  0, 255, 255 };
const Color Green{ 0, 255, 0, 255 };
const Color Purple{ 128,  0,  128, 255 };
const Color Yellow{ 255,  255, 0,  255 };
const Color Orange{ 255, 165,  0,  255 };

Color::Color(uint8_t red, uint8_t blue, uint8_t green, uint8_t alpha) :
	r(red), b(blue), g(green), a(alpha)
{
}
