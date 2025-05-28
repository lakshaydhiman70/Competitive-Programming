#include<bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>>adj(n);
    vector<int>ind(n), ans;
    queue<int>que;

    for(auto it: pre){
        adj[it[1]].push_back(it[0]);
    }

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
    
    return ans.size() == n;
}

int main(){
    vector<vector<int>>pre = {{1, 0}, {2, 1}, {3, 2}};
    
}