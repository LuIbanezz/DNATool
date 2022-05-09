#include "algorithm.h"

using namespace std;

string algorithm(string& gen1, string& gen2, size_t sizeGen1, size_t sizeGen2)
{
    char* pointerGen1 = &gen1[0];
    char* pointerGen2 = &gen2[0];

    AlgorithmData* mat = new AlgorithmData[(sizeGen1+1)*(sizeGen2+1)];

    mat[0].score = 0;
    mat[0].direction = 0;

    for(int i=1 ; i <= (sizeGen1+1) ; i++)
    {
        mat[i].score = -i;
        mat[i].direction = horizontal;
    }

    for(int j=1 ; j <= (sizeGen1+1) ; j++)
    {
        mat[j*(sizeGen2+1)].score = -j;
        mat[j*(sizeGen2+1)].direction = vertical;
    }

    calculateScoreandDirection(mat, pointerGen1, pointerGen2, sizeGen1, sizeGen2);
    
    //test
    //cout << mat[17].score << endl;      // test
    //cout << mat[17].vertical << endl;   // test
    //cout << mat[17].horizontal << endl; // test
    //cout << mat[17].diagonal << endl;   // test
    //

    string alignment = calculateOptimumPath(mat, sizeGen1, sizeGen2, gen1, gen2);

    return alignment;

    delete[] mat;
}


void calculateScoreandDirection (AlgorithmData* mat, char* pointerGen1, char* pointerGen2, int sizeGen1, int sizeGen2)
{

    int verticalScore;
    int diagonalScore;
    int horizontalScore;
    int maxScore;

    for(int j=1; j < (sizeGen1+1); j++)
    {
        for(int i=1; i < (sizeGen2+1) ; i++)
        {
            int actualPosition = i+(j*(sizeGen2+1));        //test
            
            int verticalValue = mat[i+((j-1)*(sizeGen2+1))].score;      //test
            verticalScore = mat[i+((j-1)*(sizeGen2+1))].score + INDELSCORE; 

            int horizontalValue = mat[(i-1)+(j*(sizeGen2+1))].score;        //test
            horizontalScore = mat[(i-1)+(j*(sizeGen2+1))].score + INDELSCORE;

            int diagonalValue = mat[(i-1)+((j-1)*(sizeGen2+1))].score;      //test

            char caracterGen1 = pointerGen1[j-1];       //test
            char caracterGen2 = pointerGen2[i-1];       //test

            if(pointerGen1[j-1] == pointerGen2[i-1])    // coinciden los caracteres
            {
                diagonalScore = mat[(i-1)+((j-1)*(sizeGen2+1))].score + MATCHSCORE;
            }
            else
            {   
                diagonalScore = mat[(i-1)+((j-1)*(sizeGen2+1))].score + SUSTSCORE;
            }

            if(verticalScore > horizontalScore)
            {
                maxScore = verticalScore;
                mat[i+(j*(sizeGen2+1))].direction = vertical;
            }
            else
            {
                maxScore = horizontalScore;
                mat[i+(j*(sizeGen2+1))].direction = horizontal;
            }

            if(diagonalScore > maxScore)
            {
                maxScore = diagonalScore;
                mat[i+(j*(sizeGen2+1))].direction = diagonal;
            }
            mat[i+(j*(sizeGen2+1))].score = maxScore;       // la posicion que estoy editando es mat[i+(j*(sizeGen1+1))]
            //cout << "score" << i << " , " << j << " : " << mat[i+(j*(sizeGen2+1))].score << endl;
            //cout << "direction" << i << " , " << j << " : " << mat[i+(j*(sizeGen2+1))].direction << endl;
        }
    }
}

string calculateOptimumPath(AlgorithmData* mat, int sizeGen1, int sizeGen2, string& gen1, string& gen2)
{
    int currentPositionIndex = (sizeGen1 + 1)*(sizeGen2 + 1) - 1;
    int nextPositionIndex = currentPositionIndex;

    int indexGen1 = sizeGen1;
    int indexGen2 = sizeGen2;
    string alignment;

    while(nextPositionIndex != 0)
    {
        switch(mat[nextPositionIndex].direction)
        {
            case vertical:
                nextPositionIndex -= (sizeGen2+1);
                alignment.push_back(' ');
                gen2.insert(indexGen2, "-", 1);
                indexGen1--;
                break;
            case horizontal:
                nextPositionIndex -= 1;
                alignment.push_back(' ');
                gen1.insert(indexGen1, "-", 1);
                indexGen2--;
                break;
            case diagonal:
                int currentPositionIndex = nextPositionIndex;
                nextPositionIndex -= (sizeGen2+2);
                if(mat[currentPositionIndex].score > mat[nextPositionIndex].score)  // coinciden
                {
                    alignment.push_back('|');
                }
                else
                {
                    alignment.push_back('*');
                }
                indexGen1--;
                indexGen2--;
                break;
        }
    }

    string auxAlignment;

    for(int i = (alignment.size() -1); i>=0; i--)
    {
        auxAlignment.push_back(alignment[i]);
    }

    /*
    for( int i = 0 ; i <= gen1.size() ; i++)
    {
        cout << gen1[i] << endl;
    }

    for( int i = 0 ; i <= alignment.size() ; i++)
    {
        cout << alignment[i] << endl;
    }

    for( int i = 0 ; i <= gen2.size() ; i++)
    {
        cout << gen2[i] << endl;
    }*/

    return auxAlignment;

}