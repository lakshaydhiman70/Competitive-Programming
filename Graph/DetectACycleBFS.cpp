#include<bits/stdc++.h>
using namespace std;

bool isCycleUsingBfs(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];
    vector<int>vis(n+1);

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<pair<int,int>>que;
    que.push({1, -1});
    vis[1] = 1;

    while(!que.empty()){
        auto node = que.front();
        int nodemain = node.first;
        int parent = node.second;
        que.pop();

        for(auto edge: adj[nodemain]){
            if(!vis[edge]){
                que.push({edge, nodemain});
                vis[edge] = 1;
            }
            else if( edge != parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    auto result = isCycleUsingBfs();
    cout<<result;
}

// 7 7
// 1 2
// 1 6
// 2 3
// 3 4
// 4 5
// 5 6
// 6 7