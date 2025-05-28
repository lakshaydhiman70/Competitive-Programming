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
        string s;
        cin>>s;
        int i=0;
        int less = 0, greater = 0; 
        int mx = 0;
        while(i<n){
            less = 0;
            greater = 0;
            while(s[i]=='<'){
                less++;
                i++;
            }
            while(s[i]=='>'){
                greater++;
                i++;
            }
            mx = max({less, greater, mx});
        }
        cout<<mx+1<<endl;
    }
}