#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    bool isSorted = true;
    long long mnans = numeric_limits<long long>::max();
    vector<long long>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int i=1;i<n;i++){
        if(vec[i] < vec[i-1]){
            isSorted = false;
        }
        long long val = (vec[i] - vec[i-1]);
        mnans = min(mnans, val);
    }

    if(!isSorted){
        cout<<0;
    }
    else{
        cout<<(mnans/2)+1;
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}