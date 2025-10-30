#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    if(n1>n2)return kthElement(b, a, n2, n1, k);
    int low = max(0, k - n2), high = min(k, n1), mid, mid1, needed = k;
    
    while(low <= high){
        mid = (low + high)/2;
        mid1 = needed - mid;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid < n1)r1 = a[mid];
        if(mid1 < n2)r2 = b[mid1];
        if(mid - 1 >= 0)l1 = a[mid-1];
        if(mid1 - 1 >= 0)l2 = b[mid1-1];
        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return 0;
}


int main(){

}