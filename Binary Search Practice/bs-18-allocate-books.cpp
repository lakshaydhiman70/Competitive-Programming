#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.
*/

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

int findPages(vector<int> &arr, int k) {
    int mxval = INT_MIN, sum = 0;
    int n = arr.size(), ans = -1;
    
    if(k > n)return ans;
    
    for(int i=0; i<n; i++){
        sum+=arr[i];
        mxval = max(mxval, arr[i]);
    }
    
    int low = mxval, high = sum, mid;
    
    while(low <= high){
        mid = low + (high - low)/2;
        
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
    vector<int>temp = {15, 10, 19, 10, 5, 18, 7};
    cout<<findPages(temp, 5);   
}