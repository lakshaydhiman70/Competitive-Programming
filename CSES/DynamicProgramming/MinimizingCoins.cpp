//https://cses.fi/problemset/task/1634/
#include<bits/stdc++.h>
using namespace std;
const int maxCoins = 1e6 + 10;

void Solution(int n, vector<int>&coins, vector<int>&dp){
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i){
                auto test = dp[i-coins[j]]+1;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    
    if(dp[n]==1e9){
        cout<<-1;
    }
    else{
        cout<<dp[n];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin>>n>>k;
    
    vector<int>coins(n);
    for(auto &inp: coins){
        cin>>inp;
    }

    vector<int>dp(k+1, 1e9);
    Solution(k, coins,dp);
}