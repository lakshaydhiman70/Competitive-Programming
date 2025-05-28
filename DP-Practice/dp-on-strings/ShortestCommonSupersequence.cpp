#include <bits/stdc++.h> 
using namespace std;

string shortestSupersequence(string &s, string &t)
{
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

    int i = n, j = m;

    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans+= s[i-1];
            i--;
            j--;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            ans += t[j-1];
			j--;
        }
        else{
			ans += s[i-1];
            i--;
        }
    }

    while(i>0){
        ans += s[i-1];
        i--;
    }

    while(j>0){
        ans+=t[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string a = "brute", b = "groot";
    cout<<shortestSupersequence(a, b);
}