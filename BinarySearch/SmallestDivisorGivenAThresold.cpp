#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&arr, int mid, int limit){
    int sum = 0;
    for(auto &res: arr){
        sum = sum + ceil(static_cast<double>(res) / mid);
    }
    return sum <= limit;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	int low = 1, high = *max_element(arr.begin(), arr.end()), mid;
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
    int n = 5;
    int limit = 8;
    vector<int>arr = {1, 2, 3, 4, 5};
    cout<<smallestDivisor(arr, limit);
}