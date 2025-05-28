#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dp(n, vector<int>(m));
    dp[0][0] = grid[0][0];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j==0){
                continue;
            }
            int minVal = INT_MAX;

            if(i-1 >= 0){
                minVal = min(minVal, dp[i-1][j]);
            }

            if(j-1 >= 0){
                minVal = min(minVal, dp[i][j-1]);
            }

            dp[i][j] = grid[i][j] + minVal;
        }
    }
    
    return dp[n-1][m-1];
}

int main(){
    vector<vector<int>>grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
}