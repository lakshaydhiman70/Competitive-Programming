#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&arr, int mid, int limit){
    int sum = 0;

    for(int i=0;i<arr.size();i++){
        sum += ceil((double)arr[i] / (double)mid);
    }

    return sum <= limit;
}

int smallestDivisor(vector<int>& arr, int limit){
	int maxVal = 0;

    for(int i=0;i<arr.size();i++){
        maxVal = max(maxVal, arr[i]);
    }

    int low = 1, high = maxVal, mid;

    while(low <= high){
        mid = (low + high)/2;

        if(isValid(arr, mid, limit)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> v = {4, 27, 30, 9, 37, 44};
    int limit = 11;
    cout<<smallestDivisor(v, limit);
}
