//TC - O(ElogV), SC - O(V)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y;
    int g, f;

    bool operator>(const Node &other) const
    {
        return f > other.f;
    }
};

int heuristic(int x, int y, int dx, int dy)
{
    return abs(x - dx) + abs(y - dy);
}

int main()
{
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,1,0,1},
        {0,0,0,0}
    };

    int n = grid.size();
    int m = grid[0].size();

    pair<int,int> src = {0,0};
    pair<int,int> dest = {2,3};

    vector<vector<int>> g(n, vector<int>(m, INT_MAX));

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    g[src.first][src.second] = 0;

    pq.push({
        src.first,
        src.second,
        0,
        heuristic(src.first, src.second, dest.first, dest.second)
    });

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        if(cur.x == dest.first && cur.y == dest.second)
        {
            cout << "Shortest Distance = " << cur.g << endl;
            return 0;
        }
        for(int k=0;k<4;k++)
        {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if(nx<0 || ny<0 || nx>=n || ny>=m)
                continue;
            if(grid[nx][ny]==1)
                continue;
            int newG = cur.g + 1;
            if(newG < g[nx][ny])
            {
                g[nx][ny] = newG;
                int newF = newG + heuristic(nx, ny,dest.first,dest.second);
                pq.push({nx, ny, newG, newF});
            }
        }
    }
    cout << "No Path Exists\n";
    return 0;
}