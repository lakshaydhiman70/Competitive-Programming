#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int                 long long
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl

void solve() {
    int n;
    cin>>n;
    int ans = 0, mx = -1, sum = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum += x;
        mx = max(mx, x);
        if(sum-mx == mx){
            ans++; 
        }
    }
    cout<<ans<<endl;
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