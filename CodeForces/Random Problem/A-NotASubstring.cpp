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
        bool patA = false; //((()))
        bool patB = false; //()()()()()

        if(s.size()==2 && s[0] == '(' && s[1] ==')'){
            cout<<"NO"<<nl;
            continue;
        }
        else if(((s[0] == '(' && s[1] =='(') || (s[s.size()-2] == ')' && s[s.size()-1] ==')'))||
            ((s[0] == '(' && s[1]==')') && s[2] == ')') && ((s[0] == '(' && s[1]=='(') && s[2] == ')')){
            patA=true;
        }

        else {
            patB=true;
        }
        
        if(patB){
            cout<<"YES"<<nl;
            for(int i=0;i<s.size();i++){
                cout<<'(';
            }
            for(int i=0;i<s.size();i++){
                cout<<')';
            }
        }
        else if(patA){
            cout<<"YES"<<nl;
            for(int i=0;i<s.size();i++){
                cout<<"()";
            }
        }
        cout<<endl;
    }
}