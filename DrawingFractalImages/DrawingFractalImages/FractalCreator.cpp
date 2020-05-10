#include "FractalCreator.hpp"

Fractals::FractalCreator::FractalCreator(int width, int height) :
	m_width(width),
	m_height(height),
	m_histogram(new int[Mandelbrot::MAX_ITERATIONS]),
	m_fractal(new int[width * height]),
	m_bitmap(width, height),
	m_zoomList(width, height),
	m_total(0)
{
	// initialising m_histogram with zeros
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_histogram[i] = 0;
	}

	// initialising m_fractal with zeros
	for (int i = 0; i < m_width * m_height; i++)
	{
		m_fractal[i] = 0;
	}

	// default zoom
	addZoom(Zoom(width / 2, height / 2, 4.0 / width));
}

Fractals::FractalCreator::~FractalCreator()
{
}

void Fractals::FractalCreator::calculateIterations()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			std::pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				m_histogram[iterations]++;
			}

			m_fractal[y * m_width + x] = iterations;
		}
	}
}

void Fractals::FractalCreator::calculateTotalIterations()
{
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total += m_histogram[i];
	}
}

void Fractals::FractalCreator::drawFractal()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			int iterations = m_fractal[y * m_width + x];
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;

				for (int i = 0; i <= iterations; i++)
				{
					hue += ((double)m_histogram[i]) / m_total;
				}

				green = hue * 255;
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void Fractals::FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomList.add(zoom);
}

void Fractals::FractalCreator::writeBitmap(std::string filename)
{
	m_bitmap.write(filename);
}

void Fractals::FractalCreator::run()
{
	addZoom(Zoom(295, m_height - 202, 0.1));
	addZoom(Zoom(312, m_height - 304, 0.1));

	calculateIterations();
	calculateTotalIterations();
	drawFractal();

	writeBitmap("test.bmp");
}
