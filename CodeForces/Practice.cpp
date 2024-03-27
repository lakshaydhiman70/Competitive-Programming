#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // Create a map to store the indices of the elements
    unordered_map<int, int> indexMap;
    vector<int> ans;

    // Store indices of elements in the map
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (indexMap.count(complement)) {
            // If complement exists in the map, return the indices
            ans.push_back(indexMap[complement]);
            ans.push_back(i);
            return ans;
        }
        // Otherwise, store the current element's index
        indexMap[nums[i]] = i;
    }

    return ans; // No solution found
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> ans = twoSum(nums, k);
    if (ans.empty()) {
        cout << "No solution found";
    } else {
        for (auto res : ans) {
            cout << res << " ";
        }
    }
    cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
