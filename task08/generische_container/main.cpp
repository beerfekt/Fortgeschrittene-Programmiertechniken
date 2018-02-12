#include <iostream>
#include <vector>
#include "/home/beer/workspace/progII/task06/klassen/point.h"

using namespace std;


//VL 08 S.1-3


int main()
{
    cout << "08 - Generische Container  " << __cplusplus << endl << endl << endl;


    //Vektor<typ> ist generischer Container
    vector<int> vektor1 = {1,2,3,4,5};  // 1,2,3,4,5
    vector<int> vektor2 (2,44);         // 2 mal 44 -> {44,44}
    vector<int> v = vektor2;

      //größe des vektors
      cout << vektor1.size() << endl;
      cout << vektor2.size() << endl
           << endl;

      //ausgabe einzelnes element
          //Subscript-Operator
      cout << vektor1[2] << endl;
      cout << vektor2[2] << endl
           << endl
           << endl
           << endl ;


     //einfügen am ende:
     vektor1.push_back(9);



     //for schleife

     for (size_t i = 0 ; i < vektor1.size() ; i++) {
         cout << vektor1[i] <<  " ";
     }


     //for schleife

     for (int x : vektor2) {
        cout << x <<  " ";
     }


     // falls vektor<T>::size() und ergebnistyp noch nicht bekannt:

     //automatische typinferenz: for
     for(decltype(v.size()) i = 0; i < v.size(); ++i) {}

     //foreach
     for(const auto& element : v){
         cout << element << endl;
     }




     //BSP Vorlesung:
     Point p;


     vector<Point> points;
     points.push_back(p);
     points.push_back(p);

     for (Point point : points) {
         cout << point ;
     }

     // Neue Seriennummer bei den Points bei kopie
     vector<Point> points2 = points;

     for (Point point : points2){
         cout << point ;
     }






    return 0;
}
