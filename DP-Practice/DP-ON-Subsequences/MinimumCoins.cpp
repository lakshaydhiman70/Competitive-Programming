#include<bits/stdc++.h>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    //state: dp[i] states that number of min coins required to sum up till i.d 

    //transistion: summation of i till n

    //base case: dp[0] = 1;
    int n = num.size();
    vector<int>dp(x+1, INT_MAX);
    dp[0] = 1;

    for(int i=1; i<=x; i++){
        for(int j = 0; j<n; j++){
            dp[i] = dp[i-1];
            if(i - num[j] >= 0){
                dp[i] += min(dp[i - num[j]], dp[i]); 
            }
        }
    }

    return dp[x];
}

int main(){
    vector<int>arr = {1,2,3};
    int x = 7;
    cout<<minimumElements(arr, x);
}