#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll n,k,q;
        cin>>n>>k>>q;
        vector<ll> countDaysArr;
        ll countDays=0;
        vector<ll>v(n);
        ll ans =0;
        for (auto &inp: v)cin>>inp;
        for(int i=0; i<n;){
            if(v[i]>q ){
                i++;
                continue;
            }
            countDays = 0;
            while(i<n && v[i++]<=q){
                    countDays++;
            }
                // cout<<countDays<<"\n";
            if(countDays>=k && countDays>0){
                ll val = countDays-(k)+1;
                
                ans+= val*(val+1)/2;
            }
        }
        cout<<ans<<endl;
    }
}