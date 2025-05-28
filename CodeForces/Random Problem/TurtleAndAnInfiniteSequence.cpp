#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int                 long long
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()


void solve() {
    int n,m;
    cin>>n>>m;
    int mod = 15;
    int dp[mod];
    dp[0] = 1;
    dp[mod-1] = (mod - 1) | (mod - 2); 
    int multiple = 2;
    int val = 1;
    
    for(int i=1; i<mod-1; i++){
        dp[i] = ((i-1)|(i)|(i+1));
    }

    for(int i=0;i<mod;i++){
        cout<<dp[i]<<" ";
    }
    
}

int32_t main(){
    FAST_IO;

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