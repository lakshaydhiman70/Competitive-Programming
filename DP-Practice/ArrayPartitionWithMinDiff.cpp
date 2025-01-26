#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n) {
    int sum = 0;
    for (auto it : arr) {
        sum += it;
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int t = 1; t <= sum; t++) {
            bool pick = false;
            if (arr[i - 1] <= t) {
                pick = dp[i - 1][t - arr[i - 1]];
            }

            bool nonPick = dp[i - 1][t];

            dp[i][t] = pick || nonPick;
        }
    }

    int minVal = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n][i]) {
            int value = sum - i;
            minVal = min(abs(value - i), minVal);
        }
    }

    return minVal;
}

int main(){
	vector<int>arr = {9, 8, 11, 6, 2};
	cout<<minSubsetSumDifference(arr, arr.size());
}