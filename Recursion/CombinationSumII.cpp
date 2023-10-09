#include<bits/stdc++.h>
using namespace std;
void combII(int ind, vector<int> v, int k, vector<int>&vec, vector<vector<int>>&ans){
    if(k==0){
        ans.push_back(vec);
    }
    if(ind >= v.size() || k<0){
        return;
    }
    for(int i=ind ; i<v.size(); i++){
        if(((i>0)&&(v[i]!=v[i-1])||i==0)&&(k-v[i]>=0)&&(v[i]<=k)){
            vec.push_back(v[i]);
            combII(i,v,k-v[i],vec,ans);
            vec.pop_back();
        }
    }
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
    combII(0, v, k, vec, ans);
    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}