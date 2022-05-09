#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <string>
#include <deque>
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


deque<char> algorithm(string&, string&, size_t, size_t);
void calculateScoreandDirection(AlgorithmData*, char*, char*, int, int);
deque<char> calculateOptimumPath(AlgorithmData*, int, int, string&, string&);

#endif//_ALGORITHM_H