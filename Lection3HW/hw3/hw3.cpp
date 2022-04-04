#include <fstream>
#include <time.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

/// Output image resolution
static const int imageWidth = 1920;
static const int imageHeight = 1080;
static const double aspectRatio = (double)imageWidth / (double)imageHeight;
static const int maxColorComponent = 255;

int clamp(int value, int min, int max) {
	if (value <= min)
		return min;
	if (value >= max)
		return max;
	return value;
}

void hw3(double z)
{
	std::ofstream ppmFileStream("hw3.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	double x = 0, y = 0;

	for (int row = 0; row < imageHeight; row++) {
		for (int col = 0; col < imageWidth; col++) {
			x = col + 0.5;
			y = row + 0.5;
			x /= imageWidth;
			y /= imageHeight;
			x = (2.0 * x) - 1.0;
			y = 1.0 - (2.0 * y);
			x *= aspectRatio;
			ppmFileStream << to_string(abs((int)(x * 255))) << " " << to_string(abs((int)(y * 255))) << " " << to_string(abs((int)z * 255)) << "\t";
			//моля да ми кажете как да си оправя aspect ratio-то да работи правилно, защото не мога да го измисля
		}
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
}

int main()
{
	hw3(-1.0);

	return 0;
}