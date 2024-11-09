#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    vector<int>dp(n+1);
    
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }

    while(j >= 0){
        int testval = nums2[j];
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans(n);
    int i=0,j = n-1;
    for(int k=n-1;k>=0;k--){
        if(abs(nums[i] * nums[i]) > abs(nums[j] * nums[j])){
            ans[k] = abs(nums[i] * nums[i]);
            i++;
        }
        else{
            ans[k] = abs(nums[j] * nums[j]);
            j--;
        }
    }     
}

vector<vector<int>> merge(vector<vector<int>>& ints) {
    vector<vector<int>>ans;
    vector<int>temp = ints[0];

    for(int i=1;i<ints.size();i++){
        if(temp[1] > ints[i][0]){
            temp[1] = max(temp[1], ints[i][1]);
        }
        else{
            ans.push_back(temp);
            temp = ints[i];
        }
    }
    ans.push_back(temp);
    return ans;
}

//1,2,3,4
//24,12,8,6

/*
    inp - [1, 2, 3, 4]
           0, 1, 2, 3
    if i want to find the index 2 then what shall be the output - 

    i need to find the prefix sum before 2nd idx and after 2nd idx

    before is = 2
    after is  = 4

    in prefix and suffix arrays we are going to store the values like - 

    for prefix we shall do - product of all the values from start just excluding the current value

    for suffix we shall do - product of all the values from end just excluding the current value.

    output - 24, 12, 8, 6

    prefix - 1, 2, 6, 24

    suffix - 24, 24, 12, 4
*/

/*
    3 sum problem
*/

int subarraySum(vector<int>& nums, int k) {

}

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        int j = i+1, k = n-1;

        while (j<k)
        {
            if(nums[j] + nums[k] + nums[i] == 0){
                ans.push_back({nums[i], nums[j], nums[k]});

                while(k!=0 && nums[k] == nums[k-1]){
                    k--;
                }
                while(j<n && nums[j] == nums[j+1]){
                    j++;
                }
                j++;
                k--;
            }
            else if(nums[j] + nums[k] + nums[i] > 0){
                while(k!=0 && nums[k] == nums[k-1]){
                    k--;
                }
                k--;
            }
            else{
                while(j<n && nums[j] == nums[j+1]){
                    j++;
                }
                j++;
            }
        }
        while(i<n && nums[i] == nums[i+1]){
            i++;
        }
    }
}

bool found(int row, int col, vector<vector<char>>& board, string word){

    vector<pair<int,int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == word[i]){
                if(found(i, j, board, word.substr(1, word.size()))){
                    return true;
                }
            }
        }
    }
    return false;
}

int maxArea(vector<int>& height) {
    int n = height.size();

    int i = 0, j = n-1;
    int ans = 0;

    while(i<j){
        int mxval = max(height[i], height[j]);
        ans = max(ans, (mxval * (abs(i-j))));
    }
}


vector<vector<int>> generate(int n) {
    vector<vector<int>>ans = {{1}};
    for(int i = 1; i<n; i++){
        vector<int>temp;
        temp.push_back(1);
        for(int j = 1; j<i; j++){
            int val = ans[i-1][j-1] + ans[i-1][j];
            temp.push_back(val);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
}

int main(){
    vector<vector<int>>vec = {{1,3},{2,6},{8,10},{15,18}};
    merge(vec);
    for(auto it: vec){
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}