#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int k, int m, int mid){
    for(int i=0;i<arr.size(); i++){
        int tempVal = k;
        while(arr[i] <= mid){
            if(arr[i]>mid)break;
            tempVal--;
        }
        if(tempVal<=0){
            m--;
        }
    }
    return m<=0;
}

int roseGarden(vector<int> arr, int k, int m){
	int maxVal = 0;
    for(int i=0;i<arr.size();i++){
        maxVal = max(arr[i], maxVal);
    }

    int low = 1, high = maxVal, mid;
    
    while(low <= high){
        mid = (low + high) / 2;

        if(isValid(arr, k, m, mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return low;
}

int main(){
    vector<int> v = {1, 2, 1, 2, 7, 2, 2, 3, 1};
    int k = 3, m = 2;
    roseGarden(v, k, m);
}