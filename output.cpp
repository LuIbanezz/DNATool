#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include <sstream>

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

    size_t size = aux.find(".txt") + (size_t)4; //sumo tamano del txt mas la cantidad de elementos hasta el punto
    for (int i = 0; i<size ; i++) //CUIDADO QUE CAMBIE INT POR SIZE_T
    {
        result += aux[i];
    }

    return result;
}   


void writeGen (vector<char> gen1, vector<char> gen2, size_t sizeGen1, size_t sizeGen2)
{
    ostringstream out1;
    ostringstream out2;

    for (char c: gen1)
    {
        out1 << c;
    }

    for (char c: gen2)
    {
        out2 << c;
    }

    string output1(out1.str());
    string output2(out2.str());
    
    




}

