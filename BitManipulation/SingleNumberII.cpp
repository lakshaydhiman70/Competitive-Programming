#include<bits/stdc++.h>
using namespace std;

int powerSet(vector<int>&nums){
    int n = nums.size();
    int end = pow(2, n);

    for(int i=0;i<end;i++){
        for(int j=0;j<n;j++){
            if(i &(1 << j)){
                cout<<nums[j];
            }
        }
        cout<<endl;
    }
}

int main(){
    vector<int>nums = {1, 1, 1, 2, 3, 3, 3};
    powerSet(nums);
}