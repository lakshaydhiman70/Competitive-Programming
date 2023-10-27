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
        string s1, s2;
        cin>>s1>>s2;
        bool flag = false, flag1 = false;
        for(int i=1;i<s1.size()-1;i++){
            if(s1[i] == s2[i] && s1[i]== '1'){
                flag = true;
                break;
            }

            if(s1[i] != s2[i]){
                break;
            }
        }

        for(int i=1;i<s1.size()-1;i++){
            if(s1[s1.size()-i-1] == s2[s1.size()-i-1] && s1[s1.size()-i-1]=='0'){
                // cout<<s1.size()-i-1;
                // cout<<s1[s1.size()-i-1]<<" "<<s2[s1.size()-i-1]<<nl;
                flag1 = true;
                break;
            }
            else if(s1[s1.size()-i-1] != s2[s1.size()-i-1]){
                break;
            }
        }

        flag || flag1 ? cout<<"YES"<<nl:cout<<"NO"<<nl;
    }
}