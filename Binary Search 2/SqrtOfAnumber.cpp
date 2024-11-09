#include<bits/stdc++.h>
using namespace std;

int sqrt(int n){
    int low = 0, high = n;
    int mid, ans = n;

    while(low <= high){
        mid = (low+high)/2;

        if(mid * mid <= n){
            low = mid+1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}


int main(){
    cout<<sqrt(26);
}