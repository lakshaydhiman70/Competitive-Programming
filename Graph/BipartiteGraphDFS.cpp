#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int color, vector<int>& colorarr, vector<vector<int>>& adj, vector<int>& vis){
    colorarr[node] = color;

    for(auto edge : adj[node]){
        if(colorarr[edge] == -1){
            if(dfs(edge, !color, colorarr, adj, vis) == true){
                return true;
            }
        }
        else if(colorarr[node] == colorarr[edge]){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adj){
    int n = adj.size();
    int m = adj[0].size();

    vector<int>colorarr(n, -1);
    vector<int>vis(n);
    
    for(int i=0;i<n;i++){
        if(!vis[i] && colorarr[i] == -1){
            if(dfs(i, 0, colorarr, adj, vis) == false){
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

    int n, m;
    cin>>n>>m;

    vector<vector<int>>adj(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    isBipartite(adj);
}