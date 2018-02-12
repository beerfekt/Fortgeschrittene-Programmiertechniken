#include <iostream>
#include <point.h>

using namespace std;

int main()
{
    cout << "Freie Funktionen: "  << __cplusplus << endl;

    Point a(1,1);
    Point b(4,2);
    Point c = add(a,b); //Anwendung der freien Funktion

    cout << "Point [ " << c.getX() << ", " << c.getY() << " ]" << endl;
    return 0;
}
