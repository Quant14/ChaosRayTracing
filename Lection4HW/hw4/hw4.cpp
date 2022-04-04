#include <fstream>
#include <time.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

struct Vector {
	double x;
	double y;
	double z;
};

void printVector(Vector a) {
	cout << "x: " << a.x << ", y: " << a.y << ", z: " << a.z << "\n";
}

Vector subtractVector(Vector a, Vector b) {
	Vector res = { a.x - b.x, a.y - b.y, a.z - b.z };
	return res;
}

Vector cross(Vector a, Vector b) {
	Vector res = { a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x };
	return res;
}

double calcLength(Vector a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

class Triangle {
	Vector a;
	Vector b;
	Vector c;
public:
	Triangle(Vector a, Vector b, Vector c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Vector findNormal() {
		Vector e0 = subtractVector(this->b, this->a);
		Vector e1 = subtractVector(this->c, this->a);
		Vector res = cross(e0, e1);
		double length = calcLength(res);
		res.x /= length;
		res.y /= length;
		res.z /= length;
		return res;
	}

	double calculateArea(bool parallelogram) {
		Vector res = cross(subtractVector(this->b, this->a), subtractVector(this->c, this->a));
		if (parallelogram)
			return calcLength(res);
		return calcLength(res) / 2;
	}

	Vector get_a() { return this->a; }
	Vector get_b() { return this->b; }
	Vector get_c() { return this->c; }
};

int main()
{
	Triangle* triangle1 = new Triangle({ 3.5, 0, 0 }, { 1.75, 3.5, 0 }, { 0, 0, 0 } );
	Triangle* triangle2 = new Triangle({ 3, -3, 1 }, { 4, 9, 3 }, { 0, 0, 0 });
	Triangle* triangle3 = new Triangle({ 3, -3, 1 }, { -12, 12, -4 }, { 0, 0, 0 });

	Triangle* triangle4 = new Triangle({ -1.75, 1.75, -3 }, { 1.75, -1.75, -3 }, { 0, 1.75, -3 });
	Triangle* triangle5 = new Triangle({ 0, 0, -1 }, { 1, 0, 1 }, { -1, 0, 1 });
	Triangle* triangle6 = new Triangle({ 0.56, 1.11, 1.23 }, { 0.44, -2.368, -0.54 }, { -1.56, 0.15, -1.92 });
	cout << "Cross 1: ";
	printVector(cross(triangle1->get_a(), triangle1->get_b()));
	cout << "Cross 2: ";
	printVector(cross(triangle2->get_a(), triangle2->get_b()));
	cout << "\nArea of parallelogram 1: " << triangle2->calculateArea(true) << "\n";
	cout << "Area of parallelogram 2: " << triangle3->calculateArea(true) << "\n\n";
	cout << "Normal of triangle 1: ";
	printVector(triangle4->findNormal());
	cout << "Normal of triangle 2: ";
	printVector(triangle5->findNormal());
	cout << "Normal of triangle 3: ";
	printVector(triangle6->findNormal());
	cout << "\nArea of triangle 1: " << triangle4->calculateArea(false) << "\n";
	cout << "Area of triangle 2: " << triangle5->calculateArea(false) << "\n";
	cout << "Area of triangle 3: " << triangle6->calculateArea(false) << "\n";

	return 0;
}