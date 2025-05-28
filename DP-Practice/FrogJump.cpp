#include <bits/stdc++.h> 
using namespace std;

int solve(int n, vector<int>&v){
    if(n <= 0){
        return 0;
    }

    int left = solve(n - 1, v) + abs(v[n] - v[n-1]);
    int right = INT_MAX;
    if(n > 0){
        right = solve(n - 2, v) + abs(v[n] - v[n-2]);
    }

    return min(left, right);
}

int tabulationSolve(int n, vector<int>&v){
    /*
        here prev1 shall tell us what is the min cost to reach if we go till i - 2;
        and prev2 shall tell us what is the min cost to reach if we go till i - 1;
    */
    int prev1 = 0;
    int prev2 = abs(v[0] - v[1]);


    for(int i=2; i<=n; i++){
        int left = prev2 + abs(v[i] - v[i-1]);
        int right = prev1 + abs(v[i] - v[i-2]);

        prev1 = prev2;
        prev2 = min(left, right);
    }

    return prev2;
}

int frogJump(int n, vector<int> &v){
    return tabulationSolve(n-1, v);
}

int main(){
    vector<int>v = {7, 2, 3, 6, 9, 6, 10, 10, 10, 3, 2, 7, 7, 4, 9, 5, 10, 5, 8, 7};
    cout<<frogJump(v.size(), v);
}