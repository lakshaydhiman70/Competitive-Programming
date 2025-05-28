#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(auto &it: vec)cin>>it;

    int mxZeroCt = 0;
    int currZeroCt = 0;
    for(int i=0;i<n;i++){
        if(vec[i] == 1){
            mxZeroCt = max(currZeroCt, mxZeroCt);
            currZeroCt = 0;
            continue;
        }
        currZeroCt++;
    }
    mxZeroCt = max(currZeroCt, mxZeroCt);

    cout<<mxZeroCt<<endl;
}

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}