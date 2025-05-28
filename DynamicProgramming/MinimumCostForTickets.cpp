#include<bits/stdc++.h>
using namespace std;

/*
    State: dp[i] represents that min cost of ticket to travel till ith day.

    Transistion: for(i(0 -> max(daysArray))) 
                dp[i] = min((dp[i - 1] + c[0]), (dp[i - 7] + c[1]), (dp[i - 30] + c[2])); 
    BaseCase: 
            dp[0] = 0;
            dp[1] = days[0];


*/

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int maxDay = days.back();
    vector<int>dp(maxDay+1);
    // dp[0] = 0;
    // dp[1] = costs[0];

    unordered_set<int>set(days.begin(), days.end());

    for(int i=1; i <= maxDay; i++){
        if(set.find(i) == set.end()){
            dp[i] = dp[i-1];
            continue;
        }

        int minVal = INT_MAX;
        if(i - 1 >= 0){
            minVal = dp[i-1] + costs[0];
        }
        
        if(i - 7 >= 0){
            minVal = min(minVal, dp[i-7] + costs[1]);
        }
        else{
            minVal = min(minVal, costs[1]);
        }

        if(i - 30 >= 0){
            minVal = min(minVal, dp[i-30] + costs[2]);
        }
        else{
            minVal = min(minVal, costs[2]);
        }

        dp[i] = minVal;
    }

    for(auto it: dp){
        cout<<it<<" ";
    }

    return dp[maxDay];
}

int main(){
    vector<int>vec = {1,4,6,7,8,20};
    vector<int>costs = {7,2,15};

    cout<<mincostTickets(vec, costs);
}