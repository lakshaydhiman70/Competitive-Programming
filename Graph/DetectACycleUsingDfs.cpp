#include<bits/stdc++.h>
using namespace std;

bool isCycle(int node, int parent, vector<int>adj[], vector<int>&vis){
    vis[node] = 1;

    for(auto edge: adj[node]){
        if(!vis[node]){
            if(isCycle(edge, node, adj, vis) == true){
                return true;
            }
        }
        else if(edge != parent){
            return true;
        }
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
   int n,m;
   cin>>n>>m;
   vector<int>adj[n+1]; 
   vector<int>vis(n+1);

    for(int j=0;j<m;j++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

   auto result = isCycle(1, -1, adj, vis);
   cout<<result;
}

// test case
// 7 7
// 1 2
// 1 6
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7