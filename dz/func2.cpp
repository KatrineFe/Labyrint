#include "Header1.h"

using namespace std;


bool solveMaze(vector<vector<int>>& maze, vector<vector<string>>& new_maze, Point start, Point end) {
    if (!isValid(start.x, start.y, maze) || !isValid(end.x, end.y, maze)) {
        return false;
    }

    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<int>> dist(rows, vector<int>(cols, -1));
    queue<Point> q;


    q.push(start);
    dist[start.x][start.y] = 0;


    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };


    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) {
            new_maze[curr.x][curr.y] = "*";
            return true;
        }


        for (int i = 0; i < 4; ++i) { //Расказать
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY, maze) && dist[newX][newY] == -1) {
                dist[newX][newY] = dist[curr.x][curr.y] + 1;
                q.push({ newX, newY });
                new_maze[curr.x][curr.y] = "*";
            }
        }
    }

    return false;
}