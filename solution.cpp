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

    template<typename K, typename V>
    void printContainer(const map<K, V> &m) {
        cerr << "{ ";
        for (const auto &kv : m) cerr << kv.first << ": " << kv.second << ", ";
        cerr << "}\n";
    }

    template<typename K, typename V>
    void printContainer(const unordered_map<K, V> &m) {
        cerr << "{ ";
        for (const auto &kv : m) cerr << kv.first << ": " << kv.second << ", ";
        cerr << "}\n";
    }

    #define dbgv(v) cerr << #v << " = "; printContainer(v)
#else
    #define dbg(...)
    #define dbgv(v)
#endif

void permute(vector<bool>&used, int n, vector<string>&ans, string s, string curr){
    if(curr.size() == n){
        ans.push_back(curr);
        return;
    }

    for(int i=0; i<n; i++){
        dbgv(used);
        if(!used[i]){
            if(i !=0 && s[i] == s[i-1]&& !used[i - 1]) continue;
            if(i != 0){
                bool test = used[i-1];
                auto t = test;
            }
            curr.push_back(s[i]);
            used[i] = true;
            permute(used, n, ans, s, curr);
            curr.pop_back();
            used[i] = false;
        }
    }
}


void  combinationSum(int i, int n, int k, vector<int>&arr, vector<int>&temp){
    
    if (k < 0) return;
    if (i == n) {
        if (k == 0) {
            for (int it : temp) cout << it << " ";
            cout << endl;
        }
        return;
    }

    //pick
    temp.push_back(arr[i]);
    combinationSum(i, n, k - arr[i], arr, temp);

    //not pick
    temp.pop_back();
    combinationSum(i + 1, n, k, arr, temp);
}


void combinationSum2(int idx, int k, vector<bool>&flag, vector<int>&arr, vector<int>&ans){
    if(idx > arr.size()){
        return;
    }
    if(k < 0)return;
    if(k == 0){
        for(auto &it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i = idx; i<arr.size(); i++){
        if(!flag[i] && (k - arr[i]) >= 0){

            if(i > 0 && arr[i] == arr[i-1] && !flag[i-1]){
                /*
                Here we are checking if we are picking the current element and
                the previous element is also same then we need to check if 
                we have already picked the previous element yes or no if we have not picked 
                it then we don't need to move forward.
                here main motive is to pick the same elements together.
                */
                continue;
            }

            ans.push_back(arr[i]);
            flag[i] = true;
            combinationSum2(i+1, k - arr[i], flag, arr, ans);
            ans.pop_back();
            flag[i] = false;
        }
    }
}

void permutation(int idx, vector<int>&arr){
    if(idx == arr.size()){
        for(auto &it: arr){
            cout<<it<<" ";
        }

        cout<<endl;
        return;
    }


    for(int i = idx; i<arr.size(); i++){
        swap(arr[idx], arr[i]);
        permutation(idx + 1, arr);
        swap(arr[idx], arr[i]);
    }
}


void solve() {
    vector<int>arr = {2,5,2,1,2}, temp;
    // combinationSum(0, arr.size(), 7, arr, temp);

    // sort(arr.begin(), arr.end());
    // vector<bool>flag(arr.size(), false);
    // combinationSum2(0, 5, flag, arr, temp);

    vector<int>vec = {1, 2, 3};
    permutation(0, vec);
}

int32_t main() {
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) solve();
}