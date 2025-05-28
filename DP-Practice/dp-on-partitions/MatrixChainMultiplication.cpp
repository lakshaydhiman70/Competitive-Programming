#include<bits/stdc++.h>
using namespace std;

int solveRecursive(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
    if(i == j)return 0;
    int minval = INT_MAX;

    if(dp[i][j] != -1)return dp[i][j];

    for(int k = i; k<j; k++){
        int val = solveRecursive(i, k, arr, dp) +
                    solveRecursive(k + 1, j, arr, dp) +
                    arr[i-1] * arr[k] * arr[j];

        minval = min(minval, val);
    }

    dp[i][j] = minval;
}

int tabulationSolution(vector<int>&arr, int n){
    vector<vector<int>>dp(n, vector<int>(n, 0));

    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j < n; j++){
            int mini = INT_MAX;

            for(int k = i; k < j; k++){
                int steps = arr[i-1] * arr[k] * arr[j]
                    + dp[i][k]
                    + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>>dp(N, vector<int>(N, -1));
    return solveRecursive(1, N-1, arr, dp);
}

int main(){

}