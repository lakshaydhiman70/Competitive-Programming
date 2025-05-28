#include<bits/stdc++.h>
using namespace std;

int solve(int i, int n, int w, vector<int>&profit, vector<int>&wt){
    if(w < 0)return 0;

    if(i == n){
        return 0;
    }

    int pick = 0;
    
    if(wt[i] <= w){
        pick = profit[i] + solve(i, n, w - wt[i], profit, wt);
    }

    int notPick = solve(i + 1, n, w, profit, wt);
    return max(pick, notPick);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return solve(0, n, w, profit, weight);
}


int main(){
   int n = 3, w = 10;

   vector<int>profit = {5, 11, 13};
   vector<int>wt = {2, 4, 6};

   cout<<unboundedKnapsack(n, w, profit, wt);
}