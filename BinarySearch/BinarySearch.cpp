#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&vec, int target){
    int n = vec.size();
    int low = 0, high = n-1;
    while(high-low > 1){
        int mid = (low+high)/2;
        if(vec[mid]>target)high=mid-1;
        else//mid <= target we are stopping the while loop at when the arrary have only two elements left and high and low will be pointin to each of them
        low = mid;
    }
    if(vec[low] == target){
        return low;
    }
    else if (vec[high]==target){
        return high;
    }
    return -1;
}

int binarySearchPrac(int n, vector<int>&vec, int target){
    int low=0, high = n-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if(vec[mid] == target){
            return mid;
        }
        else if(vec[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);

        for(auto &inp: v){
            cin>>inp;
        }
        sort(v.begin(), v.end());
        cout<<binarySearchPrac(n, v, k);
    }
}

//Below is the strivers implementation
// #include <bits/stdc++.h>
// using namespace std;

// int binarySearch(vector<int>& nums, int target) {
//     int n = nums.size(); //size of the array
//     int low = 0, high = n - 1;

//     // Perform the steps:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target) return mid;
//         else if (target > nums[mid]) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }
// vec[mid] < target then low = mid+1
//1 2 3 4 5 6 7 8 9 10
//0 1 2 3 4 5 6 7 8 9

// int binarySearch(vector<int>&vec, int target)
// {
//     int n = vec.size()-1;
//     int low = 0, high = n;
    
//     while(low <= high)
//     {
//         int mid = (low + high)/2;

//         if(vec[mid] > target)
//         {
//             high = mid - 1;
//         }
//         else if(vec[mid] > target)
//         {
//             low = mid+1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
//     int target = 6;
//     int ind = binarySearch(a, target);
//     if (ind == -1) cout << "The target is not present." << endl;
//     else cout << "The target is at index: "
//                   << ind << endl;
//     return 0;
// }


// time Complexity log2(n)