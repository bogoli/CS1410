// Main.cpp

#include "Geometry.h"
#include "Rectangle.h"
#include "Box.h"
#include "Circle.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Prism.h"

// report function 
void report(Geometry &obj){

	cout << "----- Geometry Report -----\n";
	cout << "   Name:    " << obj.GetName() << endl;
	cout << "   Type:    " << obj.GetType() << endl; 
	cout << "   Volume:  " << obj.ComputeVolume()  << endl;
	cout << "   Surface: " << obj.ComputeSurface() << endl;
	cout << "---------------------------\n";
}

// =================================== MAIN ======================

int main(int argc, char const *argv[])
{

/*   TEST CODE 

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

	cout << endl << endl; 

	// test case blue box
	Box blue = Box("blue", 20, 20, 20);
	blue.PrintGeometry();
	cout  << blue.GetName() << " " << "Volume: "  << blue.ComputeVolume() << endl;
	cout  << blue.GetName() << " " << "Surface: " << blue.ComputeSurface() << endl;

	cout << endl << endl; 

	// test case salmon sphere
	Sphere salmon = Sphere("salmon", 10);
	salmon.PrintGeometry();
	cout  << salmon.GetName() << " " << "Volume: "  << salmon.ComputeVolume() << endl;
	cout  << salmon.GetName() << " " << "Surface: " << salmon.ComputeSurface() << endl;

	cout << endl << endl; 

	// test case teal triangle
	Triangle teal = Triangle("teal", 10, 20);
	teal.PrintGeometry();
	cout  << teal.GetName() << " " << "Volume: "  << teal.ComputeVolume() << endl;
	cout  << teal.GetName() << " " << "Surface: " << teal.ComputeSurface() << endl;

	cout << endl << endl; 

	Prism purple = Prism("purple", 5, 12, 10);
	purple.PrintGeometry();
	cout  << purple.GetName() << " " << "Volume: "  << purple.ComputeVolume() << endl;
	cout  << purple.GetName() << " " << "Surface: " << purple.ComputeSurface() << endl;




	Rectangle test = new Rectangle("test", 10, 10);
	Rectangle testcopy = test;


*/

	Rectangle red = new Rectangle("red", 10, 10); 

	
	return 0;
}