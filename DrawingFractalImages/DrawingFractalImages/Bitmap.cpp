#include "Bitmap.hpp"
#include "BitmapInfoHeader.hpp"
#include "BitmapFileHeader.hpp"

#include <fstream>

using namespace Fractals;

namespace Fractals
{
	Bitmap::Bitmap(int width, int height) :
		m_width(width),
		m_height(height),
		m_pPixels(new uint8_t[width * height * 3]{})
	{
	}

	Bitmap::~Bitmap()
	{
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue)
	{
		uint8_t* pPixel = m_pPixels.get();
		// y * m_width = number of pixels/bytes (if each pixel is 1 byte) in all the rows before the one we are actually interested in
		// + x = moving it forward the number of columns specified by x
		// y * 3 = because we have r, g, b
		pPixel += (y * 3) * m_width + (x * 3);

		// reversed format because the bitmap is a little endian format
		// little endian: storing least significant byte in the area of memory that has the smallest memory addressed
		// 0xFF8844
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	bool Bitmap::write(std::string filename)
	{
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;

		std::ofstream file;
		file.open(filename, std::ios::out | std::ios::binary);

		if (!file)
		{
			return false;
		}

		file.write((char*)&fileHeader, sizeof(fileHeader));
		file.write((char*)&infoHeader, sizeof(infoHeader));
		file.write((char*)m_pPixels.get(), m_width * m_height * 3);

		file.close();

		if (!file)
		{
			return false;
		}

		return true;
	}
}