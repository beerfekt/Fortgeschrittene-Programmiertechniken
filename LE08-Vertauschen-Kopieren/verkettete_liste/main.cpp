#include <iostream>
#include <pointlist.h>

//include "/home/beer/workspace/progII/task06/klassen/point.h"

using namespace std;





int main()
{
    cout << "LE08 Verkettete Liste : " << __cplusplus << endl << endl;


    // List
       //enthält -  ListNode s


    //RULE OF THREE :

/*
    Muss eine der Elementfunktionen:
                                    - Destruktor
                                    - Kopierkonstruktor
                                    - Kopierzuweisungsoperator
    überschrieben oder verboten werden,
    so trifft das fast immer auf die anderen 2 auch zu


    //Wann?
    Bei Rohen zeigern
*/

    PointList list1;
    PointList list2;

    for (int i = 0; i < 10; i++)   list1 += Point();
    for (int i = 0; i < 3; i++) list2 += Point();

    cout << "list1-size: " << list1.size() << endl;
    cout << "list2-size: " << list2.size() << endl;


    swap(list1,list2); //freie funktion

    cout << "list1-size: " << list1.size() << endl;
    cout << "list2-size: " << list2.size() << endl;

    list1.swap(list2); //element funktion

    cout << "list1-size: " << list1.size() << endl;
    cout << "list2-size: " << list2.size() << endl;


    //stand LE08 - S7





    return 0;
}




