#include "Header1.h"


using namespace std;
bool isValid(int x, int y, vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}