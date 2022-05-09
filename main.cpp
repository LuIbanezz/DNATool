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

    cout << argv[1] << endl;
    cout << argv[2] << endl;

    cout << gen1 << endl;

    //char* pointer1 = &gen1[0];
    //char* pointer2 = &gen2[0];
    deque<char> alignment = algorithm(gen1, gen2, gen1.size(), gen2.size());

    return 0;
}


