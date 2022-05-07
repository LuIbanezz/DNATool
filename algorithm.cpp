#include <vector>
#include "algorithm.h"
#include <iostream>
#define INDELSCORE -1
#define MATCHSCORE 1
#define SUSTSCORE -1

using namespace std;

void algorithm (char* gen1, char* gen2, int sizeGen1, int sizeGen2)
{
    AlgorithmData* mat = new AlgorithmData[(sizeGen1+1)*(sizeGen2+1)];

    mat[0].score = 0;
    mat[0].vertical = 0;
    mat[0].diagonal = 0;
    mat[0].horizontal = 0;


    for(int i=1 ; i <= (sizeGen1+1) ; i++)
    {
        mat[i].score = -i;
        mat[i].horizontal = 1;
    }

    for(int j=1; j <= (sizeGen2+1); j++)
    {    
        for(int i=0; i < (sizeGen1+1) ; i++)
        {
            mat[i+(j*(sizeGen1+1))];
        }
    }

/*
filas: sizeGen2 +1
col: sizeGen1 +1

0   -1   -2   -3   -4   -5
0                       
0
0


*/




   delete[] mat;

}


/*
puntaje 0
bool    arriba
bool    horizontal
bool    diagonal


*/
