#include<bits/stdc++.h>
using namespace std;
//3 6 8 10 11
/*
	What is the lower bound?
	This method returns an index if the provided element x is greater than the element at the returned idx.
*/
int upperBound(vector<int>&arr, int x){
    int low = 0, n= arr.size();
    int high = n-1;
    int mid, ans = n;

    while(low<=high){
        mid = (high + low)/2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int>inp(n);
    for(auto &it: inp){
        cin>>it;
    }

    sort(inp.begin(), inp.end());

    int t;
	cin>>t;
    while(t--){
        int val;
        cin>>val;

        // int sum=upper_bound(inp.begin(),inp.end(),val)-inp.begin();
        int sum = upperBound(inp, val);
        cout<<sum<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
	solve();
}