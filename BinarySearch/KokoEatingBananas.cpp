#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &v, int mid, int h){//monotonic function
    int sum = 0;
    for(auto &res : v){
        sum += ceil((double)(res)/(double)mid);//taking the ceil value
    }

    return sum <= h;
}

int minimumRateToEatBananas(vector<int> &v, int h) {
    int n = v.size();
    int low = 1, mid, high = *max_element(v.begin(), v.end());
    while(low <= high){
        mid = (high + low)/2;
        if(isValid(v, mid, h)){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}


int main(){
    vector<int> arr = {7, 15, 6, 3};
    sort(arr.begin(), arr.end());
    int n = arr.size(), x = 8;
    cout<<minimumRateToEatBananas(arr, x);
}