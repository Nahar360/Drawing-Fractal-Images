#include <iostream>
#include <cstdint>

#include "Bitmap.hpp"
#include "Mandelbrot.hpp"

using namespace Fractals;

int main()
{
	std::cout << "Drawing Fractal Images" << std::endl;

	const int WIDTH = 800;
	const int HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min = INT_MAX;
	double max = INT_MIN;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			double xFractal = (x - (WIDTH / 2)) * 2.0 / WIDTH;
			double yFractal = (y - (HEIGHT / 2)) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			uint8_t red = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

			bitmap.setPixel(x, y, red, red, red);

			if (red < min) min = red;
			if (red > max) max = red;
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}