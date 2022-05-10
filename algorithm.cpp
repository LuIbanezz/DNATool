/**
 * @file algorithm.cpp
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Needleman-Wunsch algorithm manager.
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */

#include "algorithm.h"

/**
 * @brief Manages the general algorithm
 * 
 * @param gen1 : references string gen1
 * @param gen2 : references string gen2
 * @param sizeGen1 : size of string gen1
 * @param sizeGen2 : size of string gen2
 * @return string alignment
 */
string algorithm(string& gen1, string& gen2, size_t sizeGen1, size_t sizeGen2)
{
    char* pointerGen1 = &gen1[0];
    char* pointerGen2 = &gen2[0];

    AlgorithmData* mat = new AlgorithmData[(sizeGen1+1) * (sizeGen2+1)];

    mat[0].score = 0;
    mat[0].direction = 0;

    for(int i = 1 ; i <= (sizeGen1+1) ; i++)
    {
        mat[i].score = -i;
        mat[i].direction = horizontal;
    }

    for(int j = 1 ; j <= (sizeGen1+1) ; j++)
    {
        mat[j * (sizeGen2+1)].score = -j;
        mat[j * (sizeGen2+1)].direction = vertical;
    }

    calculateScoreandDirection(mat, pointerGen1, pointerGen2, sizeGen1, sizeGen2);
    
    string alignment = calculateOptimumPath(mat, sizeGen1, sizeGen2, gen1, gen2);

    return alignment;

    delete[] mat;
}

/**
 * @brief Fills cells of matrix with maximum score and the direction that maximises the score
 * using the Needleman-Wunsch algorithm
 * 
 * @param mat matrix with scores and direction
 * @param pointerGen1 pointer to first char of string Gen1
 * @param pointerGen2 pointer to first char of string Gen2
 * @param sizeGen1 size of string gen2
 * @param sizeGen2 size of string gen1
 */
void calculateScoreandDirection (AlgorithmData* mat, char* pointerGen1, char* pointerGen2, 
                                int sizeGen1, int sizeGen2)
{

    int verticalScore;
    int diagonalScore;
    int horizontalScore;
    int maxScore;

    for(int j = 1; j < (sizeGen1+1); j++)
    {
        for(int i = 1; i < (sizeGen2+1) ; i++)
        {
            verticalScore = mat[i+ ((j-1) * (sizeGen2+1))].score + INDELSCORE; 

            horizontalScore = mat[(i-1) + (j * (sizeGen2+1))].score + INDELSCORE;

            if(pointerGen1[j-1] == pointerGen2[i-1])
            {
                diagonalScore = mat[(i-1) + ((j-1) * (sizeGen2+1))].score + MATCHSCORE;
            }
            else
            {   
                diagonalScore = mat[(i-1) + ((j-1) * (sizeGen2+1))].score + SUSTSCORE;
            }

            if(verticalScore > horizontalScore)
            {
                maxScore = verticalScore;
                mat[i + (j * (sizeGen2+1))].direction = vertical;
            }
            else
            {
                maxScore = horizontalScore;
                mat[i + (j * (sizeGen2+1))].direction = horizontal;
            }

            if(diagonalScore > maxScore)
            {
                maxScore = diagonalScore;
                mat[i + (j * (sizeGen2+1))].direction = diagonal;
            }
            mat[i + (j * (sizeGen2+1))].score = maxScore;       
        }
    }
}


/**
 * @brief Calculates the alignment due to the optimum path 
 *        from cell [i,j] to cel [0,0] of the matrix
 * 
 * @param mat matrix with values and direction
 * @param sizeGen1 size of string Gen1
 * @param sizeGen2 size of string Gen2
 * @param gen1 refernce to string Gen1 (from main)
 * @param gen2 reference to string Gen2 (from main)
 * @return string alignment of Gen1 with Gen2
 */
string calculateOptimumPath(AlgorithmData* mat, int sizeGen1, int sizeGen2, string& gen1, string& gen2)
{
    int currentPositionIndex = (sizeGen1 + 1) * (sizeGen2 + 1) - 1;
    int nextPositionIndex = currentPositionIndex;

    int indexGen1 = sizeGen1;
    int indexGen2 = sizeGen2;

    int alignmentScore = 0;
    int amountOfSubstitutions = 0;
    int amountOfDeletions = 0;
    int amountOfInsertions = 0;
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
                alignmentScore += INDELSCORE;
                amountOfDeletions++;
                break;

            case horizontal:
                nextPositionIndex -= 1;
                alignment.push_back(' ');
                gen1.insert(indexGen1, "-", 1);
                indexGen2--;
                alignmentScore += INDELSCORE;
                amountOfInsertions++;
                break;

            case diagonal:
                int currentPositionIndex = nextPositionIndex;
                nextPositionIndex -= (sizeGen2+2);
                if(mat[currentPositionIndex].score > mat[nextPositionIndex].score)
                {
                    alignment.push_back('|');
                    alignmentScore += MATCHSCORE;
                }
                else
                {
                    alignment.push_back('*');
                    alignmentScore += SUSTSCORE;
                    amountOfSubstitutions++;
                }
                indexGen1--;
                indexGen2--;
                break;
        }
    }
    
    cout << "Optimum Alignment Score: " << alignmentScore << endl;
    cout << "Amount of Insetions: " << amountOfInsertions << endl;
    cout << "Amount of Deletions: " << amountOfDeletions << endl;
    cout << "Amount of Substitutions: " << amountOfSubstitutions << endl;

    string auxAlignment;

    for(int i = (alignment.size() -1); i >= 0; i--)
    {
        auxAlignment.push_back(alignment[i]);
    }
    
    return auxAlignment;
}