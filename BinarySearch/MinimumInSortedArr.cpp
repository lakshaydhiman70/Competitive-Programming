#include<bits/stdc++.h>
using namespace std;

int minimumInRotated(vector<int>&vec, int n){
    int low = 0, mid, high = n-1;
    int minVal = INT_MAX;
    while(low<=high){
        mid = (low + high)/2;
        if(vec[low] <= vec[mid]){
            minVal = min(minVal, vec[low]);
            low = mid+1;
        }
        else{
            minVal = min(minVal, vec[mid]);
            high = mid - 1;
        }
    }
    return minVal;
}

int main(){
    vector<int> arr = {43, 45, 48, 55, 39};
    int n = 5, x = 15;
    cout<<minimumInRotated(arr, n)<<"\n";
}