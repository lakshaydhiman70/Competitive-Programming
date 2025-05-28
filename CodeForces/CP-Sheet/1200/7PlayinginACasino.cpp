#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>>inp;
    for(int i=0; i<n; i++){
        vector<int>temp;
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        inp.push_back(temp);
    }

    int ans = 0;

    for(int col=0; col<m; col++){
        vector<int>temp;
        for(int row=0; row<n; row++){
            temp.push_back(inp[row][col]);
        }
        sort(temp.begin(), temp.end());

        int tempVal = 0;
        for(int i = 1; i<n; i++){
            int val = (abs(temp[i-1] - temp[i]) * i)* (n - i);
            tempVal = tempVal + val;
        }

        ans+=tempVal;
    }

    cout<<ans<<endl;
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