//https://codeforces.com/contest/1882/problem/B
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int mergeSets(vector<vector<int>>&vec1, vector<int>&vec){
    set<int>mergedSet;
    for(auto res: vec1){
        for(auto res1: res){
            vec[res1]++;
            mergedSet.insert(res1);
        }
    }
    // for(auto res: mergedSet){
    //     cout<<res<<" ";
    // }
    // cout<<endl;

    int mx = INT_MIN;
    auto tempVec = vec;
    for(auto res: vec1){
        tempVec = vec;
        for(auto res1: res){
            tempVec[res1]--;
        }
        int temp = 0;

        for(int i=0;i<tempVec.size();i++){
            if(tempVec[i]!=0)temp++;
        }
        mx = temp == mergedSet.size()?mx:max(mx, temp);
    }
    return mx;
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

        int value = mergeSets(sets, arr);
        cout<<value<<endl;
    }
}