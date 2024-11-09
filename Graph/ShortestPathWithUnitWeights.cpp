#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<vector<int>>adj(N);
    for(int i=0;M;i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int>que;

}

int main(){
    vector<vector<int>>graph = {{1,2,3},{0},{0},{0}};
    
}