#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while(i<m || j<n){
        while(i < m && nums1[i] == 0)i++;
        while( j < n && nums2[j] == 0)j++;
        if(i < m && j < n){
            if(nums1[i] < nums2[j]){
                cout<<nums1[i];
                i++;
            }
            else{
                cout<<nums2[j];
                j++;
            }
        }
        else if(i<m){
            while(i<m){
                cout<<nums1[i];
                i++;
            }
        }
        else if(j < n){
            while(j<n){
                cout<<nums2[j];
                j++;
            }
        }
    }
}


vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);        // Can also use `nums` as the ans array.
    vector<int> prefix(n, 1);  // prefix product
    vector<int> suffix(n, 1);  // suffix product

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] * nums[i + 1];

    for (int i = 0; i < n; ++i)
      ans[i] = prefix[i] * suffix[i];

    for(auto res: prefix){
        cout<<res<<" ";
    }

    return ans;
  }

int main(){
    vector<int> a = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    vector<int> b = {1, 2, 2};

    vector<int>vec = {1, 2, 3, 4};

    productExceptSelf(vec);

    // merge(a, a.size(), b, b.size());
}