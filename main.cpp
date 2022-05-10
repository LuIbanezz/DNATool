/**
 * @file main.cpp
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Main file for genome reading. 
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include "text.h"

using namespace std;

int main ( int argc , char * argv[] ) 
{         
    string gen1 = readGen(argv[1]);
    if(gen1 == "error"){
        cout << "Error: could not find line ORIGIN"
    }
    string gen2 = readGen(argv[2]);

    string alignment = algorithm(gen1, gen2, gen1.size(), gen2.size());
    
    printGen(alignment, gen1.size(), gen1, gen2);

    return 0;
}


