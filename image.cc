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
	bool lastblack;
	for (int i = 1; i<=image.height(); i++) 
	{	
		if (i % 2 == 0) lastblack = false;
		else lastblack = true;
		for (int j = 1; j<= image.width(); j++)	
		{
			if (lastblack)	
			{
				image(j,i) = 255;	
				lastblack = false;
			}
			else { 
				lastblack= true;
			}
		}
		
	}
  			
	std::cout << to_string(image) << std::endl;
	

	return 0;
}
