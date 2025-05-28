#include <iostream>
#include <vector>
using namespace std;

int countSubsetsWithSum(vector<int>& arr, int k, int d) {
    int n = arr.size();
    vector<int> dp(k + 1, 0);

    // Base case: one subset (empty subset) for sum 0
    dp[0] = 1;

    // Process each element in the array
    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= arr[i]; --j) {
            dp[j] += dp[j - arr[i]];
        }
    }

    // return dp[k];
    for(int i=0;i<=k;i++){
        // cout<<dp[i]<<" ";
    }

    int ans = 0;

    for(int i=0;i<=k;i++){
        int sum = d + i;
        int val1 = k-sum;
        if(dp[val1] > 0 || dp[sum] > 0){
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    vector<int> arr = {5, 2, 5, 1};
    int k = 13;
    countSubsetsWithSum(arr, k, 3);
    // cout << "Count of subsets with sum " << k << ": " << countSubsetsWithSum(arr, k) << endl;
    return 0;
}
