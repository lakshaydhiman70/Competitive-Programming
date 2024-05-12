#include<bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(vec[mid]-(mid+1) < k){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return vec[high] + (k - (vec[high] - (high + 1))); 
}


int main(){
    int n = 5;
    int k = 5;
    vector<int>arr = {2, 3, 4, 7, 11};
    cout<<missingK(arr, n, k);
}