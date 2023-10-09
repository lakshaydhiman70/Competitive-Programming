#include<bits/stdc++.h>
using namespace std;

void combI(int ind, vector<int>v, int k, vector<int>&vec, vector<vector<int>>&ans){
    if(k<0 || ind>=v.size()){
        return;
    }
    if(k==0){
        ans.push_back(vec);
        return;
    }
    vec.push_back(v[ind]);
    combI(ind, v, k-v[ind], vec,ans);
    vec.pop_back();
    combI(ind+1, v, k, vec,ans);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>>ans;
    vector<int>vec;
    combI(0, v, k, vec, ans);
    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}