//https://codeforces.com/problemset/problem/1855/B
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())
 
const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if((s.back()-'0')%2==1){
            cout<<1<<nl;
        }
        else{
            auto IntValue = stoi(s);
            for(int i=0; i <= IntValue*IntValue; i++){
                
            }
        }
    }
}