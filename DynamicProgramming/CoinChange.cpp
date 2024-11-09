#include<bits/stdc++.h>
using namespace std;

/*
    State:
        dp[i] = minimum number of coins needed to make the sum i;

    Transistion:
        sum of 

    Basecase:
*/

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int>dp(amount+1, amount+1);
    dp[0] = 0;
    for(int i=1; i<=amount; i++){
        for(int j=0; j<n; j++){
            if(i-coins[j] >= 0){
                dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
            }
        }
    }
    return dp[amount] > amount?  -1 : dp[amount];
}

int main(){
    vector<int>coins = {2};
    int k = 3;
    cout<<coinChange(coins, k);
}