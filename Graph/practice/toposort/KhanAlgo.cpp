#include<bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> &adj){
    vector<int>ind(n);
    vector<int>ans;
    queue<int>que;

    for(int i=0; i<n; i++){
        for(int j = 0; j<adj[i].size(); j++){
            ind[adj[i][j]]++;
        }
    }

    for(int i=0; i<n; i++){
        if(ind[i] == 0){
            que.push(i);
        }
    }

    while (!que.empty()){
        int node = que.front();
        que.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            ind[it]--;
            if(ind[it] == 0){
                que.push(it);
            }
        }
    }
    
    for(int it: ans){
        cout<<it<<" ";
    }
}

int main(){
    int n = 6;
    vector<int>vis(n + 1);
    vector<vector<int>>adj(n, vector<int>(n));
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {0, 2};

    bfs(n, adj);
}