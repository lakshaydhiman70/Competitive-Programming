#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x, k;
    cin>>x>>k;

    if(x % k != 0){
        cout<<1<<"\n"<<x;
    }
    else{
        cout<<2<<"\n"<<x-1<<" "<<1;
    }
    cout<<endl;
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