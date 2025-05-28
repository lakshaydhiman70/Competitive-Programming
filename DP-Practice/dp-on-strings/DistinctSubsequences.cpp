#include<bits/stdc++.h>
using namespace std;

int solveRecursive(int idx1, int idx2, int n, int m, string &str, string &sub, vector<vector<int>>&dp, int mod){
    if(idx2<0){
        return 1;
    }

    if(idx1<0){
        return 0;
    }

    if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
    }

    if(str[idx1] == sub[idx2]){
        int val1 = solveRecursive(idx1 - 1, idx2 - 1, n, m, str, sub, dp, mod);
        int val2 = solveRecursive(idx1 - 1, idx2, n, m, str, sub, dp, mod);
        return dp[idx1][idx2] = (val1 + val2)%mod;
    }
    else{
        return dp[idx1][idx2] = (solveRecursive(idx1 - 1, idx2, n, m, str, sub, dp, mod)) % mod;
    }
}

int distinctSubsequences(string &str, string &sub)
{
    int mod = 1e7;
    int n = str.size(), m = sub.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
	return solveRecursive(n-1, m-1, n, m, str, sub, dp, mod);
}

int main(){
    string str = "aaaaa", sub = "a";
    cout<<distinctSubsequences(str, sub);
}