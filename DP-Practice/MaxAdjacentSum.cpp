#include<bits/stdc++.h>
using namespace std;

//recursion
int fun(int idx, vector<int>&vec, vector<int>&dp){

    if(idx < 0)return 0;
    if(idx == 0)return vec[idx];

    if(dp[idx] != -1)return dp[idx];

    //pick
    int pick = vec[idx] + fun(idx - 2, vec, dp);
    //not pick
    int notPick = fun(idx - 1, vec, dp);  

    int mx = max(pick, notPick);

    return dp[idx] = mx;
}

//tabulation
int fun(vector<int>&vec){
    int n = vec.size();
    vector<int>dp(n);

    dp[0] = vec[0];
    dp[1] = max(vec[1], vec[0]);

    for(int i=2;i<n;i++){

        int take = vec[i] + dp[i-2];
        int notTake = dp[i-1];

        dp[i] = max(take, notTake);
    }
    return dp[n-1];
}

//tabulation with space optimization
int funSpace(vector<int>&vec){
    int n = vec.size();
    int prev2 = vec[0];
    int prev = max(vec[1], vec[0]);
    int curr = prev;

    for(int i=2;i<n;i++){

        int take = vec[i] + prev2;
        int notTake = prev;

        curr = max(take, notTake);
        
        prev2 = prev;
        prev = curr;
        
    }
    return curr;
}

int main(){
    vector<int>vec = {1, 2, 3, 4, 5};
    cout<<fun(vec);
    cout<<endl;
    cout<<funSpace(vec);
}
