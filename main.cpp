#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include "text.h"

using namespace std;


int main ( int argc , char * argv[] ) {         
    string gen1 = readGen(getStringPath(argv[1]));
    string gen2 = readGen(getStringPath(argv[2]));

    char* pointer1 = &gen1[0];
    char* pointer2 = &gen2[0];
    vector<char> alignment = algorithm(pointer1, pointer2, gen1.size(), gen2.size());

    return 0;
}


