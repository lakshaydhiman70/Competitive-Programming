#include<bits/stdc++.h>
using namespace std;

int spaceOptimized(vector<int> &prices, int n, int fee) {
	vector<int>dp(2, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) {
            if(j == 0){
                dp[j] = max(dp[1] - prices[i], dp[0]);
            }
            else{
                dp[j] = max(dp[0] + prices[i] - fee, dp[1]);
            }
        }
    }

    return dp[0];
}

int maximumProfit(vector<int> &prices, int n, int fee)
{
	return spaceOptimized(prices, n, fee);
}

int main(){
    cout<<maximumProfit<<endl;
}