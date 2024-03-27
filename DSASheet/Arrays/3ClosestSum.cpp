#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0, minDiff = INT_MAX;

    for(int i=0;i<n;i++){
        int l = i + 1, r = n - 1;
        while (l<r)
        {
            int currsum = nums[i] + nums[l] + nums[r];
            if(abs(currsum - target) < minDiff){
                minDiff = abs(currsum - target);
                ans = currsum;
            }
            if(currsum == target){
                return ans;
            }
            if(currsum < target){
                l++;
            }
            else r--;
        }
        return ans;
    }
}

int main(){

}