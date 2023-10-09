#include<bits/stdc++.h>
using namespace std;

//Lower bound is the index of the first element which is greater than or equal to the givem element K.
int lowerbound(int n, int k, vector<int>&v){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low + high)/2;
        if(v[mid]<=k){
           low = mid; 
        }else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        
    }
}


