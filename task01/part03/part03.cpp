#include <iostream>

class Experiment {
public:
    static void main (){
        std::cout << "Part03 \n Statische funktion (main) - Compiler :   " << __cplusplus << std::endl;
    }
};


#ifndef NO_MAIN

int main () {
    Experiment::main();
}

#endif
