#include<bits/stdc++.h>
using namespace std;

void processSubset(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
    
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    processSubset(index+1, nums, ans, temp);
    temp.pop_back();
    processSubset(index+1, nums, ans, temp);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>temp;
    processSubset(0, nums, ans, temp);
    return ans;
}

int main(){
    vector<int>nums = {1,2,3};
    auto res = subsets(nums);
    for(auto subset: res){
        for(auto val: subset){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}