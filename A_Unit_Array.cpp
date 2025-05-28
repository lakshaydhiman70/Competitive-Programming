#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int nval = 0, pval = 0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x < 0){
            nval++;
        }
    }

    pval = n - nval;

    if(nval < pval){ //means sum is positive
        if(nval % 2 == 0){ // if negative values are even then we shall get the positive product
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else{
        int temp = nval - pval;

        nval -= temp;
        pval += temp;

        int ans = nval % 2 == 1 ? ans + 1 : ans;
        cout<<ans;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}