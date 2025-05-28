#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> RunFloydWarshall(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));

    // Initialize the distance matrix with graph weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != numeric_limits<int>::max() &&
                    dist[k][j] != numeric_limits<int>::max() &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}

// Utility function to print the distance matrix
void PrintMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            if (val == numeric_limits<int>::max()) {
                cout << "INF ";
            } else {
                cout << val << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 7},
        {3, 0, 1, 0, 0},
        {0, 1, 0, 2, 0},
        {0, 0, 2, 0, 4},
        {7, 0, 0, 4, 0}
    };

    vector<vector<int>> result = RunFloydWarshall(graph);
    
    cout << "Shortest distance matrix:" << endl;
    PrintMatrix(result);

    return 0;
}
