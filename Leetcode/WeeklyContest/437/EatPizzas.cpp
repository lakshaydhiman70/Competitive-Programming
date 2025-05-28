#include<bits/stdc++.h>
using namespace std;

long long maxWeight(vector<int>& pizzas) {
    int n = pizzas.size();
    sort(pizzas.begin(), pizzas.end());
    
    int noOfDays = (n+1)/4;
    int evenDays = noOfDays/2;
    int oddDays = noOfDays - evenDays;
    long long ans = 0;

    for(int i = n-1; i >= (n-oddDays); i--){
        ans += pizzas[i];
    }

    for(int i = (n - oddDays - 2); i >= (n - ((2 * oddDays) + evenDays)); i-=2){
        ans += pizzas[i];
    }

    return ans;
}

int main(){
    vector<int>vec = {3,4,2,4,2,4,2,2,4,5,3,2,1,2,1,1};
    // vector<int>vec = {1,1,1,2,2,2,2,2,2,3,3,4,4,4,4,5};
    cout<<maxWeight(vec);
}