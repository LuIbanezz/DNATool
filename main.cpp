#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"

using namespace std;
string readGen(string genPath);
string getStringPath(char*);

int main ( int argc , char * argv[] ) {         
    string gen1 = readGen(getStringPath(argv[1]));
    string gen2 = readGen(getStringPath(argv[2]));

    char* pointer1 = &gen1[0];
    char* pointer2 = &gen2[0];
    vector<char> alignment = algorithm(pointer1, pointer2, gen1.size(), gen2.size());

    return 0;
}

string readGen(string genPath)   // recibir nombre del archivo txt
{
    ifstream fin(genPath);
    string line1;
    string line2;
    int i=0;

    while(getline(fin, line1))
    {
        if(line1.find("ORIGIN")!=(string::npos)) //si llegue a origin
        {
            while(line1.find("//") == (string::npos))//mientras no llegue a //
            {
                getline(fin, line1);
                while (line1[i] != 'a' && line1[i] != 'c' && line1[i] != 'g' && line1[i] != 't' && i<line1.size())
                {
                    i++;
                }//si no es acgt, avanzo de a un char hasta quedar en acgt

                while (i<line1.size())
                {
                    if(line1[i] != ' ')
                    {
                        line2 += line1[i]; //copio el char acgt
                    }
                    i++;
                }

                
                i=0;//i vuelve a ser cero porque evalua los chars en un renglon 
            }
            cout<<line2<<endl;
            return line2;
        }

    }
    return "error";
} 


string getStringPath (char* genPath)
{
    string aux = genPath;

    string result;

    int size = aux.find(".txt") + (size_t)4; //sumo tamano del txt mas la cantidad de elementos hasta el punto
    for (int i = 0; i<size ; i++)
    {
        result += aux[i];
    }

    return result;
}   