#include <iostream>
#include <a.h>



using namespace std;

int main()
{
    cout << "Hello World!" << __cplusplus << endl;

    A a;         //Referenz auf a
    const A& a2 = a  ; //Konstante Referenz auf a

    a.setX(30);

    // a2.setX(4); geht nicht da a2 const
    A& a3 = a;

    cout << a.getX()  << endl;
    cout << a2.getX() << endl;
    a.test(a3);


    //bsp. Skript 4.2
    int d = 42;
    d = 3; // ok
    const int& rd = d;
    // rd = 3; // not ok




    return 0;
}
