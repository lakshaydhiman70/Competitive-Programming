#include<bits/stdc++.h>
using namespace std;

void buildMinPathArray(int n, vector<int>&dist, vector<vector<pair<int,int>>>&adj, stack<pair<int,int>>&st){
    queue<pair<int,int>>que;
    while(!st.empty()){
        que.push(st.top());
        st.pop();
    }

    while(!que.empty()){
        auto node = que.front();
        que.pop();
        int num = node.first;
        int distval = node.second;

        for(auto it: adj[num]){
            if(dist[it.first] == 1e9 || dist[it.first] > distval + it.second){
                dist[it.first] = distval + it.second;
            }
        }
    }
}

void toposort(pair<int,int> node, vector<vector<pair<int,int>>>&adj, stack<pair<int,int>>&st, vector<int>&vis){
    vis[node.first] = 1;
    
    for(auto it: adj[node.first]){
        if(vis[it.first] == 0){
            toposort(it, adj, st, vis);
            vis[it.first] = 1;
        }
    }

    st.push(node);
}

int main(){
    int n = 7;
    vector<vector<pair<int,int>>>adj(n, vector<pair<int,int>>(n));

    adj[0] = {{1, 2}};
    adj[1] = {{3, 1}};
    adj[2] = {{3, 3}};
    adj[3] = {{}};
    adj[4] = {{0, 3}, {2, 1}};
    adj[5] = {{4, 1}};
    adj[6] = {{4, 2}, {5, 3}};

    vector<int>vis(n), dist(n, 1e9);
    stack<pair<int,int>>st;
    
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            toposort({i, -1}, adj, st, vis);
        }
    }

    buildMinPathArray(n, dist, adj, st);
    for(auto it: dist){
        cout<<it<<" ";
    }
}