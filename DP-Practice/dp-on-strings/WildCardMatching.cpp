#include<bits/stdc++.h>
using namespace std;

bool checkAllStar(string str, int idx){
    for(int i = 0; i <= idx; i++){
        if(str[i] != '*') return false;
    }
    return true;
}

bool recursiveSol(int idx1, int idx2, string str, string str2, vector<vector<int>>&dp){

    if(idx1 < 0 && idx2 < 0){
        return true;
    }
    if(idx1 < 0 && idx2 >= 0){
        return false;
    }
    if(idx2 < 0 && idx1 >= 0){
        return checkAllStar(str, idx1);
    }

    if(dp[idx1][idx2] != -1)return dp[idx1][idx2];

    if(str[idx1] == str2[idx2] || str[idx1] == '?'){
        return dp[idx1][idx2] = recursiveSol(idx1 - 1, idx2 - 1, str, str2, dp);
    }
    else{
        if(str[idx1] == '*'){
            return dp[idx1][idx2] = recursiveSol(idx1 - 1, idx2, str, str2, dp) || recursiveSol(idx1, idx2 - 1, str, str2, dp);
        }
        return dp[idx1][idx2] = false;
    }
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.size(), m = text.size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return recursiveSol(n - 1, m - 1, pattern, text, dp);
}

int main(){
    string str1 = "abef", str2 = "abcdef";
    cout<<wildcardMatching(str1, str2);
}