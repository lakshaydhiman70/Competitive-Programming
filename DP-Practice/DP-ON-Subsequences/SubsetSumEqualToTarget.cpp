#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int n, int k, vector<int>&array, vector<vector<int>>&dp){
    if(k == 0)return true;
    if(i == n || k < 0){
        return false;
    }

    if(dp[i][k]!=-1)return dp[i][k];

    bool include = solve(i+1, n, k - array[i], array, dp);
    bool notInclude = solve(i+1, n, k, array, dp);
    
    return dp[i][k] = (include || notInclude);
}

bool SolveTabulation(int n, int k, vector<int>&array){
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int t = 1; t <= k; t++) {
            bool pick = false;
            if (array[i - 1] <= t) {
                pick = dp[i - 1][t - array[i - 1]];
            }

            bool nonPick = dp[i - 1][t];

            dp[i][t] = pick || nonPick;
        }
    }
    
    return dp[n][k];
}

bool subsetSumToK(int n, int k, vector<int> &array) {
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return solve(0, n, k, array, dp);
}

int main(){

}