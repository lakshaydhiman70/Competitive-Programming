#include<bits/stdc++.h>
using namespace std;

vector<int>bellmanFord(int n, int src, vector<vector<int>>adj){
    int inf = INT_MAX;
    vector<int>dist(n+1, inf);
    dist[src] = 0;
    for(int i=0; i<n-1; i++){
        for(vector<int> it: adj){
            int source = it[0];
            int dest = it[1];
            int wt = it[2];

            if(dist[source]!= inf && dist[dest] > wt + dist[source]){
                dist[dest] = wt + dist[source];
            }
        }
    }

    for(int i=0; i<n-1; i++){
        for(vector<int> it: adj){
            int source = it[0];
            int dest = it[1];
            int wt = it[2];

            if(dist[source]!= inf && dist[dest] > wt + dist[source]){
                //-ve cycle exists
                for(int i=0; i<=n; i++){
                    dist[i] = -1;
                }
                return dist;
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    int src = 1; // Starting node

    vector<vector<int>> adj = {
        {1, 2, 6},
        {1, 3, 7},
        {2, 3, 8},
        {2, 4, 5},
        {2, 5, -4},
        {3, 4, -3},
        {4, 2, -2},
        {5, 4, 7}
    };

    vector<int> dist = bellmanFord(n, src, adj);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": INF\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }

    return 0;
}