#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Automatische Typinferenz!" << __cplusplus << endl << endl;

    //Wenn Typ unbekannt:
    //Kann mit jedem Typ instanziiert werden
    auto dynamisch = "test" ; //string
    auto dynamisch2 = 33;     //int


    // falls vektor<T>::size() und ergebnistyp noch nicht bekannt:
    {
    vector<int> v = {1,2,3};


    //automatische typinferenz: for
    for(decltype(v.size()) i = 0; i < v.size(); ++i) {}
    }

    vector <string> v = {"hi","du","depp"};

    //foreach
    for(const auto& element : v){
        cout << element << endl;
    }


    cout << dynamisch << dynamisch2 <<  endl;

    return 0;
}
