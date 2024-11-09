#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cout<<(n-x) + 1<<" ";
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