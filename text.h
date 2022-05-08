#ifndef _TEXT_H
#define _TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"


string readGen(string);
string getStringPath(char*);


void writeGen(vector<char>, vector<char>, size_t, size_t);

#endif //_TEXT_H