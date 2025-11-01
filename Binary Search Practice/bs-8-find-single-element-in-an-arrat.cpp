#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }

    int low = 1, high = nums.size() - 2, mid;

    if(nums[0] != nums[1]){
        return nums[0];
    }

    if(nums[n-1] != nums[n-2]){
        return nums[n-1];
    }

    while(low <= high){
        mid = (high + low)/2;

        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
            return nums[mid];
        }

        if(mid % 2 == 0){
            if(nums[mid + 1] == nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            if(nums[mid - 1] == nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    
    return -1;
}

int main(){
    vector<int>temp = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(temp);
}