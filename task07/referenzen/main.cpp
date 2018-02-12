#include <iostream>

using namespace std;

int main()
{
    cout << "Referenzen!" << endl;



    int original = 4;
    int& referenz = original;
    int kopie = referenz;
    kopie = 5;
    referenz = 88; //anderer name für original, hier wird original verändert

    cout << " original: " << original << "   kopie: " << kopie << endl;


}
