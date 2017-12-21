#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdint>
#include "image.h"
#include <iostream>

int main()
{
	
	Image image(4,3);
	std::cout << to_string(image) << std::endl;
	
	image(4,3) = 1;
	std::cout << to_string(image) << std::endl;
	
	std::cout << to_string(image) << std::endl;

	return 0;
}
