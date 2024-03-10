#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr)
{
	int low = 0, mid, high = arr.size()-1;
    int ans = INT_MAX;
    while(low <= high){
        mid = (low + high)/2;
        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 3;
    
}