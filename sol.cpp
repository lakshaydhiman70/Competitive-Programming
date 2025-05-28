#include<bits/stdc++.h>
using namespace std;

void comb(int idx, vector<int>&temp, vector<int>& nums, vector<vector<int>>& ans, int target){
    if(idx == nums.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
    }

    if(nums[idx] <= target){
        temp.push_back(nums[idx]);
        comb(idx, temp, nums, ans, target-nums[idx]);
        temp.pop_back();
    }

    comb(idx+1, temp, nums, ans, target);
}

int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    int n = horizontalCuts.size();
    int m = verticalCuts.size();
    int maxhori = horizontalCuts[1] - horizontalCuts[0];
    int maxver = verticalCuts[1] - verticalCuts[0];
    for(int i=1;i<n;i++){
        maxhori = (maxhori, horizontalCuts[i] - horizontalCuts[i-1]);
    }

    for(int i=1;i<m;i++){
        maxver = (maxver, verticalCuts[i] - verticalCuts[i-1]);
    }

    maxhori %= 1000000007;
    maxver %= 1000000007;

    long long ans = maxhori *1ll * maxver;
    return ans;
}

/*
    lets solve this by using iteratively
*/

int backTrack(int row, int col, vector<vector<int>>& grid){
    
    
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n = grid.size(), m = n? grid[0].size(): 0, mxans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                mxans = max(mxans, backTrack(i, j, grid, ));
            }
        }
    }
    return mxans;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>temp;
    comb(0, temp, candidates, ans, target);
    return ans;
}

int jump(vector<int>& nums) {
    int n = nums.size();
    int maxVal = 0;
    int jumps = 0;
    int currend = 0;
    for(int i=0;i<n;i++){
        maxVal = max(maxVal, nums[i] + i);
        if(i == currend){
            jumps++;
            currend = maxVal;
        }
    }
    return jumps;
}

int main(){
   vector<int>cand = {2,3,6,7};
   int target = 7;
   auto ans = combinationSum(cand, target);

   for(auto &it : ans){
        for(int &val: it){
            cout<<val<<" ";
        }
        cout<<endl;
   }
}
