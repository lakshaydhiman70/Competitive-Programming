#include<bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n);
    dp[0] = nums[0];
    dp[1] = nums[1];

    for(int i=2;i<n;i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

int main(){
    vector<int>nums = {1,2,3,1};
    int ans = rob(nums);
    cout<<ans;
}