#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdint>
#include "image.h"

int main()
{
	Image image1(1,1) = 10;
	Image image2(1,1) = 10;

	if (image1 == image2) 
	{
		std::cout << "lul" << std::endl;
	}
	else 
	{
		std::cout << "nopenopenoep" << std::endl;
	}
	return 0;
}
