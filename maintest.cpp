
/**
 * @file maintest.cpp
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Algorithm tester.
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"

using namespace std;

int main()
{
    string gen1 = "cgattatgcttaaagtactagt";    //en matriz esta en filas
    string gen2 = "tgtactaggtaactgactacgtaaactagctagg";     // en matriz esta en columnas

    string alignment = algorithm(gen1, gen2, gen1.size(), gen2.size());
}

