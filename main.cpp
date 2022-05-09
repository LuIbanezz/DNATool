#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include "text.h"

using namespace std;


int main ( int argc , char * argv[] ) {         
    string gen1 = readGen(argv[1]);
    string gen2 = readGen(argv[2]);

    string alignment = algorithm(gen1, gen2, gen1.size(), gen2.size());

    printGen(alignment, gen1.size(), gen2.size(), gen1, gen2);

    return 0;
}


