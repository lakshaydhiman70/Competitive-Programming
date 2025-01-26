#include<bits/stdc++.h>
using namespace std;

int solve(int i, int rodSum, int n, vector<int>&pri, vector<vector<int>>&dp){
	if(rodSum >= n)return 0;
    if(i >= n)return 0;

	if(dp[i][rodSum]!=-1)return dp[i][rodSum];

    int pick = 0;
    if(rodSum + i + 1 <= n){
        pick = pri[i] + solve(i, rodSum + i + 1, n, pri, dp);
    }
	
	int notPick = solve(i + 1, rodSum, n, pri, dp);

	return dp[i][rodSum] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n, -1));
	return solve(0, 0, n, price, dp);
}

int main(){
    vector<int>price = {2, 5, 7, 8, 10};
    cout<<cutRod(price, price.size());
}