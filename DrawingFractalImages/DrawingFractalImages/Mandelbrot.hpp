#ifndef MANDELBROT_HPP
#define MANDELBROT_HPP

#include <string>
#include <cstdint>
#include <memory>

namespace Fractals
{
	class Mandelbrot
	{
	private:

	public:
		Mandelbrot();
		virtual ~Mandelbrot();

		static int getIterations(double x, double y);

	public:
		static const int MAX_ITERATIONS = 1000;
	};
}

#endif // MANDELBROT_HPP