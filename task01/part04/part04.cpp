#include <iostream>

class Experiment {
public:
    //nur deklaration der Funktion main
    static void main();
};


//definition der Funktion main ausserhalb
void Experiment::main (){
      std::cout << "Part04 \n  Statische funktion (main) - Compiler :   " << __cplusplus << std::endl;
}

#ifndef NO_MAIN

//die freie Funktion main (nicht die main oben)
int main () {
    Experiment::main();
}

#endif
