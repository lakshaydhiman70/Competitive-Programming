#include<bits/stdc++.h>
using namespace std;
void oneton(int i, int n){
    if(i>n)return;
    oneton(i+1,n);
    cout<<i<<"\n";
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    #endif
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    oneton(1,5);
}