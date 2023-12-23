#include <vector>
#include <iostream>
#include "Header1.h"
bool isValid(int x, int y, vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}