#include "ZoomList.hpp"

Fractals::ZoomList::ZoomList(int width, int height) :
	m_width(width), m_height(height)
{
}

void Fractals::ZoomList::add(const Zoom& zoom)
{
	m_zooms.push_back(zoom);

	m_xCenter += (zoom.x - (m_width / 2)) * m_scale;
	m_yCenter += (zoom.y - (m_height / 2)) * m_scale;

	m_scale *= zoom.scale;
}

std::pair<double, double> Fractals::ZoomList::doZoom(int x, int y)
{
	double xFractal = (x - (m_width / 2)) * m_scale + m_xCenter;
	double yFractal = (y - (m_height / 2)) * m_scale + m_yCenter;

	return std::pair<double, double>(xFractal, yFractal);
}
