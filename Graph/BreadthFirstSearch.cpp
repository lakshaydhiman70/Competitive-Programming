#include<bits/stdc++.h>
using namespace std;

void BfsTraversal(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin>>n>>m;
    int startingNode = 1;
    vector<int>adj[n+1];
    vector<int>vis(n+1, 0);
    queue<int>que;

    vis[startingNode] = 1;
    que.push(startingNode);
    vector<int>ans;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    while(!que.empty()){
        int front = que.front();
        que.pop();
        ans.push_back(front);

        for(int i=0;i<adj[front].size(); i++){
            int val = adj[front][i];
            if(vis[val] == 0){
                que.push(val);
                vis[val] = 1;
            }
        }
    }

    for(auto res: ans){
        cout<<res<<" ";
    }
}

int main(){
    BfsTraversal();
}

// Test Case
// 9 9
// 1 2 
// 1 6
// 2 3
// 2 4
// 6 7
// 6 9
// 4 5
// 7 8
// 5 8