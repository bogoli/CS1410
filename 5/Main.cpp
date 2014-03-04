// Main.cpp

#include "Geometry.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Box.h"


int main(int argc, char const *argv[])
{
	cout << "This is main.\n\n";

	/*

	// test case: red rectangle
	Rectangle red = Rectangle("red", 20, 20);
	red.PrintGeometry();
	cout  << red.GetName() << " " << "Volume: "  << red.ComputeVolume() << endl;
	cout  << red.GetName() << " " << "Surface: " << red.ComputeSurface() << endl;

	cout << endl << endl; 

	// test case cerulean circle
	Circle cerulean = Circle("cerulean", 5);
	cerulean.PrintGeometry();
	cout << cerulean.GetName() << " " << "Volume: " << cerulean.ComputeVolume() << endl;
	cout << cerulean.GetName() << " " << "Surface: " << cerulean.ComputeSurface() << endl;

	*/

	Box blue = Box("blue", 20, 20, 20);
	blue.PrintGeometry();
	cout  << blue.GetName() << " " << "Volume: "  << blue.ComputeVolume() << endl;
	cout  << blue.GetName() << " " << "Surface: " << blue.ComputeSurface() << endl;



	return 0;
}