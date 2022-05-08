#include "algorithm.h"

using namespace std;

deque<char> algorithm(char* gen1, char* gen2, size_t sizeGen1, size_t sizeGen2)
{
    AlgorithmData* mat = new AlgorithmData[(sizeGen1+1)*(sizeGen2+1)];

    mat[0].score = 0;
    mat[0].direction = 0;

    for(int i=1 ; i <= (sizeGen1+1) ; i++)
    {
        mat[i].score = -i;
        mat[i].direction = horizontal;
    }

    for(int j=1 ; j <= (sizeGen2+1) ; j++)
    {
        mat[j*(sizeGen1+1)].score = -j;
        mat[j*(sizeGen1+1)].direction = vertical;
    }

    calculateScoreandDirection(mat, gen1, gen2, sizeGen1, sizeGen2);
    
    //test
    //cout << mat[17].score << endl;      // test
    //cout << mat[17].vertical << endl;   // test
    //cout << mat[17].horizontal << endl; // test
    //cout << mat[17].diagonal << endl;   // test
    //

    deque<char> alignment = calculateOptimumPath(mat, sizeGen1, sizeGen2, gen1, gen2);

    return alignment;

    delete[] mat;
}


void calculateScoreandDirection (AlgorithmData* mat, char* gen1, char* gen2, int sizeGen1, int sizeGen2)
{

    int verticalScore;
    int diagonalScore;
    int horizontalScore;
    int maxScore;

    for(int j=1; j < (sizeGen2+1); j++)
    {
        for(int i=1; i < (sizeGen1+1) ; i++)
        {
            //int actualPosition = i+(j*(sizeGen1+1));        //test
            
            //int verticalValue = mat[i+((j-1)*(sizeGen1+1))].score;      //test
            verticalScore = mat[i+((j-1)*(sizeGen1+1))].score + INDELSCORE; 

            //int horizontalValue = mat[(i-1)+(j*(sizeGen1+1))].score;        //test
            horizontalScore = mat[(i-1)+(j*(sizeGen1+1))].score + INDELSCORE;

            //int diagonalValue = mat[(i-1)+((j-1)*(sizeGen1+1))].score;      //test

            //char caracterGen1 = gen1[i-1];       //test
            //char caracterGen2 = gen2[j-1];       //test

            if(gen1[i-1] == gen2[j-1])    // coinciden los caracteres
            {
                diagonalScore = mat[(i-1)+((j-1)*(sizeGen1+1))].score + MATCHSCORE;
            }
            else
            {   
                diagonalScore = mat[(i-1)+((j-1)*(sizeGen1+1))].score + SUSTSCORE;
            }

            if(verticalScore > horizontalScore)
            {
                maxScore = verticalScore;
                mat[i+(j*(sizeGen1+1))].direction = vertical;
            }
            else
            {
                maxScore = horizontalScore;
                mat[i+(j*(sizeGen1+1))].direction = horizontal;
            }

            if(diagonalScore > maxScore)
            {
                maxScore = diagonalScore;
                mat[i+(j*(sizeGen1+1))].direction = diagonal;
            }
            mat[i+(j*(sizeGen1+1))].score = maxScore;       // la posicion que estoy editando es mat[i+(j*(sizeGen1+1))]
            // cout << "posicion " << i << " , " << j << " = " << mat[i+(j*(sizeGen1+1))].score << endl;   //test
        }
    }

}

deque<char> calculateOptimumPath(AlgorithmData* mat, int sizeGen1, int sizeGen2, char* gen1, char* gen2)
{
    int currentPositionIndex = (sizeGen1 + 1)*(sizeGen2 + 1) - 1;
    int nextPositionIndex = currentPositionIndex;

    int i = 0;
    deque<char> alignment;

    while(nextPositionIndex != 0)
    {
        switch(mat[nextPositionIndex].direction)
        {
            case vertical:
                nextPositionIndex -= (sizeGen1+1);
                alignment.push_front(' ');
                (gen1).insert(i, "-", 1);
                break;
            case horizontal:
                nextPositionIndex -= 1;
                alignment.push_front(' ');
                break;
            case diagonal:
                int currentPositionIndex = nextPositionIndex;
                nextPositionIndex -= (sizeGen1+2);
                if(mat[currentPositionIndex].score > mat[nextPositionIndex].score)  // coinciden
                {
                    alignment.push_front('|');
                }
                else
                {
                    alignment.push_front('*');
                }
                break;
        }
        i++;
    }

    return alignment;

}