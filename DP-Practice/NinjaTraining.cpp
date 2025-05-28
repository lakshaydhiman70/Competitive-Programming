#include<bits/stdc++.h>
using namespace std;

int solve(int currIdx, int prevDayUsed, vector<vector<int>>&mat, vector<vector<int>>&dp){
    if(currIdx == mat.size() - 1){
        int mx = 0;
        for(int i=0;i<3;i++){
            if(i!=prevDayUsed){
                int call = mat[currIdx][i];
                mx = max(mx, call);
            }
        }
        return mx;
    }

    if(dp[currIdx][prevDayUsed] != -1){
        return dp[currIdx][prevDayUsed];
    }

    int mx = 0;
    for(int i=0;i<3;i++){
        if(i!=prevDayUsed){
            int call = mat[currIdx][i] + solve(currIdx + 1, i, mat, dp);
            mx = max(mx, call);
        }
    }
    return dp[currIdx][prevDayUsed] = mx;
}


int recursiveSolution(){
    
}

int main(){
    /*
        2
        10 50 1
        5 100 11
    */

   vector<vector<int>>mat = {{10, 50, 1}, {5, 100, 11}};
   int n = mat.size();
   vector<vector<int>>dp(n, vector<int>(3, -1));
   cout<<solve(0, n, mat, dp);
}