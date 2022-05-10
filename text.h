/**
 * @file text.h
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Header for input and output manager. Reads genome and prints alignment in another file.
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "algorithm.h"

#define SIZE_OF_LINE 66

using namespace std;

string readGen(string);
string getStringPath(char*);
void printGen (string&, size_t, string&, string&);

#endif //_TEXT_H