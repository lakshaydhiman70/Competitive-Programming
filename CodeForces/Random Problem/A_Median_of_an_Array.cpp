#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int i = (n+1)/2-1;
        int j = i;
        while(j<n && vec[i] == vec[j]){
            j++;
        }
        cout<<(j-i)<<"\n";
    }
}