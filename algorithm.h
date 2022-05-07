#include <string>
#include <vector>


struct AlgorithmData
{
    int score;
    bool vertical;
    bool horizontal;
    bool diagonal;
};


void algorithm (char*, char*, int, int);