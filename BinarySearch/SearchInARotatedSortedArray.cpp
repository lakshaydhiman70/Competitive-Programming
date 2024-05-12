#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
    int low = 0, high = arr.size()-1, mid;

    while (low <= high)
    {
        mid = (high+low)/2;
        if(arr[mid] == k)return mid;
        else if(arr[low] < arr[mid]){
            if(k >= arr[low] && k <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else {
            if(k >= arr[mid] && k <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    if(arr[high]== k)return high;
    return -1;
}

int searchParctice(vector<int>& arr, int n, int k){
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[low]<arr[mid]){
            if(k>= arr[low] && k <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(k >= arr[mid] && k <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }

    if(arr[high] == k)return high;
    return -1;
}

int main(){
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 15;
    cout<<searchParctice(arr, n, x)<<"\n";
    cout<<"-------------------------\n";
    cout<<search(arr, n,x);
}