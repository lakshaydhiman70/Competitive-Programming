#include<bits/stdc++.h>
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

#define setBit(n, pos)     ((n) | (1LL << (pos)))
#define clearBit(n, pos)   ((n) & ~(1LL << (pos)))
#define toggleBit(n, pos)  ((n) ^ (1LL << (pos)))
#define checkBit(n, pos)   (((n) >> (pos)) & 1)

#define countSetBits(n)    (__builtin_popcountll(n))
#define trailingZeros(n)   (__builtin_ctzll(n))
#define leadingZeros(n)    (__builtin_clzll(n))

#define isPowerOfTwo(n)    ((n) && !((n) & ((n) - 1)))
#define lowestBit(n)       ((n) & -(n))
#define turnOffLowestBit(n) ((n) & ((n) - 1))

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


/*
    we have to replace tires
    we have to replace n tires:
    There are two types of busses: 
    one with 2 axles which is having 4tires
    one with 4 axles which is having 6tires

    the main problem here is we have given total no of tires as n
    and we need to determine total no of min and max buses we
    can have.


    10: max: 2: min: 2;
    12: max: 3, min: 2;
    14: max: 3, min: 3;

    20: max: 6 + 4: 

    if one we can make from combination then?
    20: 6*2 and 4*2
    is there any other way here?

    yes: 4*5

    let's start with 4:
    4 = 1, 6 = 0

    6:
    4 = 0, 6 = 1

    8: 
    4 = 2. 6 = 0

    10: 
    4 = 1, 6 = 1

    12: 4 = 0, 6 = 2 & 4 = 3

    14: 4 = 2, 6 = 1

    16: 
*/

void solve() {
    int n;
    cin>>n;

    if(n < 4 || isOdd(n)){
        cout<<-1<<endl;
        return;
    }

    //find max
    int mxval = 0;
    int fours = n / 4;
    int rem = n % 4;
    if(rem > 0 && rem < 6){
        fours--;
        rem+=4;
    }

    int six = rem / 6;

    mxval = fours + six;

    //min val

    int mnval = 0;
    six = 0;
    fours = 0;

    six = n / 6;
    rem = n % 6;

    if(rem > 0 && rem < 4){
        six--;
        rem+=6;
    }

    fours = rem / 4;

    mnval = fours + six;

    cout<<mnval<<" "<<mxval<<endl;
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) solve();
}