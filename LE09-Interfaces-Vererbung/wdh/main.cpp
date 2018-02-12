#include <iostream>
#include <point.h>

using namespace std;



int main()
{
    cout << "WDH" << __cplusplus << endl << endl;

    Point p1(1,1);
    Point p2(2,2);
    Point p2_copy = p2;
    Point p2_copy_construct(p2);

    cout << p1
         << p2
         << p2_copy
         << p2_copy_construct
         << p1+p2
         << endl;



    return 0;
}
