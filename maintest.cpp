#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"

using namespace std;

int main()
{
    string gen2 = "cgatga";
    string gen1 = "gactgta";

    char* pointer1 = &gen1[0];
    char* pointer2 = &gen2[0];
    int sizeGen1 = 7;
    int sizeGen2 = 6;
    vector<char> alignment = algorithm(pointer1, pointer2, sizeGen1, sizeGen2);
}

