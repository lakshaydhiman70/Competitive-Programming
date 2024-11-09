#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&arr, int mid, int n, int m){
    
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n)return -1;

    int sum = 0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    int low = 1, high = sum, mid;

    while(low <= high){
        mid = (low + high)/2;
        if(isValid(arr, mid, n, m)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){

}