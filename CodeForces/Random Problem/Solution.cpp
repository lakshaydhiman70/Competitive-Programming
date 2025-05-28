#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pair<int, int>>
#define umi unordered_map<int,int>
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

#define setBit(n, pos)     ((n) | (1LL << (pos)))          // Set bit at pos
#define clearBit(n, pos)   ((n) & ~(1LL << (pos)))         // Clear bit at pos
#define toggleBit(n, pos)  ((n) ^ (1LL << (pos)))          // Toggle bit at pos
#define checkBit(n, pos)   (((n) >> (pos)) & 1)            // Check if bit at pos is set

#define countSetBits(n)    (__builtin_popcountll(n))       // Count number of 1s
#define trailingZeros(n)   (__builtin_ctzll(n))            // Count trailing 0s
#define leadingZeros(n)    (__builtin_clzll(n))            // Count leading 0s (for 64-bit)

#define isPowerOfTwo(n)    ((n) && !((n) & ((n) - 1)))      // Check if n is power of two
#define lowestBit(n)       ((n) & -(n))                     // Isolate lowest set bit
#define turnOffLowestBit(n) ((n) & ((n) - 1))               // Turn off lowest set bit

#define findMSB(n)       (63 - __builtin_clzll(n))

#define sortv(v) sort(all(v))
#define sortvd(v) sort((v).begin(), (v).end(), greater<>())
#define rev(v) reverse(all(v))
#define isEven(x) ((x) % 2 == 0)
#define isOdd(x) ((x) % 2 != 0)
#define ub(arr, key) (upper_bound((arr).begin(), (arr).end(), (key)) - (arr).begin())
#define lb(arr, key) (lower_bound((arr).begin(), (arr).end(), (key)) - (arr).begin())
#define psv(arr, n) for(int i=1;i<n;++i)arr[i]+=arr[i-1];


#ifndef ONLINE_JUDGE
    #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", dbgOut(__VA_ARGS__)
    void dbgOut() { cerr << endl; }
    template<typename T, typename... Args>
    void dbgOut(T a, Args... args) {
        cerr << a << " ";
        dbgOut(args...);
    }

    template<typename T>
    void printContainer(const T &container) {
        cerr << "[ ";
        for (const auto &elem : container) cerr << elem << " ";
        cerr << "]\n";
    }

    template<typename A, typename B>
    ostream& operator<<(ostream &out, const pair<A, B> &p) {
        return out << "(" << p.first << ", " << p.second << ")";
    }

    #define dbgv(v) cerr << #v << " = "; printContainer(v)
#else
    #define dbg(...)
    #define dbgv(v)
#endif


int find_MSB(int num){
    int pos = -1;
    while(num > 0){
        num >>= 1;
        pos++;
    }
    return pos;
}

void solve() {
    int n;
    cin >> n;

    vi v(n);
    rv(v);

    map<int, int> mp;

    for (int num : v) {
        if (num > 0) {
            int pos = findMSB(num);
            mp[pos]++;
        }
    }

    int totalPairs = 0;

    for (auto &it : mp) {
        int pos = it.first;
        int count = it.second;
        if (count >= 2) {
            totalPairs += count * (count - 1) / 2;
        }
    }

    cout << totalPairs << '\n';
}



int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--) solve();
}

/*
here for the solution we need to find two numbers having same most significant bit and count the pairs that's it.
eg: (4, 7), (6, 5), (2, 3)
*/