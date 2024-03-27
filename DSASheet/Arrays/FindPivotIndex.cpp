#include<bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;

    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    int leftSum = 0;

    for(int i=0;i<n;i++){
        int rightSum = totalSum - nums[i] - leftSum;
        if(rightSum == leftSum){
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}
int main(){
    vector<int>vec={-1,-1,0,-1,-1,0};
    cout<<pivotIndex(vec);
}