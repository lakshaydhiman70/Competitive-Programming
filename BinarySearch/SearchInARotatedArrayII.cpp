//https://www.codingninjas.com/studio/problems/search-in-a-rotated-sorted-array-ii_7449547
#include<bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    int low = 0, high = arr.size()-1, mid;
    while(low <= high){
        mid = (low+high)/2;
        if (arr[low]==arr[mid] and arr[low]==arr[high]){
            low++;
            high--;
            continue;
        }
        else if(arr[mid] == key)return true;
        else if(arr[low] <= arr[mid]){
            if(key >= arr[low] && key <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        else if(arr[mid] <= arr[high]){
            if(key >= arr[mid] && key <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    if(arr[high] == key)return true;
    return false;
}



int main(){
    vector<int> vec = {3, 5, 8, 15, 19};
    int n = 5, k = 3;
    cout<<searchInARotatedSortedArrayII(vec, k);
}