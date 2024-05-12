#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k, x;
    cin>>n>>k>>x;
    if(x != 1){
        cout<<"YES\n";
        cout<<n<<'\n';
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
    }
    else if((n % 2) == 0 && k == 2){
        cout<<"YES\n";
        cout<<n/2<<"\n";
        for(int i=1;i<=n/2;i++)cout<<2<<" ";
        cout<<endl;
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}