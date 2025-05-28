#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n+1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2;i<n;i++){
        dp[i] = max((dp[i-2] + nums[i]), dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    vector<int>inp = {2, 1, 4, 9};
    cout<<maximumNonAdjacentSum(inp);
}