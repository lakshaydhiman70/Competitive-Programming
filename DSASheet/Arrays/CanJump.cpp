#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for(int i=0; i<n;i++){
        j = max(j, i + nums[i]);
        if(j > n){
            return true;
            break;
        }
    }
    return false;
}

int main(){
    vector<int>nums = {3,2,1,0,4};
    cout<<canJump(nums);
}