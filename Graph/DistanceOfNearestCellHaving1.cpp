#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<pair<int,int>,int>>que;
    vector<vector<int>>vis(n, vector<int>(m, 0));
    vector<vector<int>>ans(n, vector<int>(m, 0));

    vector<pair<int,int>>distance = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                que.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    while(!que.empty()){
        auto front = que.front();
        que.pop();
        int row = front.first.first;
        int col = front.first.second;
        int steps = front.second;

        ans[row][col] = steps + 1;

        for(auto dist: distance){
            int nrow = row + dist.first;
            int ncol = col + dist.second;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                que.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return ans;
}


int main(){

}