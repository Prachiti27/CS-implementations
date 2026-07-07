#include <bits/stdc++.h>

using namespace std;

int primMST(int v, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(v, false);
    int totalCost = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        totalCost += wt;

        for(auto [weight, v]:adj[u]) {
            if(!visited[v]) {
                pq.push({weight, v});
            }
        }
    }
    return totalCost;
}

int main() {
    int v,e;
    cout<<"Enter number of vertices and edges : ";
    cin>>v>>e;

    vector<vector<pair<int,int>>> adj(v);

    cout<<"Enter edges as: u v weight"<<endl;

    for(int i=0;i<e;i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt, v});
        adj[v].push_back({wt, u});
    }
    int cost = primMST(v, adj);
    cout<<"Cost of MST : "<<cost<<endl;
}