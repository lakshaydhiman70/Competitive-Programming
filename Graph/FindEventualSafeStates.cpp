#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int>indegree(n);

    for(int i=0;i<n;i++){
        for(auto node: adj[i]){
            indegree[node]++;
        }
    }

    
}

int main(){

}