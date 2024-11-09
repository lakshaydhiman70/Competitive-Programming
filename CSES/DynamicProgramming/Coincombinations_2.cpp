#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n = 3, x = 9;
    vector<int>coins = {2, 3, 5};

    vector<vector<int>>dp(n+1, vector<int>(x+1));

    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    for(int i=n-1;i>=0;i--){
        for(int sum = 1; sum <= x; sum++){
            int skipping = dp[i+1][sum];
            int picking = 0;

            if(coins[i] <= sum){
                picking = dp[i][sum - coins[i]];
            }

            dp[i][sum] = (skipping + picking);
        }
    }

    cout<<dp[0][x];
}

int main(){
    solve();
}