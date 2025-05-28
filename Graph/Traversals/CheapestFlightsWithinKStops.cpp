#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<pair<int,int>>>&adj, int n, int sourceNode, int destNode, int k){
    const int mod = 1e5;
    vector<int>dis(n+1, 1e5);
    dis[sourceNode] = 0;
    queue<pair<int, pair<int,int>>>que;
    que.push({0, {sourceNode, 0}});

    while(!que.empty()){
        auto frontnode = que.front();
        que.pop();
        int parNoOfNodes = frontnode.first;
        int parNode = frontnode.second.first;
        int parWt = frontnode.second.second;

        for(auto it: adj[parNode]){
            int node = it.first;
            int childWt = it.second;
            if((parWt + childWt) < dis[node] && (parNoOfNodes <= k)){
                que.push({parNoOfNodes + 1, {node, (parWt + childWt)}});
                dis[node] = parWt + childWt;
            }
        }
    }

    return dis[destNode] == mod? dis[destNode] : -1;
}

int main(){
    int nodes = 4;
    vector<vector<pair<int,int>>>adj(nodes);
    adj[0].push_back({1, 100});
    adj[1].push_back({2, 100});
    adj[1].push_back({3, 600});
    adj[2].push_back({0, 100});
    adj[2].push_back({3, 200});

    solve(adj, nodes, 0, 3, 1);
}