#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>& nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    int index = -1;
    for(int i=n-1; i>0; i--){
        if(nums[i] > nums[i-1]){
            index = i-1;
            break;
        }
    }

    if(index == -1){
        reverse(nums, 0, n-1);
    }
    else{
        int tempIndex = -1;
        for(int i=n-1; i>index; i--){
            if(nums[index] < nums[i]){
                tempIndex = i;
                break;
            }
        }
        swap(nums[tempIndex], nums[index]);
        reverse(nums.begin()+index+1, nums.end());
        // reverse(nums, index+1, n-1);
    }
}

int main(){
    vector<int>nums = {1, 1, 5};
    //4 5 3 2 1

    nextPermutation(nums);

    for(auto res: nums){
        cout<<res<<" ";
    }
}


