#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include <sstream>

using namespace std;

#define SIZE_OF_LINE 61
#define SIZE_OF_LINE_WITH_SPACES 65

string readGen(string genName)   // recibir nombre del archivo txt
{
    string genPath = "../resources/test/" + genName;
    ifstream fin(genPath, ios::in);

    // bool isOpen = fin.is_open(); // test

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
            // cout<<line2<<endl;
            return line2;
        }
    }
    return "error";
} 


/*string getStringPath (char* genPath)
{
    string aux = genPath;

    string result;

    size_t size = aux.find(".txt") + (size_t)4; //sumo tamano del txt mas la cantidad de elementos hasta el punto
    for (int i = 0; i<size ; i++) //CUIDADO QUE CAMBIE INT POR SIZE_T
    {
        result += aux[i];
    }

    return result;
}*/


void printGen (string& alignment, size_t sizeGen1 , size_t sizeGen2, string& gen1, string& gen2)
{ 
    ofstream fout("out.txt");      //lo vuelvo mi salida

    bool isOpen = fout.is_open();

    for(int i = 0 ; i <= gen1.size() ; i++)
    {
        for(int j = 10; j<SIZE_OF_LINE && j< gen1.size() ; j+=10)
        {
            if(j+(i*SIZE_OF_LINE) < gen1.size()){
                gen1.insert(j+(i*SIZE_OF_LINE),1,' ');
                alignment.insert(j+(i*SIZE_OF_LINE),1,' ');
                gen2.insert(j+(i*SIZE_OF_LINE),1,' ');
                /*
                if(j==60)
                {
                    gen1.insert((i*SIZE_OF_LINE)+j,1,'0');
                    alignment.insert((i*SIZE_OF_LINE)+j,1,'0');
                    gen2.insert((i*SIZE_OF_LINE)+j,1,'0');
                }*/
            }
        }
    }
    int finalSize = gen1.size();

    for(int k = 0; k*SIZE_OF_LINE<=finalSize; k++)
    {
        string lineGen1 = gen1.substr(k*SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineGen1 << endl;

        string lineAlignment = alignment.substr(k*SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineAlignment << endl;

        string lineGen2 = gen2.substr(k*SIZE_OF_LINE, SIZE_OF_LINE);
        fout << lineGen2 << endl;

        fout << endl;
    }
}


