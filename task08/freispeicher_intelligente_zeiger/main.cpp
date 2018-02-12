#include <iostream>
#include <memory> //benötigt für intelligente zeiger

#include <quadrat.h>
#include <zeichnung.h>

using namespace std;

int main()
{

/*
    Eigentümerschaft:
      unique - ein intelligenter Zeiger
      shared - mehrere intelligente Zeiger
      keine  - nur roher zeiger
*/




// ------------------- unique ---------------------------------
        unique_ptr<Quadrat> up1 = make_unique<Quadrat>(9,9);
        auto up2 = move(up1); //up1 wird zu up2
        up1 = nullptr;       //up1 ist weg ->  auf nullptr setzen

        //ausgabe:
        cout << &up2 << " wert:  " << up2->getX() << endl;



// -------------------- shared --------------------------------

    //Basics:

    //shared (via Template)
    shared_ptr<Quadrat> sp1 = make_shared<Quadrat>(1,1);
    auto sp2 = sp1;
    // anzahl der zeiger ausgeben
    sp2.use_count();

    //ausgabe:
    cout  << " anzahl zeiger auf adresse: [" << sp2 << " inhalt: " << sp2->getX() <<  "] : " << sp2.use_count() << endl;




    //Eigentümer Teil2:

    {
        Zeichnung z(sp1);  //Zeichnung bekommt Eigentümerschaft
        cout << sp1.use_count() <<   endl;                          // 3 eigentümer
    }
                                                                  // 2 eigentümer


    //lebensdauer

     // foo( const Quadrat* q)   //-> Roher zeiger verlängert Lebensdauer nicht
     // foo( const Quadrat& q)   //-> Referenz verlängert lebensdauer
     // foo ( *q )               //-> besser


    {
        auto sp4 = sp1;
        Zeichnung z;
        z.setQuadrat(sp4); //Lebensdauer wird über Block hinnaus verlängert

    }//normalerweise wäre lebensdauer von sp4 hier zu ende






// ------------------- keine ----------------------------------
            //Siehe "Zeiger"










    return 0;
}
