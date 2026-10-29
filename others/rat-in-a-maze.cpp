#include <iostream>
#include <vector>
using namespace std;

bool solveMaze(vector<vector<int>>& maze,
               vector<vector<bool>>& visited,
               int row, int col, string& path,
               vector<string>& paths) {
    int n = maze.size();

    if (row < 0 || col < 0 || row >= n || col >= n ||
        maze[row][col] == 0 || visited[row][col])
        return false;

    if (row == n - 1 && col == n - 1) {
        paths.push_back(path);
        return true;
    }

    visited[row][col] = true;

    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char moves[] = {'D', 'L', 'R', 'U'};

    for (int i = 0; i < 4; i++) {
        path.push_back(moves[i]);
        solveMaze(maze, visited, row + dr[i],
                  col + dc[i], path, paths);
        path.pop_back();
    }

    visited[row][col] = false;
    return !paths.empty();
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> paths;
    string path;

    solveMaze(maze, visited, 0, 0, path, paths);

    if (paths.empty()) {
        cout << "No path exists\n";
    } else {
        cout << "Valid paths:\n";
        for (const string& p : paths)
            cout << p << '\n';
    }

    return 0;
}