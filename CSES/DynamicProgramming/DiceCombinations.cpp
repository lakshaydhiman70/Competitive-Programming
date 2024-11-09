#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;

int diceComb(int n){
    vector<int>dp(n+1, 0);
    dp[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=6; j++){
            if(i - j >= 0){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    return dp[n];
}

int diceComb2(int n){
    vector<int>dp(n+1);
    dp[n] = 1;

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=6;j++){
            if(j<= n-i){
                dp[i] = dp[i] + dp[i+j];
            }
        }
    }
    return dp[0];
}

int main(){
    int n = 4;
    // cin>>n;
    auto ans = diceComb(n);
    auto ans1 = diceComb2(n);
    cout<<ans<<" "<<ans1;
}