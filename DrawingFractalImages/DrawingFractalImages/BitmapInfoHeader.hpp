#ifndef BITMAPINFOHEADER_HPP
#define BITMAPINFOHEADER_HPP

#include <cstdint>

#pragma pack(2)

namespace Fractals
{
	struct BitmapInfoHeader
	{
		// int32_t = 4 bytes * 9 = 36
		// int16_t = 2 bytes * 2 = 4
		// actual size of the struct = 36 + 4 = 40 bytes
		int32_t headerSize{ 40 };

		int32_t width; // width of bitmap
		int32_t height; // height of bitmap
		int16_t planes{ 1 };
		int16_t bitsPerPixel{ 24 }; // 1 byte per pixel (R, G, B)
		int32_t compression{ 0 }; // no compression
		int32_t dataSize{ 0 }; // the size of the data written to the bitmap file
		int32_t horizontalResolution{ 2400 }; // 2400 bits per pixel
		int32_t verticalResolution{ 2400 }; // 2400 bits per pixel
		int32_t colors{ 0 };
		int32_t importantColors{ 0 };
	};
}

#endif // BITMAPINFOHEADER_HPP
