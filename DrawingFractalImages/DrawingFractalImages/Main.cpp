#include <iostream>

#include "Bitmap.hpp"

using namespace Fractals;

int main()
{
	std::cout << "Drawing Fractal Images" << std::endl;

	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	int pixelsDrawn = 1;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (pixelsDrawn % 1 == 0)
			{
				bitmap.setPixel(j, i, 255, 0, 0);
			}
			if (pixelsDrawn % 2 == 0)
			{
				bitmap.setPixel(j, i, 0, 255, 0);
			}
			if (pixelsDrawn % 3 == 0)
			{
				bitmap.setPixel(j, i, 0, 0, 255);
			}

			pixelsDrawn++;
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}