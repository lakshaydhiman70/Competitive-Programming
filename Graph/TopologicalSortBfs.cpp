#include<bits/stdc++.h>
using namespace std;

void topoSort(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>indegree(n, 0);
    vector<int>ans;

    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int>que;

    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n, vector<int>(m, 0));

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
}