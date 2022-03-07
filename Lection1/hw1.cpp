#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

struct blocks {
	int r[4][4];
	int g[4][4];
	int b[4][4];
};

/// Output image resolution
static const int imageWidth = 1920;
static const int imageHeight = 1080;
static const int maxColorComponent = 255;

void task1()
{
	srand(time(NULL));
	std::ofstream ppmFileStream("hw1task1.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";
	struct blocks blocks;
	int colN = 0, rowN = 0;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			blocks.r[col][row] = rand() % 256;
			blocks.g[col][row] = rand() % 256;
			blocks.b[col][row] = rand() % 256;
		}
	}

	for (int row = 0; row < imageHeight; row++) {
		rowN = row / 270;
		for (int col = 0; col < imageWidth; col++) {
			colN = col / 480;
			ppmFileStream << (blocks.r[colN][rowN] + rand() % 51) % 256 << " " << (blocks.g[colN][rowN] + rand() % 51) % 256 << " "<< (blocks.b[colN][rowN] + rand() % 51) % 256 << "\t";
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();
}

void task2()
{
	std::ofstream ppmFileStream("hw1task2.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";
	for (int row = 0; row < imageHeight; row++) {
		for (int col = 0; col < imageWidth; col++) {
			if (row > 300 && row < 700 && col > (450 + 700 - row) && col < (1050 + 700 - row)) {
				ppmFileStream << "244 99 30\t";
			}
			else {
				ppmFileStream << "169 185 197\t";
			}
		}
		ppmFileStream << "\n";
	}
}

int main() {

	//task1();

	task2();

	return 0;
}
