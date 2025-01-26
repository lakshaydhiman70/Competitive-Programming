#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<vector<int>> &mat){
    vector<vector<int>>dp(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] != -1){
                if(i>0)dp[i][j]+= dp[i-1][j];
                if(j>0)dp[i][j]+= dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return solve(n, m, mat);
}

int main(){
    vector<vector<int>>mat = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
    cout<<mazeObstacles(mat.size(), mat[0].size(), mat);
}