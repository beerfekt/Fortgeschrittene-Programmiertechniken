
//point.h


        Point(const Point& other);

	Point& operator=(const Point& p);
	const int serienNummer; //verhindert die Synthetisierung des Kopierzuweisungsoperators


//point.cpp

Point& Point::operator=(const Point& p)
{
 
if (&rhs != this) {              //selbstzuweisung?
		mX = p.mX;  
		mY = p.mY; 
		mColor = p.mColor; 
	} 
	return *this; // referenz auf dieses objekt
}
