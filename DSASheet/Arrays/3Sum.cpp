#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

}

void twoSumUsing2Ptr(vector<int>&nums, int i){
    
}

void twoSum(vector<int>&nums){
    int targetSum = 0;
    int n = nums.size();
    unordered_map<int, int>mp;

    for(int i=0;i<n;i++){
        if(mp.find(nums[i])!= mp.end()){
            cout<<mp[nums[i]]<<" "<<i;
            break;
        }
        else{
            mp[0-nums[i]] = i;
        }
    }
}

int main(){
    vector<int>nums = {-1,9,9,2,1,-4};
    twoSum(nums);
}