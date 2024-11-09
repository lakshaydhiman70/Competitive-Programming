#include<bits/stdc++.h>
using namespace std;


int minimizeCost(int n, int k, vector<int> &h){
    vector<int>dp(n, INT_MAX);
    dp[0] = 7;

    for(int i=1;i<n;i++){

        for(int j=0;j<k;j++){
            if(j<i){
                int val = min(abs(h[i-j-1] - h[i]) + dp[i-j-1], dp[i]);
                dp[i] = val;
            }
        }
    }

    return dp[n-1];
}

int main(){
    vector<int>inp = {7, 1, 4, 0};
    cout<<minimizeCost(inp.size(), 3, inp);
}