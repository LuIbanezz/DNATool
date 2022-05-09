#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <string>
#include <deque>
#include <list>
#include <stdlib.h>
#include <iostream>
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


string algorithm(string&, string&, size_t, size_t);
void calculateScoreandDirection(AlgorithmData*, char*, char*, int, int);
string calculateOptimumPath(AlgorithmData*, int, int, string&, string&);

#endif//_ALGORITHM_H