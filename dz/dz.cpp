
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <fstream>

//git
//два файла
//++i

using namespace std;


struct Point {
    int x, y;
};


bool isValid(int x, int y, vector<vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0);
}


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

int main() {
    string name;
    cin >> name; 
    string line;
    int** d;
    Point start;
    Point end;

    ifstream file(name);
    int rows, cols;
    file >> rows >> cols;

    vector<vector<int>> maze(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> maze[i][j];
        }
    }
    file >> start.x >> start.y;
    file >> end.x >> end.y;
    file.close();

    vector<vector<string>> new_maze(rows, vector<string>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_maze[i][j] = to_string(maze[i][j]);
        }
    }
    
    setlocale(LC_ALL, "Russian");
    if (solveMaze(maze, new_maze, start, end)) {
        std::ofstream file(name, std::ios::app);
        file << "Лабиринт успешно пройден!" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                file << new_maze[i][j] << " ";
            }
            file << "\n";
        }
        file.close();
    }
    else {
        std::ofstream file(name, std::ios::app);
        file << "Лабиринт непроходим!" << endl;
        file.close();
    }

    return 0;
}