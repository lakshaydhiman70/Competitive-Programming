#include<bits/stdc++.h>
using namespace std;

int solve(int idx1, int idx2, string a, string b, vector<vector<int>>&dp){
    if(idx1 < 0 || idx2 < 0){
        return 0;
    }

	if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];

    int value = 0;

    if(a[idx1] == b[idx2]){
        value = 1 + solve(idx1 - 1, idx2 - 1, a, b, dp);
        return dp[idx1][idx2] = value;
    }
    else{
        int val1 = solve(idx1 - 1, idx2, a, b, dp);
        int val2 = solve(idx1, idx2 - 1, a, b, dp);
        return dp[idx1][idx2] = max(val1, val2);
    }
}

int tabulationSolution(string &s, string &t){
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

string GetLcsString(string &s, string &t){
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";
    int length = dp[n][m];
    int idx = length - 1;
    for(int i=0;i<length;i++){
        ans+='$';
    }

    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans[idx] = s[i-1];
            i--;
            j--;
            idx--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }

    return ans;
}

int lcs(string s, string t)
{
	int n = s.size(), m = t.size();
	vector<vector<int>>dp(n, vector<int>(m, -1));
	return solve(n - 1, m - 1, s, t, dp);
    return tabulationSolution(s,t);
}

int main(){
    string a = "brute", b = "groot";
    cout<<GetLcsString(a, b);
}