#include<bits/stdc++.h>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
    int count=0;
    vector<int>dp(60,0); //here we are constructing an array of lenth 60 with zeros
    for(int i=0;i<time.size();i++)
    {
        int a=time[i] % 60;

        if(a==0)
        {
            count += dp[0];
        }
        else
        {
            count += dp[60-a];
        }
        
        dp[a]++;
    }
    return count;
}

int main(){
    vector<int>vec = {30,20,150,100,40};
    cout<<numPairsDivisibleBy60(vec);
}