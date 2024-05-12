#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){
    int low = 0, mid, high = arr.size()-1;
    int ans = 1e9, idx = -1;
    while(low<=high){
        mid = (low+high)/2;
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                idx = low;
            }
            low = mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid-1;
        }
    }
    return idx;
}

int howMany(vector<int>&a, int n){
    int low = 0, mid, high = n-1, minval = INT_MIN, minValIdx = 0;
    while(low <= high){
        mid = low + high / 2;
        if(a[low] <= a[mid]){
            if(minval > a[low]){
                minval = a[low];
                minValIdx = low;
            }
            low = mid+1;
        }
        else{
            if(minval > a[mid]){
                minval = a[mid];
                minValIdx = mid;
            }
            high = mid-1;
        }
    }
    return minValIdx;
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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(auto &inp: vec){
            cin>>inp;
        }
        cout<<findKRotation(vec);
    }
}