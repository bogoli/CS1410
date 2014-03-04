// Geometry.cpp

Geometry::Geometry(char* n, char* t){
	// inside Geometry Constructor
	Name = n;
	Type = t;
}

Geometry::Geometry(Geomtery &obj){
	// copy constructor 
	
}

Geometry::~Geometry(){
	// inside Geometry Deconstructor
}

double Geometry::ComputeVolume(){
	// inside virtual function (will be defined in derived classes)

}

double ComputeSurface(){
	// inside virtual function (will be defined in derived classes)
}