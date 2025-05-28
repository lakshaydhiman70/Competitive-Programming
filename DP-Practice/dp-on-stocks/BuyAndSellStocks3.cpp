#include<bits/stdc++.h>
using namespace std;

//problem link: https://www.naukri.com/code360/problems/buy-and-sell-stock_1071012

int solveRecursively(int idx, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>&dp){
    if(idx == prices.size())return 0;
    if(k == 0)return 0;
    
    if(dp[idx][buy][k] != -1)return dp[idx][buy][k];

    if(buy){
        return dp[idx][buy][k] = max(solveRecursively(idx + 1, 0, k, prices, dp) - prices[idx], 
                    solveRecursively(idx + 1, 1, k, prices, dp));
    }
    else{
        return dp[idx][buy][k] = max(solveRecursively(idx + 1, 1, k - 1, prices, dp) + prices[idx],
                    solveRecursively(idx + 1, 0, k, prices, dp));
    }
}

int maxProfit(vector<int>& prices){
    int k = 2;
    vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solveRecursively(0, 1, 2, prices, dp);
}

int main(){
    vector<int>Prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(Prices);
}