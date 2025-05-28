#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>&vispath){
    vis[node] = 1;

    for(auto edge: adj[node]){
        if(!vis[edge]){
            if(dfs(edge, adj, vis, vispath) == true){
                return false;
            }
        }
        else if(vispath[edge]){
            return true;
        }
    }
    vispath[node] = 0;
    return false;
}

bool detectCycle(vector<vector<int>>& adj){
    int n = adj.size();
    int m = adj[0].size();

    vector<int>vis(n, 0);
    vector<int>vispath(n, 0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, vispath)){
                return true;
            }
        }
    }
    return false;
}

int main(){

}