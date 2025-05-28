#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int sum = 0;
    int n = prices.size();
    for(int i=0;i<n-1;i++){
        if(prices[i] < prices[i+1]){
            sum += (prices[i+1] - prices[i]);
        }
    }
    return sum;
}

int spaceOptimized(vector<int> &prices, int n, int fee) {
    vector<vector<int>>dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            if(j == 0){
                dp[i][j] = max(dp[i + 1][1] - prices[i], dp[i + 1][0]);
            }
            else{
                dp[i][j] = max(dp[i + 1][0] + prices[i] - fee, dp[i + 1][1]);
            }
        }
    }

    return dp[0][0];
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
	return spaceOptimized(prices, n, fee);
}

int main(){
    vector<int>prices = {};
    cout<<maxProfit(prices);   
}