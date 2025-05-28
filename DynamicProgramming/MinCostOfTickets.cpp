#include<bits/stdc++.h>
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int maxDays = days.back();
    vector<int>dp(maxDays+1);
    int n = days.size();
    // unordered_set<int>daysHash(days.begin(), days.end());

    for(int i=1;i<=maxDays;i++){
        dp[i] = 
    }
}

int main(){
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,5};
    int result = mincostTickets(days, costs);
    cout<<result;
}