#include <iostream>
#include <punkt.h>

using namespace std;

int main()
{
    cout << "seriennummer + kopieroperator!" << __cplusplus << endl;

    //Punkt p0;
    Punkt p1(1,1, "yellow");
    Punkt p2(2,2);
    Punkt p3 = p2;
    Punkt p4 = p3;

    cout << p1 << p2 << p3 << p4 << endl;

    return 0;
}
