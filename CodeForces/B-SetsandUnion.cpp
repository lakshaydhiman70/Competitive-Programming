//https://codeforces.com/contest/1882/problem/B
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void mergetTwoSets(vector<int>&vec, vector<int>&vec1){
    
}

void mergeSets(vector<vector<int>>&vec1, vector<int>&vec){
    for(auto res: vec1){
        for(auto res1: res){
            vec[res1]++;
        }
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
        int q;
        cin>>q;
        vector<int>arr(51,0);
        vector<vector<int>>sets;
        while(q--){
            int n;
            cin>>n;
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                cin>>vec[i];
            }
            sets.push_back(vec);
        }
        for(auto res: sets){
            for(auto test: res){
                cout<<test<<" ";
            }
            cout<<endl;
        }
    }
    
}