//https://codeforces.com/problemset/problem/1802/B
#include<bits/stdc++.h>
using namespace std;
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
        int n;
        cin>>n;
        vector<int>vec(n);
        int ct1 = 0, ct2 = 0,ans=0;
        for(auto &inp: vec){
            cin>>inp;
            if(inp == 2){
                ct2+=ct1;
                ct1=0;
                if(ct2>0)ans=max(ans,(ct2/2)+1);
            }
            else{
                ct1++;
                if(ct2==0)ans = max(ans, ct1);
                else{
                    ct1+=ct2;
                    ans=max(ans,(ct1/2)+1);
                }

            }
        }
        cout<<ans<<"\n";
    }
}


//15/2-> 7+1 -> 8