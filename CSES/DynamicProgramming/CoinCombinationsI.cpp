#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

void coinCombinations(int k, vector<int>&coins, vector<int>&dp){
    dp[0] = 1;

    for(int i = 1; i<=k; i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i ){
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }
    for(auto &res: dp){
        cout<<res<<" ";
    }
    cout<<"\n";
    for(int i=0;i<=k;i++){
        cout<<i<<" ";
    }
    cout<<dp[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n,k;
    cin>>n>>k;
    vector<int>coins(n);
    vector<int>dp(k+1);
    
    for(auto &inp: coins){
        cin>>inp;
    }
    
    coinCombinations(k, coins, dp);
}