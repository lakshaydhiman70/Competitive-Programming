#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a,b,num,sum=INT_MIN;
        cin>>a>>b;
        for(auto i=a;i<=b;++i){
            int mx=INT_MIN,mn=INT_MAX;
            int t=i;
            while(t>0){
                mx=max(mx,t%10);
                mn=min(mn,t%10);
                t=t/10;
            }
            if(mx-mn>sum){
                sum=mx-mn;
                num=i;
            }
            if(mx-mn==9) break;
        }
        cout<<num<<"\n";
    }
}