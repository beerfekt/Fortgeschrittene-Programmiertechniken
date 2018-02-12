#include <iostream>
#include <point.h>

using namespace std;

int main()
{
    Point a{1,2};
    Point b{3,4};
    Point c = add(a,b);

    cout << "Friend-Funktionen" << __cplusplus << endl
         << endl
         << "Point [ " << c.getX() << ", " << c.getY() << " ]" << endl;  //TODO  << operator überladen
    return 0;
}
