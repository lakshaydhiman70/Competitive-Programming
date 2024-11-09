#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&vis, vector<int>&ans, vector<vector<int>>& adj){
    vis[node] = 1;
    
    for(auto edge: adj[node]){
        if(!vis[edge]){
            dfs(edge, vis, ans, adj);
        }
    }
    ans.push_back(node);
}

void topoSort(vector<vector<int>>&adj){
    int n = adj.size();

    vector<int>vis(n, 0);
    vector<int>ans;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, vis, ans, adj);
        }
    }

    for(int i = ans.size()-1; i>=0;i--){
        cout<<ans[i]<<" ";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin>>n>>m;
    vector<vector<int>>adj(n, vector<int>(m, 0));

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    topoSort(adj);
}