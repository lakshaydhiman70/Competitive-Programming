#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraAlgo(int n, int src, vector<vector<pair<int,int>>>&adj){
    vector<int>dist(n+1, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        int parWt = node.first;
        int parNode = node.second;
        
        if(dist[parNode] < parWt){
            continue;
        }

        for(auto it: adj[parNode]){
            int childNode = it.first;
            int childWt = it.second;

            if(parWt + childWt < dist[childNode]){
                dist[childNode] = parWt + childWt;
                pq.push({parWt + childWt, childNode});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;  // number of nodes
    vector<vector<pair<int,int>>> adj(n + 1);  // 1-based indexing

    // Add edges: u -> v with weight w
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 4});
    adj[2].push_back({3, 1});
    adj[2].push_back({4, 7});
    adj[3].push_back({4, 3});
    adj[4].push_back({5, 1});

    int src = 1;
    vector<int> dist = dijkstraAlgo(n, src, adj);

    cout << "Shortest distances from node " << src << ":\n";
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}