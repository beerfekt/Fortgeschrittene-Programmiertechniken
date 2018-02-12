
/*
Jede Klasse bekommt Seriennummer, um diese eindeutig zu identifizieren

*/

// Point.h

   //private
   const int serialNumber;
   inline static int zaehler; //static zähler zählt die klassen bei erzeugung hoch 
   const int serienNummer; //verhindert die Synthetisierung des Kopierzuweisungsoperators

   //private
   Point(int x, int y);

   //public
   Point(int x);
   Point(const Point& other); //Wichtig, Konstruktor ruft privaten Hauptkonstruktor auf

   Point& operator=(const Point& p);//Überladen des operators =







//Point.cpp

Point::int zaehler = 0;


Point::Point(const Point& other): Point(other.x, other.y)  //ruft privaten seriennummer Konstruktor auf
{}


Point::Point(int x, int y): mx(x),
                            my(y),
                            serialNumber(++zaehler)
{}



Point& Point::operator=(const Point& p)
{
 
if (&rhs != this) {              //selbstzuweisung?
		mX = p.mX;  
		mY = p.mY; 
		mColor = p.mColor; 
	} 
	return *this; // referenz auf dieses objekt
}






//main.cpp


Point p(1,1);
Point p2 = p;

cout << p << p2 << endl; //Ergibt:  p[1,1]  seriennummer:1    
                         //         p2[1,1] seriennummer:2
