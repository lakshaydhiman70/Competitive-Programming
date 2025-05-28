//https://codeforces.com/problemset/problem/1807/D
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    long long n,q,sum = 0;
    cin>>n>>q;
    vector<long long>pref(n+1);
    ll x;
    for(int i=1;i<=n;i++){
        cin>>x;
        sum+=x;
        pref[i]=pref[i-1]+x;
    }
    while(q--){
        long long l,r,k;
        cin>>l>>r>>k;
        ll res = sum-(pref[r]-pref[l-1])+k*(r-l+1);
        if(res&1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long t;cin>>t;
    while(t--){
        solve();
    }
}