
#include <bits/stdc++.h>
using namespace std;

//The lower bound algorithm finds the first or the smallest index
//Eg- [1, 2, 3, 4, 5, 8, 8, 10, 15] Target - 6
// For target - 6 output is 8 (ind - 5)
// For target - 5 output is 5 (ind - 4)

/*
    in a sorted array where the value
    at that index is greater than or equal to a given key i.e. x.
*/

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

//The upper bound algorithm finds the first or the smallest index in a sorted array
// where the value at that index is greater than the given key i.e. x.
int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int LowerBound(vector<int> &vec, int n, int target)
{
    int low = 0, high = n-1;
    int mid,ans=n;

    while(low <= high){
        
        mid = low + high/2;

        if(vec[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            ans = mid;
            high = mid-1;
        }
    }

    return ans;
}

//Lower bound practice
int lowerBoundPrac(vector<int>&vec, int n, int target){
    int low = 0, high = n-1, mid, ans = n;
    while(low <= high){
        mid = (low+high)/2;
        if(vec[mid]>=target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

//smallest index where arr[index] is greater than the target
int upperBoundPrac(vector<int>&vec, int n, int target){
    int low = 0, high = n-1, mid, ans = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(vec[mid]>target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 3;
    int ind = upperBoundPrac(arr, n, x);
    int ind2 = upperBound(arr, n, x);
    cout << "The upper bound is the index: " << ind << "\n";
    cout << "The upper bound is the index: " << ind2 << "\n";
    return 0;
}



// //What is lowere bound?.
// //If the element is present in the array then its index otherwise the first element's index 
// //which is just greater than given element
// int lowerBound(vector<int>&vec, int element){
//     int low=0;
//     int high = vec.size()-1;
//     while(high-low > 1){
//         int mid = (low+high)/2;
//         if(vec[mid] < element){
//             low=mid+1;
//         }
//         else{
//             high = mid;
//         }
//     }
//     if(vec[low]>=element){
//         return low;
//     }
//     else if(vec[high]>=element){
//         return high;
//     }
//     else return -1;
// }

// //What is puper bound ?
// //An element which is strictly greater than the given element is the upper bound;
// int upperBound(vector<int>&vec, int element){
//     int low=0;
//     int high = vec.size()-1;
//     while(high-low > 1){
//         int mid = (low+high)/2;
//         if(vec[mid] <= element){
//             low=mid+1;
//         }
//         else{
//             high = mid;
//         }
//     }
//     if(vec[low]>element){
//         return low;
//     }
//     else if(vec[high]>element){
//         return high;
//     }
//     else return -1;
// }

// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int n;
//     cin>>n;
//     vector<int>v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//     }
//     int element;
//     cin>>element;
//     cout<<lowerBound(v,element);
// }