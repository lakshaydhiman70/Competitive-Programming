#include<bits/stdc++.h>
using namespace std;

vector<int> TopologicalSortBFS(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    vector<int> topoOrder;
    
    // Compute in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    // Push nodes with in-degree 0 to queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Reduce in-degree of adjacent nodes
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If all nodes are processed, return topo order, else return empty (cycle detected)
    return (topoOrder.size() == V) ? topoOrder : vector<int>{};
}

int main() {
    int V = 6;
    vector<vector<int>> adj = {
        {2, 3},   // 0 -> 2, 0 -> 3
        {3, 4},   // 1 -> 3, 1 -> 4
        {5},      // 2 -> 5
        {5},      // 3 -> 5
        {},       // 4 has no outgoing edges
        {}        // 5 has no outgoing edges
    };

    vector<int> result = TopologicalSortBFS(V, adj);
    
    if (result.empty()) {
        cout << "Cycle detected! No topological ordering possible." << endl;
    } else {
        cout << "Topological Sort (BFS): ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
