#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>&nums, int t){
    int l = 0, r = nums.size();
    int m = -1, ans = -1;

    while(l<=r){
        m = (l+r)/2;

        if(nums[m] >= t){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
}

int upperBound(vector<int>&nums, int t){
    int l = 0, r = nums.size();
    int m = -1, ans = -1;

    while(l<=r){
        m = (l+r)/2;

        if(nums[m] > t){
            r = m - 1;
        }
        else{
            ans = m;
            l = m + 1;
        }
    }
}

int main(){
    vector<int> vec = {1, 2, 3, 3, 4};
    cout<<lowerBound(vec, 3)<<endl;
    cout<<upperBound(vec, 3);
}