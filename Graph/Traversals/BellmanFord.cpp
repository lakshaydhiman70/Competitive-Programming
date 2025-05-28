#include<bits/stdc++.h>
using namespace std;

// Issue with Negative Weight Cycles 🚨
// A negative weight cycle in a graph creates an infinite loop of decreasing distances, which breaks the concept of shortest paths.


vector<int>bellmanFord(int n, int s, vector<vector<int>>&edges){
    int inf = 1e7;
    vector<int>dist(n+1, inf);
    dist[s] = 0;

    for(int i=0; i<n-1; i++){
        for(vector<int> it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[v] > dist[u] + wt){
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main() {

	int V = 4;
	vector<vector<int>> edges = {
        {0, 1, 5},  // Edge from 0 → 1 with weight 5
        {0, 2, 3},  // Edge from 0 → 2 with weight 3
        {0, 3, 2},  // Edge from 0 → 3 with weight 2
        {1, 4, -4}, // Edge from 1 → 4 with weight -4
        {2, 4, 1},  // Edge from 2 → 4 with weight 1
        {2, 5, 6},  // Edge from 2 → 5 with weight 6
        {3, 5, 2},  // Edge from 3 → 5 with weight 2
        {4, 5, -3}  // Edge from 4 → 5 with weight -3
    };

	int S = 0;
	vector<int> dist = bellmanFord(V, S, edges);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}
