#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
	bool flag = false;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        if(x == k){
			flag = true;
            // break;
		}
        
    }
	if(flag)cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}