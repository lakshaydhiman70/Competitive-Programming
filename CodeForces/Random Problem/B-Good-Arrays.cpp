//https://codeforces.com/problemset/problem/1856/B
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
const char nl = '\n';
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>vec(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum+=vec[i];
        }
        if(n==1){
            cout<<"NO"<<nl;
        }
        else{
            ll temp = 0;
            for(int i=0;i<n;i++){
                if(vec[i] == 1){
                    temp+=2;
                }
                else{
                    temp+=1;
                }
            }
            if(temp<=sum){
                cout<<"YES"<<nl;
            }
            else{
                cout<<"NO"<<nl;
            }
        }
    }
}