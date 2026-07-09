#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, wt;

    bool operator<(const Edge &other) const
    {
        return wt < other.wt;
    }
};

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;

        else if (rank[px] > rank[py])
            parent[py] = px;

        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }
};

int kruskal(int V, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());

    DSU dsu(V);

    int mstCost = 0;
    int edgeCount = 0;

    cout << "\nEdges in MST:\n";

    for (auto edge : edges)
    {
        if (dsu.find(edge.u) != dsu.find(edge.v))
        {
            dsu.unite(edge.u, edge.v);

            mstCost += edge.wt;
            edgeCount++;

            cout << edge.u << " - " << edge.v
                 << " : " << edge.wt << endl;

            if (edgeCount == V - 1)
                break;
        }
    }

    return mstCost;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter edges as: u v weight\n";

    for (int i = 0; i < E; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.wt;
        edges.push_back(e);
    }

    int cost = kruskal(V, edges);

    cout << "\nMinimum Spanning Tree Cost = "
         << cost << endl;

    return 0;
}