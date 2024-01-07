#pragma once
#ifndef HEADER1_H
#define HEADER1_H
#include <queue>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

bool solveMaze(vector<vector<int>>& maze, vector<vector<string>>& new_maze, Point start, Point end);
bool isValid(int x, int y, vector<vector<int>>& maze);
#endif HEADER1_H