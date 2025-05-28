#include<bits/stdc++.h>
using namespace std;

/*
    lower bound: the smallest index such that the number at that index is 
                greater than or equal to the given index.
    eg: arr[] = [3, 5, 8, 8, 19];
    find element: 8 => output : 2
    find element: 20 => output: 5 , a hypothetical index

    upper bound: it is the smallest index where the element at that index is 
                greater than the given value.
    eg: arr[1, 2, 3, 3, 3, 3]; x = 2;
            output - 2nd index;
*/

// arr = [1, 2, 3, 4, 5, 6, 6, 6, 7, 7, 7];

int lowerBound(vector<int>arr, int x){
    int low = 0, n= arr.size();
    int high = n-1;
    int mid, ans = n;

    if(n>1 && arr[0] > x){
        return 0;
    }

    while(low<=high){
        mid = (high + low)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int>arr, int x){
    int low = 0, n= arr.size();
    int high = n-1;
    int mid, ans = n-1;

    if(n>1 && arr[0] > x){
        return 0;
    }

    while(low<=high){
        mid = (high + low)/2;
        if(arr[mid] > x){
            ans = mid+1;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


int main(){
    vector<int>arr = {1, 2, 3, 4, 5, 6, 6, 6, 7, 7, 7};
    int x = 6;
    int ans = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    cout<<ans<<endl;
    cout<<lowerBound(arr, x);
}