#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int maxPro = 0;
    int minBuyTillNow = prices[0];
    int n = prices.size();
    for(int i=1; i<n; i++){
        if(prices[i] < minBuyTillNow){
            minBuyTillNow = prices[i];
        }
        if((prices[i]-minBuyTillNow) > maxPro){
            maxPro = prices[i]-minBuyTillNow;
        }
    }
    return maxPro;
}
int main(){

}