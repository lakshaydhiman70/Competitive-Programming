#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;
    vector<int>vec(8);
    for(int i=0;i<n;i++){
        int val = (s[i] - 'A') + 1;
        vec[val]++;
    }

    int count = 0;

    for(int i = 1; i<8; i++){
        int val = vec[i] < m ? m - vec[i] : 0; 
        count = count +  val; 
    }

    cout<<count<<endl;
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