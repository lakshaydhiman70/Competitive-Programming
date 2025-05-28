// https://leetcode.com/problems/is-graph-bipartite/submissions/1263121511/
#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, int currcolor, vector<vector<int>>& adj, vector<int>& color){
    queue<int>que;
    que.push(node);
    
    color[node] = 0;

    while(!que.empty()){
        int front = que.front();
        que.pop();

        for(auto edge : adj[front]){
            if(color[edge] == -1){
                color[edge] = !color[front];
                que.push(edge);
            }
            else if(color[edge] == color[front]){
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& adj){
    int n = adj.size();
    int m = adj[0].size();

    vector<int>color(n, -1);

    for(int i=0;i<n;i++){
        if(color[i] == -1){
            if(bfs(i, color[i], adj, color) == false){
                return false;
            }
        }
    }

    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // bool ans = isBipartite(); // provide adjecency list here with graph co-oridinates

    // cout<<ans;
}

//Bi partite graph
// 10 10
// 0 1
// 1 2
// 2 3
// 2 7
// 3 4
// 7 6
// 4 5
// 6 5
// 5 8
// 8 9