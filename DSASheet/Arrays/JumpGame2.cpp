#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0;
    int maxjump = 0;
    int currend = 0;
    for(int i=0; i<n-1; i++){
        maxjump = max(maxjump, nums[i]+i);
        if(i == currend){
            jumps++;
            currend = maxjump;
        }
    }
    return jumps;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums);
}