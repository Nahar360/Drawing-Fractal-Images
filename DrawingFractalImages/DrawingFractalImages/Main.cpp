#include <iostream>

#include "FractalCreator.hpp"

using namespace Fractals;

int main()
{
	std::cout << "Drawing Fractal Images" << std::endl;

	const int WIDTH = 800;
	const int HEIGHT = 600;

	FractalCreator fractalCreator(WIDTH, HEIGHT);
	fractalCreator.run();

	return 0;
}