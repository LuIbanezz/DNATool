/**
 * @file algorithm.h
 * @authors	Lucía Ibañez, Lucía Ruiz.
 *
 * @brief Header for Needleman-Wunsch algorithm manager.
 *
 * @copyright Copyright (c) 2022 ~ EDA ~ ITBA
 *
 */

#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <string>
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