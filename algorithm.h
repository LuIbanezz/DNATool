#include <string>
#include <vector>

using namespace std;


struct AlgorithmData
{
    int score;
    int direction;
    //bool vertical;
    //bool horizontal;
    //bool diagonal;
};

enum Direction
{
    vertical,
    horizontal,
    diagonal
};


vector<char> algorithm (char*, char*, int, int);
void calculateScoreandDirection (AlgorithmData* mat, char* gen1, char* gen2, int sizeGen1, int sizeGen2);
vector<char> calculateOptimumPath(AlgorithmData* mat, int sizeGen1, int sizeGen2);