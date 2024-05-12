#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ans){
    vis[node] = 1;
    ans.push_back(node);
    //we can remove the recursion with stack
    for(int i=0;i<adj[node].size();i++){
        int val = adj[node][i];
        if(!vis[val]){
            dfs(val, adj, vis, ans);
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int startingNode = 1;
    vector<int>adj[n+1];
    vector<int>vis(n+1, 0);
    vector<int>ans;

    for(int i = 0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(startingNode, adj, vis, ans);

    for(auto res: ans){
        cout<<res<<" ";
    }
}

//space complexity - O(n)
//Time complexity - O(n) + O(2*E) no of edges as we are traversing every edge two time