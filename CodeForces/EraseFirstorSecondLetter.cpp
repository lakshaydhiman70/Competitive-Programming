#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 14;
    // cin>>n;
    string s = "bcdaaaabcdaaaa";
    // cin>>s;
    vector<int>dp(n);
    dp[0] = 1;

    for(int i=1; i<n; i++){
        int val = 0;
        if(s[i] == s[i-1]){
            val = dp[i-1] + 1;
        }
        else{
            val = dp[i-1] + 2;
        }

        dp[i] = val;
    }

    cout<<dp[n-1]<<endl;
}