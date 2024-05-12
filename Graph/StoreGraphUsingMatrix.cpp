#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    int adj[n+1][n+1];
    memset(adj, 0, sizeof(adj));

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j] <<" ";
        }
        cout<<endl;
    }
}