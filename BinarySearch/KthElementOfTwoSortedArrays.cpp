#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    if(n > m){
        return kthElement(arr2, arr1, m, n, k);
    }
    int low = max(0, k - m), high = min(k, n), mid1, mid2;
    int noOfElementsInLeftHalf = k;//(n + m)/2;
    while(low <= high){
        int mid1 = low + high >> 1;
        mid2 = abs(noOfElementsInLeftHalf - mid1);
        int l1 = (mid1 - 1) >= 0 ? arr1[mid1-1] : INT_MIN;
        int l2 = (mid2 - 1) >= 0 ? arr2[mid2-1] : INT_MIN;
        int r1 = mid1 < n ? arr1[mid1] : INT_MAX; 
        int r2 = mid2 < m ? arr2[mid2] : INT_MAX;

        if(l1 > r2){
            high = mid1 -1;
        }
        else if (l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else{
            low = mid1 + 1;
        }

    }
}

int main(){
    int n = 3, m = 3, k = 3;
    vector<int>a = {1, 2, 3};
    vector<int>b = {4, 4, 4};

    cout<<kthElement(a, b, n, m, k);
}