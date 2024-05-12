#include<bits/stdc++.h>
using namespace std;

void rec(int val, vector<int>& vec, vector<vector<int>>& ans){
    if(vec.size() == 3){
        ans.push_back(vec);
        return;
    }
    
    rec(1, vec, ans);
    rec(2, vec, ans);
    rec(3, vec, ans);
}

int main(){
    vector<int>vec;
    vector<vector<int>>ans;
    rec(0, vec, ans);
    for(auto res: ans){
        for(auto val: res){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}