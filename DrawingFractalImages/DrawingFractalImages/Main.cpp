#include <iostream>
#include <cstdint>
#include <memory>
#include "math.h"

#include "Bitmap.hpp"
#include "Mandelbrot.hpp"

using namespace Fractals;

int main()
{
	std::cout << "Drawing Fractal Images" << std::endl;

	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int SIZE = WIDTH * HEIGHT;

	Bitmap bitmap(WIDTH, HEIGHT);

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]);
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		histogram[i] = 0;
	}

	std::unique_ptr<int[]> fractal(new int[SIZE]);
	for (int i = 0; i < SIZE; i++)
	{
		fractal[i] = 0;
	}

	// Storing
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			double xFractal = (x - (WIDTH / 2) - 175) * 2.0 / HEIGHT; // same scaling factor (HEIGHT)
			double yFractal = (y - (HEIGHT / 2)) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				histogram[iterations]++;
			}

			fractal[y * WIDTH + x] = iterations;
		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	// Drawing
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;

				for (int i = 0; i <= iterations; i++)
				{
					hue += ((double)histogram[i]) / total;
				}

				green = std::pow(255, hue);
			}

			bitmap.setPixel(x, y, red, green, blue);
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished" << std::endl;

	return 0;
}