#include "Utils.h"
#include <iostream>
#include <stdlib.h>

int Utils::Srand(int min, int max)
{
	int r = min + (rand() % (max - min + 1));
	return r;
}

int Utils::AskInt(const char* msg, int min, int max)
{
	int value = 0;
	do {
		std::cout << msg << std::endl;
		std::cout << "->";
		std::cin >> value;
		std::cout << std::endl;
		if (value > max || value < min)
			std::cout << "mauvaise valeur entree, reessayer" << std::endl;
	} while (value > max || value < min);
	return value;
}
