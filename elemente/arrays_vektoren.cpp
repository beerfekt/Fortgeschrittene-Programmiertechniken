#include <iostream>
#include <vector>
#include <iosfwd>
#include <sstream>

using namespace std;

// ########## Quadrat schnell hingerotzt  #######################


class Quadrat {
    friend ostream& operator<<(ostream& outputStream, const Quadrat& q);
public:
    int width;
    Quadrat(int width = 100);
};

//Freie:

ostream& operator<<(ostream& outputStream, const Quadrat& q){
    outputStream << "[" << q.width << ", " << q.width << "]" ;
    return outputStream;
}



//definitionen
Quadrat::Quadrat(int width)
   :width(width)
{}





// ########## Punkt schnell hingerotzt zur veranschaulichung ####

class Punkt {

    friend ostream& operator<<(ostream& outputStream, const Punkt& p);


public:
    Punkt(int x = 1, int y = 1);
        int x,y;
};

ostream& operator<<(ostream& outputStream, const Punkt& p){
    outputStream << "[" << p.x << ", " << p.y << "]" ;
    return outputStream;
}


Punkt::Punkt(int x, int y)
    : x(x),
      y(y)
{}
//##########################################################








//freie Funktion, verschiedene Datentypen:

void auslesen(const auto& vector) {
    for (auto element : vector){
        cout << "auslesen: - " ;
        cout << element << endl;
    }
}



//###################### main ###############################


int main()
{
    cout << "normale Arrays" << endl;

//Normale Arrays
    Punkt punkte[3];
    size_t punkte_size = (sizeof punkte/sizeof punkte[0]);

    //einlesen
    for (size_t i = 0; i < punkte_size; i++){
        punkte[i] = Punkt();
    }
    //auslesen
    for (Punkt& p : punkte) {
        cout << p.x << p.y << endl;
    }


    //Generische Container:
    //initialisierung
    vector<Punkt> v (4,Punkt()); //4*Punkt
    vector<Punkt> v2 = {Punkt(1,1), Punkt(2,2)};


    //Typisiert:

    //einlesen int
    for (int i = 0; i < 10; i++) v.push_back(v2[1]);

    //einlesen size_t , v.size()
    for (size_t i = 0; i < v.size(); i++) {
        v[i] = v2[1];
    }

    //auslesen
    for (Punkt& p : v) {
        cout << p.x << endl;
    }



    // zum test der verschiedenen Typen der f. "auslesen":
    vector<Quadrat> q (3,Quadrat());
    auslesen(v);
    auslesen(q);




    return 0;
}

