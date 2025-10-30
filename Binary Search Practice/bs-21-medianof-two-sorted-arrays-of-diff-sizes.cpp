#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    vector<int>temp;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(b[j]);
            j++;
        }
    }

    while(i<n){
        temp.push_back(a[i]);
        i++;
    }

    while(j<m){
        temp.push_back(b[j]);
        j++;
    }

    return temp;
}


double medianbruteforce(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0, n = a.size(), m = b.size();
    auto arr = merge(a, b);

    int size = arr.size();
    if(size % 2 == 1){
        return arr[size/2];
    }

    return ((double)arr[size/2] + (double)(arr[size/2 - 1])) / 2.0;
}


/*
we can find the median of two sorted arrays by binary search as well:
1. We need to do like: we need to find like what elements we need to pick from first array 
how many elements we need to pick from second array and on the basis of that we need to pick
the middle element of the array.
*/
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    if(n1>n2)return median(b, a);

    int needed = (n1 + n2 + 1)/2;
    
    int low = 0, high = n1, mid, mid2;

    while(low <= high){
        mid = (low + high) /2;
        mid2 = needed - mid;

        int l1 = (mid > 0) ? a[mid - 1] : INT_MIN;
        int l2 = (mid2 > 0) ? b[mid2 - 1] : INT_MIN;
        int r1 = (mid < n1) ? a[mid] : INT_MAX;
        int r2 = (mid2 < n2) ? b[mid2] : INT_MAX;

        if(l1 <= r2 && l2 <= r1){
            if((n1 + n2) % 2 == 1){
                return max(l1, l2);
            }
            else{
                return ((double)(min(r1, r2)) + (double)(max(l1, l2))) / 2.0;
            }
        }
        if (l1 > r2) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

    }

    return 0;
    
}

int main(){
    vector<int>a = {2, 4, 6}, b = {1, 3};
    cout<<median(a, b);
}