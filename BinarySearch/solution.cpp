#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll t;cin>>t;
    
    while(t--){
        ll n;cin>>n;
        vector<ll>a(n);
        for(ll i=0 ;i<n;i++){
            cin>>a[i];
        }
        ll maxEle = 0;
        if(a[0]==1){
            maxEle=2;
        }else{
            maxEle =1;
        }

        for(ll i=1;i<n;i++){
            if(maxEle+1!=a[i]){
                maxEle++;
            }else{
                maxEle+=2;
            }
        }
        cout<<maxEle<<endl;
    }
}