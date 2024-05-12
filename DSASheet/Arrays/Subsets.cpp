#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int val = 1<<0;
    cout<<val;
    vector<vector<int>> ans;
    int total = pow(2, nums.size());  
    int i = 0;
    while(i < total){
        vector<int>vec;
        for(int j = 0; j<nums.size(); j++){
            if(i & 1<<j){
                vec.push_back(nums[j]);
            }
        }
        ans.push_back(vec);
        i++;
    }
    return ans;
}

int main(){
    vector<int> subsetsArr = {1, 2, 3};
    auto res = subsets(subsetsArr);
    // for(auto i: res){
    //     for(auto j: i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
}