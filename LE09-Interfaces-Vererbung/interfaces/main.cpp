#include <iostream>
#include <svgfile.h>


using namespace std;

int main()
{
    cout << "Interface Implementierung! " << __cplusplus << endl;

    //SVG elemente erstellen
    Punkt p(300,200,"yellow");
    //File öffnen und rausbuttern
    SVGFile svg("hallo");
    svg.addElement(p);

    return 0;
}
