#include<bits/stdc++.h>
using namespace std;


//In this approach basically we are calculating the prefix as well as suffix sum for hte given 
//array but in the calculation of suffix and the prefix arrays we are not considering the element 
//in which we currently at and at the end we are just multiplying the values of the prefix and suffix arrays
//bacause the prefix array shall give us the product of all the elements that we got till now 
//except the element that we are currently on.
//same goes for suffix array.
vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> ans(n);        // Can also use `nums` as the ans array.
    vector<int> prefix(n, 1);  // prefix product
    vector<int> suffix(n, 1);  // suffix product


    //in the prefix array we are calculating the prefix
    //of the elements we get till now just not considering the element
    //we currently on

    //same goes for the suffix array
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
    vector<int>vec = {1, 2, 3, 4};
    productExceptSelf(vec);
}