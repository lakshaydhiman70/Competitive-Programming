#include <bits/stdc++.h> 
using namespace std;

long long int houseRob(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    vector<long long>dp(n);
    dp[0] = valueInHouse[0];
    dp[1] = max(valueInHouse[0], valueInHouse[1]);
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + valueInHouse[i]);
    }

    return dp[n-1];
}

long long int houseRobber(vector<int>&inp){
    int n = inp.size();
    vector<int>inp1, inp2;
    for(int i=0; i<n-1; i++){
        inp1.push_back(inp[i]);
    }
    for(int i=1; i<n; i++){
        inp2.push_back(inp[i]);
    }

    return max(houseRob(inp1), houseRob(inp2));
}

int main() {
	vector<int>inp = {2, 3, 2};
	cout<<houseRobber(inp);
	return 0;
}