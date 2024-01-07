#include <iostream>
#include <vector>
#include <string>

struct Point {
    int x, y;
};

bool solveMaze(vector<vector<int>>& maze, vector<vector<string>>& new_maze, Point start, Point end);
bool isValid(int x, int y, vector<vector<int>>& maze);

//:(((((((((((((((((((((((((((((
//))))))))))))))))))))))))))))):