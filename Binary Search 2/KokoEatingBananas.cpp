#include<bits/stdc++.h>
using namespace std;

int getTotalHrs(vector<int>v, int mid){
    int totalHours = 0;
    for(int i=0;i<v.size();i++){
        totalHours += ceil((double)v[i] / (double)mid);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int maxVal = 0;
    for(int i=0;i<v.size();i++){
        maxVal = max(maxVal, v[i]);
    }

    int low = 1, high = maxVal, mid, ans = maxVal;
    
    while(low <= high){
        mid = (low + high)/2;
        int totalHrs = getTotalHrs(v, mid);
        if(totalHrs <= h){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int>vec = {4, 9, 4, 3, 1,  3 };
    int h = 66;

    cout<<minimumRateToEatBananas(vec, h);
}