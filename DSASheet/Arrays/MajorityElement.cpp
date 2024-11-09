#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int currentCt = 1, currentEle = nums[0];

    for(int i=1;i<n;i++){
        if(currentEle == nums[i]){
            currentCt++;
        }
        else{
            currentCt--;
            if(currentCt <= 0){
                currentCt = 1;
                currentEle = nums[i];
            }
        }
    }
    
    return currentCt;
}

int main(){
    vector<int>vec = {2, 3, 4};
    cout<<majorityElement(vec);
}