#include<bits/stdc++.h>
using namespace std;

int singleElementInSorted(vector<int>&a, int n){
    int low = 1, mid, high = n-2;
    if(n == 1)return a[0];
    if(a[n-1] != a[n-2])return a[n-1];
    if(a[0] != a[1])return a[0];
    while(low <= high){
        mid  = high + low /2;
        if(mid % 2 == 0){//mid idx is even 
            if(a[mid] == a[mid+1]){//check if its duplicate on right exists
                low = mid+1;
            }
            else if(a[mid] == a[mid-1]){ //check if its duplicate on the left exists
                high = mid-1;
            }
            else return a[mid];
        }
        else{ //mid idx is odd
            if(a[mid] == a[mid+1]){//check if its duplicate on right exists
                high = mid-1;//moving to the laft half
                
            }
            else if(a[mid] == a[mid-1]){ //check if its duplicate on the left exists
                low = mid+1; //moving to the right half
            }
            else return a[mid];
        }
    }
    return a[mid];
}

int singleElementInSorted1(vector<int>&a, int n){
    int low = 1, mid, high = n-2;
    if(n == 1)return a[0];
    if(a[n-1] != a[n-2])return a[n-1];
    if(a[0] != a[1])return a[0];

    while(low <= high){
        mid  = high + low /2;
        if(a[mid] != a[mid-1] && a[mid] != a[mid+1]){
            return a[mid];
        }
        else if((mid % 2 == 1 && a[mid] == a[mid-1])
            || (mid % 2 == 0 && a[mid] == a[mid+1])){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int n = arr.size(), x = 3;
    cout<<singleElementInSorted1(arr, n);
}