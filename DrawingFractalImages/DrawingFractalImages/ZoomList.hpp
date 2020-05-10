#ifndef ZOOMLIST_HPP
#define ZOOMLIST_HPP

#include "Zoom.hpp"

#include <vector>
#include <utility>

namespace Fractals
{
	class ZoomList
	{
	private:
		int m_width = 0;
		int m_height = 0;
		std::vector<Zoom> m_zooms;

		double m_xCenter = 0;
		double m_yCenter = 0;
		double m_scale = 1.0;

	public:
		ZoomList(int width, int height);

		void add(const Zoom& zoom);
		std::pair<double, double> doZoom(int x, int y);
	};
}

#endif // ZOOMLIST_HPP