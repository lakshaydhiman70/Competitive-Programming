#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sp ' '
#define int                 long long
#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vi vector<int>
#define fr(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())
#define mxe(v)  *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define lcm(a, b) (((a) * (b)) / __gcd((a), (b)))
#define countBits(n) ({ int count = 0, val = 1, temp = (n); while(temp > 0) { temp = temp >> 1; count++; } count; })
#define xorFromZeroToN(n) ((n) % 4 == 0 ? (n) : ((n) % 4 == 1 ? 1 : ((n) % 4 == 2 ? (n) + 1 : 0)))
int MOD=1e9+7;

/// ====================================PRIME utility ==================================================
int sz=1e6+5;
bool PrimeSieve[1000005];   // 1e6+5
void buildSieve(){
    for(int i=2;i<=sz;i++)    PrimeSieve[i]=1;
    PrimeSieve[0]=0;// 
    PrimeSieve[1]=0;    // 1 is neither prime nor composite 
    for(int i=2;i<sz;i++){
        if(PrimeSieve[i]==0)    continue;       // the current number itself is composite 
        for(int j=2;j*i<sz;j++){
            PrimeSieve[i*j]=0;
        }
    }
}
// add SieveOfEratosthenes
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)  return 0;
    }
    return 1;
}

/// ====================================PRIME utility ENDS here==================================================

int getCeil(int a, int b){
    return (a+1)/b;
}

bool isValid(vector<int>&inp, int x, int mid){
    int val = 0;

    for(int i=0;i<inp.size();i++){
        if(inp[i] < mid){
            x-=(mid - inp[i]);
        }
    }

    return x>=0;
}


void solve() {
    int n, x;
    cin>>n>>x;

    vector<int>inp(n);
    fr(i,n)cin>>inp[i];

    int low = 0, high = INT_MAX, mid;


    while(low <= high){
        mid = (low + high)/2;

        if(isValid(inp, x, mid)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout<<high<<endl;
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