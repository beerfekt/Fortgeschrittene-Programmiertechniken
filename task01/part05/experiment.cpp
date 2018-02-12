#include<iostream>         //Wichtig da sonst wegen cout is not a member of std gemosert wird
#include <experiment.h>    //header muss überall verlinkt sein



//definition der Funktion main ausserhalb
void Experiment::main (){
      std::cout << "Part05 \n  Statische funktion (main) - Compiler :   " << __cplusplus << std::endl;
}
