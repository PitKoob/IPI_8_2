#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdint>
#include "image.h"
#include <iostream>


// Invertiert gegebenes PGM Bild
Image invert_image(Image const& im)
{
Image res(im.width(),im.height());
for (int i = 1; i <= im.height(); i++) 
	{
		for (int j = 1; j <= im.width(); j++)	
		{
			res(j,i) = 255 - im(j,i);
		}
	}
	
	return res;
}

// Funktion die Schachbrettmuster für ein gegebenes PGM Bild erstellt.
void chess1p(Image & im)
{
	bool blackcheck;
	for (int i = 1; i<=im.height(); i++) 
	{	
		if (i % 2 == 0) blackcheck = true;
		else blackcheck = false;
		for (int j = 1; j<= im.width(); j++)	
		{
			if (blackcheck)	
			{
				im(j,i) = 255;	
				blackcheck = false;
			}
			else { 
				blackcheck= true;
			}
		}
		
	}
}
	
	
Image chessboard(unsigned int width, unsigned int height, unsigned int square_size)
{
	Image res(width,height);

	for (int i = 1; i<=height; i++) 
	{
		for (int j = 1; j<= width; j++)	
		{
			if (j % (2*square_size) < square_size && i % (2*square_size) < square_size) 
				res(j,i) = 0;
			else if (j % (2*square_size) >= square_size && i % (2*square_size) >= square_size)
				res(j,i) = 0;
			else
				res(j,i) = 255;
		}
	}
	
	return res;
} 


int main()
{
	Image image(4,3);
	std::cout << to_string(image) << std::endl;
	chess1p(image);
	writePGM(image,"board4x3.pgm");
	Image imagecopy = readPGM("board4x3.pgm");
	std::cout << to_string(imagecopy) << std::endl;
	
	Image inverted = invert_image(image);
	writePGM(inverted,"inverted4x3.pgm");
	
	if (imagecopy == image) std::cout << "Both pictures are identical" << std::endl;
  	
  	Image image_from_scratch = chessboard(4,3,1);
  	
  	if (image_from_scratch == image) std::cout << "Both pictures are identical" << std::endl;
  	
	Image chessboard_400_300 = chessboard(400,300,20);
	writePGM(chessboard_400_300,"chessboard.pgm");
	
	Image christmas = readPGM("christmas.pgm");
	Image inchristmas = invert_image(christmas);
	writePGM(inchristmas,"christmas-inverse.pgm");

	return 0;
}
