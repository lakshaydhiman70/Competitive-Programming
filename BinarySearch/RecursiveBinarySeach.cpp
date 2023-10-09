#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}

int search(vector<int>& nums, int target) 
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}

//My written recursive code
int binarySearchRec(vector<int>&vec, int n, int low, int high, int target)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low+high)/2;

    if(vec[mid] == target)
    {
        return mid;
    }
    else if(vec[mid] < target)
    {
        binarySearchRec(vec,n, mid+1, high, target);
    }
    else
    {
        binarySearchRec(vec,n, low, mid-1, target);
    }
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 13;
    int ind = binarySearchRec(a, a.size(), 0, a.size()-1, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

