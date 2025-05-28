#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src) {
    // Min-heap priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    que.push({0, src});

    while (!que.empty()) {
        auto minNode = que.top();
        que.pop();
        int node = minNode.second;
        int wt = minNode.first;

        for (auto it : adj[node]) {
            int childNode = it.first;
            int edgeWeight = it.second;
            if (wt + edgeWeight < dist[childNode]) {
                dist[childNode] = wt + edgeWeight;
                que.push({dist[childNode], childNode});
            }
        }
    }
    return dist;
}

int main() {
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({4, 1});
    adj[4].push_back({0, 1});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[2].push_back({3, 6});
    adj[3].push_back({2, 6});

    adj[3].push_back({5, 1});
    adj[5].push_back({3, 1});

    adj[4].push_back({5, 4});
    adj[5].push_back({4, 4});

    adj[4].push_back({2, 2});
    adj[2].push_back({4, 2});

    vector<int> ans = dijkstra(n, adj, 0);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}
