#include<bits/stdc++.h>
using namespace std;

//problem link: https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-iv_1080698

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

int solveTabulationSpaceOpti(vector<int> &prices, int n, int k){
    vector<vector<int>>prev(2, vector<int>(k+1));
    vector<vector<int>>curr(2, vector<int>(k+1));

    for(int i=n-1; i >= 0; i--){
        for(int j=0;j<2;j++){
            for(int l = 1; l <= k; l++){
                if(j == 0){
                    curr[j][l] = max(prev[1][l] - prices[i], prev[0][l]);
                }
                else{
                    curr[j][l] = max(prev[0][l-1] + prices[i], prev[1][l]);
                }
            }
        }
        
        prev = curr;
    }

    return prev[0][k];
}
//best approach that should work here because the values we are using from dp is not getting updated while iterting.
int spaceOptimized(vector<int> &prices, int n, int k) {
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            for (int l = 1; l <= k; l++) {
                if (j == 0) {
                    dp[j][l] = max(dp[1][l] - prices[i], dp[0][l]);
                } else {
                    dp[j][l] = max(dp[0][l - 1] + prices[i], dp[1][l]);
                }
            }
        }
    }

    return dp[0][k];
}

int solveTabulation(vector<int> &prices, int n, int k){
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1)));
    for(int i=n-1; i >= 0; i--){
        for(int j=0;j<2;j++){
            for(int l = 1; l <= k; l++){
                if(j == 0){
                    dp[i][j][l] = max(dp[i + 1][1][l] - prices[i], dp[i+1][0][l]);
                }
                else{
                    dp[i][j][l] = max(dp[i + 1][0][l-1] + prices[i], dp[i+1][1][l]);
                }
            }
        }
    }
    return dp[0][0][k];
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    return solveTabulationSpaceOpti(prices, n, k);
}

int maxProfit(vector<int>& prices){
    int k = 2;
    vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solveRecursively(0, 1, 2, prices, dp);
}

int main(){
    vector<int>Prices = {7, 1, 5, 3, 6, 4};
    cout<<maxProfit(Prices)<<endl;
    cout<<maximumProfit(Prices, Prices.size(), 2);
}