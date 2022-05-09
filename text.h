#ifndef _TEXT_H
#define _TEXT_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"


string readGen(string);
string getStringPath(char*);


string writeGenAux(size_t);
void printGen (deque<char> , size_t , size_t , string , string);

#endif //_TEXT_H