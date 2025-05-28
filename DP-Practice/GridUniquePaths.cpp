#include<bits/stdc++.h>
using namespace std;

int solve(int n, int m, vector<vector<int>>&dp){
    
    if(n == 0 && m == 0)return 1;
    if(n < 0 || m < 0)return 0;

    if(dp[n][m]!=-1)return dp[n][m];

    int left = solve(n, m - 1, dp);
    int up = solve(n-1, m, dp);

    return dp[n][m] = (left + up);
}

int solveTabulation(int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}

int uniquePaths(int n, int m) {
    vector<vector<int>>dp(n, vector<int>(m, -1));
	return solveTabulation(n-1, m-1);
}

int main(){
    int n = 2, m = 2;
    cout<<uniquePaths(n, m);
}