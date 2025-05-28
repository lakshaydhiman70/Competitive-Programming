#include<bits/stdc++.h>
using namespace std;

int solveRecursively(int row, int prevCol, vector<vector<int>> &points, vector<vector<int>>&dp){
    if(row < 0){
        return 0;
    }

    if(prevCol != -1 && dp[row][prevCol] != -1)return dp[row][prevCol];
    
    int val = 0;

    for(int i = 0; i < 3; i++){
        if(prevCol != i){
            val = max(val, solveRecursively(row - 1, i, points, dp) + points[row][i]);
        }
    }

    return dp[row][prevCol] = val;
}

int solveTabulation(int n, vector<vector<int>> &points) {
    // Create a DP table
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: Initialize the first day's activities
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];

    // Fill the DP table for subsequent days
    for (int i = 1; i < n; i++) {
        dp[i][0] = points[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = points[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = points[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    // The result is the maximum points possible on the last day
    return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int spaceOptimization(int n, vector<vector<int>> &points) {

    vector<int>temp(3);
    temp[0] = points[0][0];
    temp[1] = points[0][1];
    temp[2] = points[0][2];

    for (int i = 1; i < n; i++) {
        int temp1 = points[i][0] + max(temp[1], temp[2]);
        int temp2 = points[i][1] + max(temp[0], temp[2]); 
        int temp3 = points[i][2] + max(temp[0], temp[1]); 
        
        temp[0] = temp1;
        temp[1] = temp2;
        temp[2] = temp3;
    }

    return max({temp[0], temp[1], temp[2]});
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return solveRecursively(n-1, 3, points, dp);
}

int main(){
    vector<vector<int>> nums = {{1, 2, 5},
                                {3, 1, 1},
                                {3, 3, 3}};

    cout<<ninjaTraining(nums.size(), nums);
}