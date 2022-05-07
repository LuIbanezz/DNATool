#include <iostream>
#include <fstream>
#include <string>
#include "algorithm.h"

using namespace std;
int readGen (char * genPath);

int main ( int argc , char * argv[] ) {         
    int index = readGen(argv[1]);

    cout << argv[1] << endl;

    char* gen1 = "actg";
    char* gen2 = "tcag";
    algorithm(gen1, gen2, 4, 4);

    return 0;
}


// abre archivo
// lee texto entre origin y //
// devuelve la letra si es actg si no lee la prox hasta encontrar actg

int readGen (char * genPath)   // recibir nombre del archivo txt
{
    ifstream fin(genPath);

    string line;
    int i = 0;
    int originIndex = 0;

    while(getline(fin, line))
    {
        if(line.find("ORIGIN")!=(string::npos)){

            originIndex = i;
            break;
        }
        i++;
    }

    return originIndex;
} 

