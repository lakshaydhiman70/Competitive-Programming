#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 1;
    for(int i=0; i<n; i++) {
        if(nums[i] == count){
            count++;
        }
        else if(nums[i] < count){
            continue;
        }
        else if(nums[i] > count){
            break;
        }
    }
    return count;
}

int main(){
    vector<int>vec = {3,4,-1,1};
    cout<<firstMissingPositive(vec);
}