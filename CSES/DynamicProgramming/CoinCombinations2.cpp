#include<bits/stdc++.h>
using namespace std;
int main(){
    int x , n;
    cin>>x>>n;
    vector<int>a(n+1);

    vector<vector<int>>dp(n+1,vector<int>(x+1));

    for(int i = n-1; i>=0; i--){
        for(int sum = 1; sum<=x ; sum++){
            int skipping = dp[i+1][sum];
            int picking = 0;
            if(a[i]<=sum){
                picking = dp[i][sum - a[i]];
            }
            dp[i][sum] = (skipping+picking);
        }
    }
    cout<<dp[0][x]<<endl;
}