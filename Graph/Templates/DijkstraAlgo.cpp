#include<bits/stdc++.h>
using namespace std;

// Edge structure
struct Edge {
    int destination;
    int weight;
};

// Dijkstra's Algorithm to find the shortest distance from `source`
unordered_map<int, int> findShortestDistance(int source, unordered_map<int, vector<Edge>>& graph) {
    unordered_map<int, int> distance;
    unordered_map<int, int> previousNode;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distances to infinity
    for (const auto& node : graph) {
        distance[node.first] = numeric_limits<int>::max();
        previousNode[node.first] = -1;
    }

    // Start from the source
    distance[source] = 0;
    pq.push({0, source}); // {distance, node}

    while (!pq.empty()) {
        auto currentDistance = pq.top().first;
        auto currentNode = pq.top().second;
        pq.pop();

        // If current distance is already more than recorded, skip it
        if (currentDistance > distance[currentNode]) continue;

        for (const auto& neighbor : graph[currentNode]) {
            int neighborNode = neighbor.destination;
            int newDistance = currentDistance + neighbor.weight;

            if (newDistance < distance[neighborNode]) {
                distance[neighborNode] = newDistance;
                previousNode[neighborNode] = currentNode;
                pq.push({newDistance, neighborNode});
            }
        }
    }

    return distance;
}

// Example usage
int main() {
    unordered_map<int, vector<Edge>> graph;

    // Adding edges
    graph[0] = {{1, 4}, {2, 1}};
    graph[1] = {{3, 1}};
    graph[2] = {{1, 2}, {3, 5}};
    graph[3] = {};

    int source = 0;
    unordered_map<int, int> shortestDistances = findShortestDistance(source, graph);

    cout << "Shortest distances from source node " << source << ":\n";
    for (const auto &it : shortestDistances) {
        auto node = it.first;
        auto dist = it.second;
        cout << "Node " << node << " -> Distance: " << (dist == numeric_limits<int>::max() ? -1 : dist) << endl;
    }

    return 0;
}
