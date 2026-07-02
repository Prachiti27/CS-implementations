#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        if(currDist > dist[u]) continue;

        for(auto [v, wt] : adj[u]) {
            if(dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int v,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;

    vector<vector<pair<int, int>>> adj(v);

    cout<<"Enter each edge as: u v weight\n";

    for(int i=0;i<e;i++) {
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    int src;
    cout<<"Enter source vertex: ";
    cin>>src;

    vector<int> dist = dijkstra(v, adj, src);

    cout<<"Shortest distance from source "<<src<<":\n";

    for(int i=0;i<v;i++) {
        cout<<"Vertex "<<i<<" -> ";
        if(dist[i] == INT_MAX) cout<<"INF";
        else cout<<dist[i];
        cout<<"\n";
    }
}