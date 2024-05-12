#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>&arr, int midVal, int k, int maxBouquets){
    int count = 0;
    int noOfBouquotes = 0;
    
    for(auto &res : arr){
        if(res <= midVal){
            count++;
            if(count == k){
                noOfBouquotes++;
                count = 0;
            }
        }
        else {
            if(count == k){
                noOfBouquotes++;
            }
            count = 0;
        }
    }
    
    if(count >= k){
        noOfBouquotes++;
    }

    return noOfBouquotes >= maxBouquets;
}

int roseGarden(vector<int>&arr, int m, int k){
    if(k*m > arr.size()){
        return -1;
    }
    int low = 1, high = *max_element(arr.begin(), arr.end()), mid;
    while(low <= high){
        mid = (low + high)/2;
        if(isValid(arr, mid, k, m)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    int n = 8, m = 2, k = 3;
    //m is the no of bouquets, 
    //k is the number of flowers each bouquets should have
    vector<int>vec = {7, 7, 7, 7, 13, 12, 11, 7};
    cout<<roseGarden(vec, m, k);
}

//In this we need to return min number days on which we can make m bouquets
//having k consecutive flowers in each bouquet