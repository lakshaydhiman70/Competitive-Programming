#include<bits/stdc++.h>

#define MOD 1000000007
 
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // long long cur = 0;
    // for (int e : a) {
    //     auto res = e - (cur % e);
    //     cur += e - (cur % e);
    // }
    // cout << cur << endl;
    int ans = a[0];
    for(int i=1; i<n; i++){
        if(a[i] > ans){
            ans = a[i];
        }
        else{
            ans = ((ans / a[i]) + 1) * a[i];
        }
    }
    cout<<ans<<endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    // cout<<3%2;
    return 0;
}


// int main(){
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif
//     int n, x;
//     cin >> n >> x;
//     vector<int> a(n);
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
 
//     vector<vector<int>> dp(n + 1, vector<int>(x + 1));
//     // dp[i][k] = number of ways to construct sum k
//     // such that all coins before coin[i] are unusable
    
//     for(int i = 0; i < n; i++){
//         dp[i][0] = 1;
//     }
    
//     for(int i = n - 1; i >= 0; i--){
//         for(int sum = 1; sum <= x; sum++){
//             int skipping = dp[i + 1][sum];
//             int picking = 0;
//             if(a[i] <= sum){
//                 picking = dp[i][sum - a[i]];
//             }
//             dp[i][sum] = (skipping + picking) % MOD;
//         }
//     }
//     cout << dp[0][x] << endl;
    
//     for(auto res: dp){
//         for(auto res1 : res){
//             cout<<res1<<" ";
//         }
//         cout<<"\n";
//     }
//     return 0;
// }