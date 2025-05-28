#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<int>& inp){
    int n = inp.size();
    if (n == 0) return 0;
    if (n == 1) return inp[0];
    if (n == 2) return max(inp[0], inp[1]);
    vector<long long int>dp(n);
    dp[0] = inp[0];
    dp[1] = max(inp[0], inp[1]);

    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1], inp[i] + dp[i-2]);
    }

    return dp[n-1];
}

long long int houseRobber(vector<int>& inp)
{
    int n = inp.size();
    if (n == 1) return inp[0];
    
    vector<int>arr, arr2;

    for(int i=0; i<inp.size(); i++){
        if(i!=0)arr.push_back(inp[i]);
        if(i!=inp.size()-1)arr2.push_back(inp[i]);
    }

    long long int val1 = solve(arr), val2 = solve(arr2);

    return max(val1, val2);
}


int main(){
    vector<int>inp = {2, 3, 2};
    cout<<houseRobber(inp);
}