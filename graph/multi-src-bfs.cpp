#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> multiSourceBFS(int n, vector<vector<int>> &adj, vector<int> &sources)
{
    vector<int> dist(n, -1);
    queue<int> q;

    for (int src : sources)
    {
        dist[src] = 0;
        q.push(src);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cout << "Enter number of source nodes: ";
    cin >> k;

    vector<int> sources(k);

    cout << "Enter source nodes:\n";
    for (int i = 0; i < k; i++)
        cin >> sources[i];

    vector<int> dist = multiSourceBFS(n, adj, sources);

    cout << "\nShortest distance from nearest source:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}