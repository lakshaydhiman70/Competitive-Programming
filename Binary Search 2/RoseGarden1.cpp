#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> arr, int k, int m, int mid){
    for(int i=0;i<arr.size(); i++){
        int tempVal = k;
        while(i < arr.size() && arr[i] <= mid){
            if(arr[i]>mid || tempVal <= 0){
                i--;
                break;
            }
            tempVal--;
            i++;
        }
        if(tempVal<=0){
            m--;
        }
    }
    return m<=0;
}

int roseGarden(vector<int> arr, int k, int m){
    if(k * m > arr.size()){
        return -1;
    }

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
    vector<int> v = {3, 3, 6, 8, 13, 17, 6, 16};
    int k = 2, m = 2;
    cout<<roseGarden(v, k, m);
}