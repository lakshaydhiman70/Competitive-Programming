// https://leetcode.com/problems/number-of-provinces/
// here we have have given a graph having multiple disconnected componenets we just 
// need to give the count of it as an answer.
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto edge: adj[node]){
        if(!vis[edge]){
            dfs(edge, adj, vis, ans);
        }
    }
}


int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int>adj[n];
    vector<int>vis(n,0);
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j] == 1 && i != j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(i, adj, vis, ans);
        }
    }
    return count;
}


int main(){
    vector<vector<int>>isConnected = {{1, 1, 0},{1, 1, 0},{0, 0, 1}};
    cout<<findCircleNum(isConnected);
}

//Tc - O(n) + O(v + 2E) 