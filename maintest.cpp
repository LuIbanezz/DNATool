#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"

using namespace std;

int main()
{
    string gen1 = "cgattatgcttaaagtactagt";    //en matriz esta en filas
    string gen2 = "tgtactaggtaactgactacgtaaactagctagg";     // en matriz esta en columnas

    deque<char> alignment = algorithm(gen1, gen2, gen1.size(), gen2.size());
}

