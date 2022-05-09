#ifndef _TEXT_H
#define _TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"


string readGen(string);
string getStringPath(char*);


void printGen (string& alignment, size_t sizeGen1 , size_t sizeGen2, string& gen1, string& gen2);
// void writeGenAux (size_t sizeGen, int line, string& gen1, string& gen2);

#endif //_TEXT_H