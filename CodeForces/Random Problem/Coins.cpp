#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    bool possible = false;
    for (int x = 0; x < 2; ++x) {
        if (n - x * k >= 0 && (n - x * k) % 2 == 0) {
            possible = true;
            break;
        }
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main(){
    
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