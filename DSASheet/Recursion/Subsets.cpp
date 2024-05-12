#include<bits/stdc++.h>
using namespace std;

void backtrack(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans){
    
    subset.push_back(nums[index]);
    backtrack(index + 1, nums, subset, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>subset;
    backtrack(0, nums, subset, ans);
    return ans;
}


int main(){
    vector<int>vec = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int>subset;

}