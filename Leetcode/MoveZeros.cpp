#include<bits/stdc++.h>
using namespace std;

void moveZeroes(std::vector<int>& nums) {
    int slow = 0; // Pointer to place the next non-zero element

    // Traverse the array with the fast pointer
    for (int fast = 0; fast < nums.size(); fast++) {
        if (nums[fast] != 0) {
            // Place the non-zero element at the slow pointer's position
            nums[slow] = nums[fast];
            slow++;
        }
    }

    // Set the remaining elements to zero
    for (int i = slow; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main(){
    
}