#include<bits/stdc++.h>
using namespace std;

// Edge structure
struct Edge {
    int destination;
    int weight;
};

// Prim's Algorithm to find MST total weight
int runPrim(int vertices, vector<vector<Edge>>& graph) {
    // Min-heap (priority queue) to select the minimum weight edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> inMST(vertices, false); // To check if a node is already in MST
    int totalWeight = 0;

    // Start from node 0
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        auto weight = pq.top().first;
        auto node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue; // Skip if already added to MST

        inMST[node] = true;
        totalWeight += weight;

        for (const auto& neighbor : graph[node]) {
            if (!inMST[neighbor.destination]) {
                pq.push({neighbor.weight, neighbor.destination});
            }
        }
    }

    return totalWeight;
}

// Example usage
int main() {
    int vertices = 5;
    vector<vector<Edge>> graph(vertices);

    // Adding edges
    graph[0] = {{1, 2}, {3, 6}};
    graph[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    graph[2] = {{1, 3}, {4, 7}};
    graph[3] = {{0, 6}, {1, 8}};
    graph[4] = {{1, 5}, {2, 7}};

    int totalMSTWeight = runPrim(vertices, graph);
    cout << "Total Minimum Spanning Tree Weight: " << totalMSTWeight << endl;

    return 0;
}
