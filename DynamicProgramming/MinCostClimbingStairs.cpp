#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int>dp(n+1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];

    /*
        State:
        dp[i] = min cost to climb at the ith stair.

        Transistion:
        dp[i] = dp[i]

        Base Case:
        dp[0] = cost[0];
        dp[1] = min(cost[0], cost[1]);
    */

    for(int i=2;i<n;i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    for(auto &it: dp){
        cout<<it<<" ";
    }

    cout<<endl;

    return min(dp[n-1], dp[n-2]);
}

int main(){
    vector<int>cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<minCostClimbingStairs(cost);
}