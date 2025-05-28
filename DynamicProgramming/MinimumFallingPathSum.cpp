#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp = matrix;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int minVal = dp[i-1][j];

            if (j > 0) {
                minVal = min(minVal, dp[i-1][j-1]);
            }
            
            if (j < m - 1) {
                minVal = min(minVal, dp[i-1][j+1]);
            }

            dp[i][j] += minVal;
        }
    }

    int result = dp[n-1][0];
    for (int j = 1; j < m; j++) {
        result = min(result, dp[n-1][j]);
    }

    return result;
}


int main(){
    vector<vector<int>>grid = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(grid);
}