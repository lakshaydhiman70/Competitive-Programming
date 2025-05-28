#include<bits/stdc++.h>
using namespace std;

int solveRecursive(int idx, int prev, int arr[], int n, vector<vector<int>>&dp) {
    if (idx >= n) {
        return 0;
    }

    if(dp[idx][prev + 1] != -1){
        return dp[idx][prev + 1];
    }

    int notPick = solveRecursive(idx + 1, prev, arr, n, dp);

    int pick = 0;
    if (arr[idx] > arr[prev + 1]) {
        //here we are checking if the condition is matching and then we shall call for the next.
        pick = 1 + solveRecursive(idx + 1, idx, arr, n, dp);
    }

    return dp[idx][prev + 1] = max(pick, notPick);
}


int tabulationSol(int arr[], int n) {
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Tabulation logic (bottom-up)
    for (int i = n - 1; i >= 0; i--) {
        for (int prev = i - 1; prev >= -1; prev--) {
            int notPick = dp[i + 1][prev + 1];  // Don't pick the current element

            int pick = 0;
            if (prev == -1 || arr[i] > arr[prev]) {
                pick = 1 + dp[i + 1][i + 1];  // Pick the current element
            }

            dp[i][prev + 1] = max(pick, notPick);
        }
    }

    return dp[0][0];  // The answer is stored at dp[0][0]
}

int tabulationSpaceOptSol(int arr[], int n) {
    // Initialize DP table
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    vector<int>prev(n+1);
    vector<int>curr(n+1);

    // Tabulation logic (bottom-up)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
            int notPick = prev[j + 1];  // Don't pick the current element

            int pick = 0;
            if (j == -1 || arr[i] > arr[j]) {
                pick = 1 + prev[i + 1];  // Pick the current element
            }

            curr[j + 1] = max(pick, notPick);
        }
        prev = curr;
    }

    return curr[0];  // The answer is stored at dp[0][0]
}


int longestIncreasingSubsequence(int arr[], int n) {
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    return solveRecursive(0, -1, arr, n, dp);
}

int main(){
    int arr[] = {5, 8, 2, 6, 3, 10, 12};
    cout<<longestIncreasingSubsequence(arr, 7);
}