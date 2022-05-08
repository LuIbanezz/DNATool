#ifndef _ALGOTIRHM_H
#define _ALGORITHM_H

#include <string>
#include <vector>
#define INDELSCORE -1
#define MATCHSCORE 1
#define SUSTSCORE -1

using namespace std;


struct AlgorithmData
{
    int score;
    int direction;
};

enum Direction
{
    vertical,
    horizontal,
    diagonal
};


vector<char> algorithm (char*, char*, size_t, size_t);
void calculateScoreandDirection (AlgorithmData*, char*, char*, int, int);
vector<char> calculateOptimumPath(AlgorithmData*, int, int);

#endif//_ALGORITHM_H