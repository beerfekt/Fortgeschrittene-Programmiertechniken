


//####################################       FREIE und FRIEND FUNKTIONEN




//---------------------- Point.h ------------------------------------

class Point
{


private:

    //Hier als friend bekanntgemacht. -Friend heißt: zugriff auf Private elemente
    friend Point add (const Point& a, const Point& b);

};

//ÖFFENTLICHE SCHNITTSTELLE:
    //freie Funktionen

Point add (const Point& a, const Point& b);




//---------------------- Point.cpp ------------------------------------



//Freie Funktion ohne namensraum Point::

Point add(const Point& a,const Point& b){
    return Point(a.x + b.x, a.y+b.y);     //Funktion hat dank friend deklaration direkten zugriff auf private
}





//---------------------- main.cpp ------------------------------------

//main
    Point c = add(a,b);






//######################################### AUsgabgeoperator überladen (Siehe muster oben)


//---------------------- Point.h ------------------------------------

    //friend deklaration der <<Operator Überladung
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p);

    //<< Operator Überladung in öffentlicher Schnittstelle
    std::ostream& operator<<(std::ostream& outputStream, const Point& p);

//---------------------- Point.cpp ------------------------------------

std::ostream& operator<<(std::ostream& outputStream, const Point& p){
    outputStream << "Point: [" << p.getX() << ", " << p.getY() << "]" ;
    return outputStream;
}




//---------------------- main.cpp ------------------------------------

//main
  Point p;
  cout << p << endl;  // Point p:   x- 3, y-4 , usw. schöne ausgabe

