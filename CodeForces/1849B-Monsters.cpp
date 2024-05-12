#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);

        for(auto &inp: v){
            cin>>inp;
            inp%=k;
            if(!inp)inp = k;
        }
        
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);

        stable_sort(ord.begin(), ord.end(), [&](int i, int j) {
            return v[i] > v[j];
        });
        for (auto &x : ord) cout << x + 1 << ' ';
        cout << endl;
    }
}