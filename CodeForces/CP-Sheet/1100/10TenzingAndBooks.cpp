#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, k;
    cin>>n>>k;
    queue<int>q1, q2, q3;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q1.push(x);
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q2.push(x);
    }
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        q3.push(x);
    }

    //------------------------------//
    int val = 0;

    if(k == 0){
        cout<<"YES\n";
        return;
    }

    while(!q1.empty() || !q2.empty() || !q3.empty()){
        int a = q1.front();
        int b = q2.front();
        int c = q3.front();

        if(!q1.empty() && (k|a) == k){
            val = val|a;
            q1.pop();
        }
        else if(!q2.empty() && (k|b) == k){
            val = val|b;
            q2.pop();
        }
        else if(!q3.empty() && (k|c) == k){
            val = val|c;
            q3.pop();
        }
        else{
            break;
        }

        if(val == k){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;

    while(t--){
        solve();
    }
}