//https://www.codingninjas.com/studio/problems/count-ways-to-reach-the-n-th-stairs_798650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>dp(N,-1); 
int countNStairs(int n){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    else{
        dp[n] = countNStairs(n-1) + countNStairs(n-2);
        return dp[n];
    }
}
int main(){
    int n = 10;
    cout<<countNStairs(n);
}