#include<bits/stdc++.h>
using namespace std;

//By memorization
int FibonacciMemorize(int n,  vector<int>& dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    else{
        return dp[n] = FibonacciMemorize(n-1, dp) + FibonacciMemorize(n-2, dp);
    }
}

int FibonacciTabulation(int n){
    int first = 0;
    int second = 1;
    for(int i=2; i<=n; i++){
        int NewVal = first+second;
        first = second;
        second = NewVal;
    }
    return second;
}

int main(){
    int n=60;
    vector<int> dp(n+1,-1);
    cout<<FibonacciMemorize(n, dp)<<endl;
    cout<<FibonacciTabulation(n);
}
