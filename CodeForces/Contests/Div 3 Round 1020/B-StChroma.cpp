#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979323846

#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define rv(v) for (auto &x : v) cin >> x;
#define each(x, a) for (auto &x : a)

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define rep0(i, n) for(int i = 0; i < (n); ++i)

#define sortv(v) sort(all(v))
#define sortvd(v) sort((v).begin(), (v).end(), greater<>())
#define rev(v) reverse(all(v))
#define isEven(x) ((x) % 2 == 0)
#define isOdd(x) ((x) % 2 != 0)
#define lb lower_bound
#define ub upper_bound

#ifndef ONLINE_JUDGE
    #define dbg(x) cerr << #x << " = " << x << endl
#else
    #define dbg(x)
#endif

void solve() {
    int n, x;
    cin>>n>>x;

    rep(i, 0, n){
        if(i != x){
            cout<<i<<" ";
        }
    }

    if(x != n){
        cout<<x<<" ";
    }
    cout<<endl;
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("../../input.txt", "r", stdin);
        freopen("../../output.txt", "w", stdout);
    #endif

    int t = 1;
    cin >> t;
    while(t--) solve();
}