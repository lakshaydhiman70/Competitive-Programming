#include<bits/stdc++.h>
using namespace std;

int deleteAndEarn(vector<int>& nums) {
    unordered_map<int,int>freq;
    for(auto &it: nums){
        freq[it]++;
    }
    
}

int main(){
    vector<int>nums = {2,2,3,3,3,4};
    int ans = deleteAndEarn(nums);
    cout<<ans;
}