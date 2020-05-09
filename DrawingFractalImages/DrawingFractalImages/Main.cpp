#include <iostream>

#include "Bitmap.hpp"

using namespace Fractals;

int main()
{
	std::cout << "Drawing Fractal Images" << std::endl;

	Bitmap bipmap(800, 600);
	bipmap.write("test.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}