#include <iostream>
#include "quadrat.h"

using namespace std;

int main()
{
    cout << "Freispeicher! - Rohe Zeiger" <<  __cplusplus << endl;


    //Freispeicher:
        //Objekte im Freispeicher bleiben solange erhalten bis diese zerstört werden.
        //identifizierung durch zeiger

        Quadrat * quadrat = new Quadrat(1);  //Allokation im Freispeicher
        cout << quadrat->getX();            //Ausgabe Zeiger
        delete quadrat;                     //löschen
                                           //Vorsicht: nur speicher gelöscht, nicht zeiger
        quadrat = nullptr;                  // daher zeiger auf nllptr zeigen lassen

        if (quadrat) cout << "zeiger:" << quadrat->getX();  //nullptr idiom anwenden!

    return 0;
}
