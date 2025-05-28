#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int prod=1,sum=0;
    for(int i=0; i<n; ++i)
    {
        int x;
        cin>>x;
        prod *=x;
        sum += x;
    }
    for(int i=0; ; ++i)
    {
        if(sum>=0 && prod==1)
        {
            cout<<i<<endl;
            return;
        }
        prod *= -1;
        sum +=2;
    }
}

int main(){
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