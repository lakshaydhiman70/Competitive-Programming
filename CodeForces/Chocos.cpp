#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int                 long long
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<int>> vec(n, vector<int>(m, 0));
    fr(i, n){
        fr(j,m){
            cin>>vec[i][j];
        }
    }

    vector<pair<int,int>>directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = 0;
            bool isTrue = true;

            for (auto dir : directions) {
                int newRow = i + dir.first;
                int newCol = j + dir.second;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    val = max(val, vec[newRow][newCol]);
                    if (vec[i][j] <= vec[newRow][newCol]) {
                        isTrue = false;
                    }
                }
            }

            if (isTrue) {
                vec[i][j] = val;
            }
        }
    }
    
    fr(i, n){
        fr(j,m){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

int32_t main(){
    FAST_IO;

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