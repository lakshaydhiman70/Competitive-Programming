#include<bits/stdc++.h>
using namespace std;

int recursiveSolution(int n, int k, vector<int> &height, vector<int>&dp){
    if(n == 0)return 0;
    if(dp[n]!=-1)return dp[n];
    int val = INT_MAX;
    for(int i=1; i <= k; i++){
        if(n - i >= 0){
            val = min(val, recursiveSolution(n - i, k, height, dp) + abs(height[n] - height[n - i]));
        } 
    }
    return dp[n] = val;
}

int tabulationSolution(int n, int k, vector<int> &height){
    vector<int>dp(n);
    dp[0] = 0;
    for(int i=1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                dp[i] = dp[i-j] + abs(height[i] - height[i-j]);
            }
        }
    }
    return dp[n];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int>dp(n, -1);
    //return recursiveSolution(n-1, k, height, dp);
    return tabulationSolution(n-1, k, height);
}

int main(){
    vector<int>height = {10, 50, 10, 50, 10, 10};
    cout<<minimizeCost(height.size(), 2, height);
}