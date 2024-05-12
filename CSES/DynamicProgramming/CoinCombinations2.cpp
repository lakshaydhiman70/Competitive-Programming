#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n = 3, target = 9;
  
  vector<int> coins = {2, 3, 5};

  vector<vector<int>>dp(n + 1, vector<int>(target + 1));

  for(int i=0;i<n;i++){
    dp[i][0] = 1;
  }

  for(int i = n-1; i>=0; i--){
    for(int sum = 1; sum<=target; sum++){
      int skipping = dp[i+1][sum];
      int picking = 0;
      if(coins[i] <= sum){
        picking = dp[i][sum - coins[i]];
      }
      dp[i][sum] = (skipping + picking);
    }
  }

  for(auto vec: dp){
    for(auto val: vec){
      cout<<val<<" ";
    }
    cout<<endl;
  }
  // cout<<dp[0][target];
}