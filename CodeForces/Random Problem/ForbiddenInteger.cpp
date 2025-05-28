#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k, x;
    cin>>n>>k>>x;

    if(x != 1){
        cout<<"YES\n";
        cout<<n<<"\n";
        for(int i=0;i<n;i++)cout<<1<<" ";
    }
    else if((k==1) || (k == 2 && n % 2 == 1)){
        cout<<"NO";
    }
    else if(n%2){
        cout<<"YES\n";
        
        int div = n/2;
        cout<<div<<"\n";

        for(int i=0;i<div-1;i++){
            cout<<2<<" ";
        }
        cout<<3;
    }
    else{
        cout<<"YES\n";
        
        int div = n/2;

        cout<<div<<"\n";
        for(int i=0;i<div;i++){
            cout<<2<<" ";
        }
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