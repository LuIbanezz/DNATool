#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "algorithm.h"
#include <sstream>

string readGen(string genPath)   // recibir nombre del archivo txt
{
    ifstream fin(genPath);

    cout << genPath << endl;
    string line1;
    string line2;
    int i=0;

    while(getline(fin, line1))
    {
        if(line1.find("ORIGIN")!=(string::npos)) //si llegue a origin
        {
            cout << "found line !" << endl;
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

/*
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
}   */


void printGen (deque<char> alignment, size_t sizeGen1 , size_t sizeGen2, string gen1, string gen2)
{ 
    int i = 0;
    int j = 0;
    int k = 0;
    gen1.push_back('0');
    gen2.push_back('1');
    alignment.push_back('2');
    ofstream fout ("out.txt");//lo vuelvo mi salida

    while (gen1[i]!= '0' && gen2[j]!='1' && alignment[k]!='2')
    {
        //string aux1 = writeGenAux(); //HAY QUE VER COMO INTERCALAR LLAMADA A FRENGLON DE GENOMA1 (SU AUXILIAR), ALINEAMIENTO (AUXILIAR?) Y LLAMADA A RENGLON DE GENOMA2(AUXILIAR)
        i+=65; //REEMPLAZO COUT POR FOUT Y YA IMPRIMO EN EL ARCHIVO. 

    }
}

string writeGenAux (size_t sizeGen, int line)//me llegan gen1 y gen2 por referencia
{
    string gen = "actg";//SACAR
    string aux;

    for(int j = 0; j<sizeGen ; j+=10)
    {
        gen.insert(j,' ',1);
    }
//HACER ESTO ANTES
    //la idea es hacer un string auxiliar que contenga 60 caracteres mas 5 espacios, y que imprima eso

    for (int i = line; i<line+65 ; i++) //HAY QUE VER COMO PROGRAMAR LINE PARA QUE QUEDE EL INDICE DE GEN EN EL RENGLON QUE CORRESPONDE
    {
        aux += gen[i];
    }

    return aux; //estoy devolviendo un renglon de un genoma
}



