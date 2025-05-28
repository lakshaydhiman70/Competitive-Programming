//https://codeforces.com/problemset/problem/1903/A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>val(n);
        int prev = 0;
        bool isSorted = true;
        for(int i=0; i<n; i++){
            cin>>val[i];
            if(prev>val[i]){
				isSorted = false;
			}
			else{
				prev = val[i];
			}
        }
        
        if(isSorted){
            cout<<"Yes\n";
        }
        else{
            if(k >= 2){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }
}