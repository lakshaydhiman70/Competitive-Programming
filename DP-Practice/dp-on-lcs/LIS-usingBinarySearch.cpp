#include<bits/stdc++.h>
using namespace std;

int tabulationSpaceOptSol(int arr[], int n) {
    vector<int>temp;
    temp.push_back(arr[0]);
    int maxLen = 1;

    for(int i=1; i<n; i++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            maxLen++;
        }
        else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];
        }
    }
    
    return maxLen;
}

int longestIncreasingSubsequence(int arr[], int n) {
    return tabulationSpaceOptSol(arr, n);
}