#include<bits/stdc++.h>
using namespace std;
void printVectorOfVectors(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout <<endl;
    }
}
void printAllPermutations(int n, vector<int>&v , vector<int>&vec, vector<vector<int>>&ans,map<int,int>&mp){
    if(vec.size() == n){
        ans.push_back(vec);
        return;
    }
    for(int i = 0; i<n ;i++){
        if(mp[v[i]]==0){
            mp[v[i]]=1;
            vec.push_back(v[i]);
            printAllPermutations(n,v, vec, ans,mp);
            vec.pop_back();
            mp[v[i]]=0;
        }
        
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>vec;
    map<int,int>mp;
    vector<vector<int>>ans;
    printAllPermutations(n,v, vec, ans,mp);
    printVectorOfVectors(ans);
}