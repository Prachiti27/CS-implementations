#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u,v, wt;
};

void bellmanFord(int v, vector<Edge>& edges, int src) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for(int i=1;i<=v-1;i++) {
        bool updated = false;

        for(auto edge:edges) {
            if(dist[edge.u]!=INT_MAX && dist[edge.v] + edge.wt < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.wt;
                updated = true;
            }
        }
        if(!updated) break;
    }

    for(auto edge:edges) {
        if(dist[edge.u]!=INT_MAX && dist[edge.u] + edge.wt < dist[edge.v]) {
            cout<<"Negative weight cycle detected\n";
            return;
        }
    }

    cout<<"\nShortest distances from source "<<src<<":\n";
    for(int i=0;i<v;i++) {
        cout<<"Vertex "<<i<<" -> ";
        if(dist[i] == INT_MAX) cout<<"INF";
        else cout<<dist[i];
        cout<<"\n";
    }
}

int main() {
    int v,e;
    cout<<"Enter number of vertices and edges: ";
    cin>>v>>e;
    vector<Edge> edges;

    cout << "Enter edges as: u v weight\n";

    for(int i=0;i<e;i++) {
        Edge e;
        cin>>e.u>>e.v>>e.wt;
        edges.push_back(e);
    }

    int src;
    cout<<"Enter source vertex : ";
    cin>>src;

    bellmanFord(v, edges, src);
}