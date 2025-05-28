#include<bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, INT_MAX));

    dp[0][0] = grid[0][0];


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (i == 0 && j == 0) continue;
            int mn = INT_MAX;
            if(i>0)mn = min(mn, dp[i-1][j]); 
            if(j>0)mn = min(mn, dp[i][j-1]); 

            dp[i][j] = grid[i][j] + mn;
        }
    }

    return dp[n-1][m-1];
}

int main(){
    vector<vector<int>>mat = {{5, 9, 6}, {11, 5, 2}};
    cout<<minSumPath(mat);
}