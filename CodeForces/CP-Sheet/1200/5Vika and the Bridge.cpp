#include<bits/stdc++.h>
using namespace std;
 
bool isValid(int diff, vector<int>& arr) {
    
}

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);

    /*
        Here if we wanted to use the binary search for every answer we may 
        need to save the answer and the second last element, then we shall
        check the answer for these two if it would be possible the answer.
    */


    for(auto &it: arr)cin>>it;
    vector<int>lastIdx(k+1);
    vector<pair<int,int>>max(k+1);//saves last and secondlast
    for(int i=0; i<n; i++){
        int lastInd = lastIdx[arr[i]];
        int lastEle = max[i+1].first;
        int secLastEle = max[i+1].second;
        int diff = i - lastInd;
        lastIdx[arr[i]] = i;
        
        if(diff > lastEle){
            max[i+1].second = lastEle;
            max[i+1].first = diff;
        }
        else if(diff > max[i+1].second){
            max[i+1].second = diff;
        }
    }

    int low = 1, high = 1000, mid, ans = 0;

    while(low <= high){
        mid = (low + high)/2;

        if(isValid(mid, arr)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}