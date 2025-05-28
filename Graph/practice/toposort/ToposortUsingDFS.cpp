#include<bits/stdc++.h>
using namespace std;

void toposort(int node, vector<vector<int>> &adj, stack<int> &st, vector<int> &vis){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            toposort(it, adj, st, vis);
        }
    }
    
    st.push(node);
}

int main(){
    int n = 6;
    vector<int>vis(n + 1);
    stack<int>st;
    vector<vector<int>>adj(n, vector<int>(n));
    adj[0] = {};
    adj[1] = {};
    adj[2] = {3};
    adj[3] = {1};
    adj[4] = {0, 1};
    adj[5] = {0, 2};

    for(int i=0; i<n; i++){
        if(!vis[i]){
            toposort(i, adj, st, vis);   
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}