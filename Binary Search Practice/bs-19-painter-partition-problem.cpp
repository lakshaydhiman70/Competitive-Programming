#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr[] and k, where the array represents the boards and each element of the given array represents the length of each board.
k numbers of painters are available to paint these boards. 
Consider that each unit of a board takes 1 unit of time to paint. 
The task is to find the minimum time to get this job done by painting 
all the boards under the constraint that any painter will only paint the continuous sections of boards.
say board [2, 3, 4] or only board [1] or nothing but not board [2, 4, 5].

Examples: 

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20, 15], Job will be done when all painters finish i.e. at time = max(5 + 10, 30, 20 + 15) = 35

Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: The most optimal way to paint: Painter 1 allocation : [10, 20, 30], Painter 2 allocation : [40], Job will be complete at time = 60
*/


//this problems seems like: book allocation problem

bool isValid(vector<int>&arr, int mid, int k){
    int nostud = 1;
    int tempsum = arr[0];
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(tempsum + arr[i] <= mid){
            tempsum += arr[i];
        }
        else{
            nostud++;
            tempsum = arr[i];
        }
    }
    
    return nostud <= k;
}

int minTime(vector<int>& arr, int k) {
    int n = arr.size(), maxval = INT_MIN, sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxval = max(maxval, arr[i]);
    }

    int low = maxval, high = sum, mid, ans = -1;

    while(low <= high){
        mid = (low + high)/2;

        if(isValid(arr, mid, k)){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int>arr = {5, 10, 30, 20, 15};
    cout<<minTime(arr, 3);
}