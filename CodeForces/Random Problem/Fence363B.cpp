#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;

    vector<int>inp(n);
	int minSum = INT_MAX;
	int idx = 0;
    for(auto &it: inp){
        cin>>it;
    }

    for(int i=1;i<n;i++){
        inp[i] += inp[i-1]; 
    }

    int it1 = 0, it2 = k-1;

    while (it2 < n){
        if(it1 == 0){
            if(inp[it2] < minSum){
                idx = it1;
                minSum = inp[it2];                
            }
        }
        else{
            int val = inp[it2] - inp[it1-1];
            if(val < minSum){
                idx = it1;
                minSum = val;                
            }
        }

        it1++;
        it2++;
    }
    

	cout<<idx+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
    #endif
	solve();
}