#include<bits/stdc++.h>
using namespace std;

//give the count of the subsequeces with sum = k.
int solve(int ind, int s, int sum, vector<int>&inp, int n){

    if(s > sum)return 0;
    if(ind >= n){
        if(s == sum)return 1;
        return 0;
    }

    s += inp[ind];
    int left = solve(ind + 1, s, sum, inp, n);
    s -= inp[ind];
    int right = solve(ind + 1, s, sum , inp, n);

    return left + right;
}

int main(){
    vector<int>inp = {1, 2, 1};
    cout<<solve(0, 0, 2, inp, inp.size());
}