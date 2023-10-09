#include<bits/stdc++.h>
using namespace std;
int firstOccurance(int n, int k, vector<int>&v){
    int low = 0, high = n-1;
    int first = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(v[mid]==k){
            first = mid;
            high = mid - 1;
        }else if(v[mid]>k){
            high = mid-1;
            
        }else{
            low = mid+1;
        }
    }
    return first;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    cout<<firstOccurance(n,11,vec);
}