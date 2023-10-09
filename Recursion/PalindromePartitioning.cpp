#include<bits/stdc++.h>
using namespace std;

bool IsPallindrome(int start, int end, string s){
    while(start != end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void PallindromePartitioning(int idx, string s, vector<string>&path, vector<vector<string>>&res){
    if(idx == s.size()){
        res.push_back(path);
    }

    for(int i=idx; i<s.size(); i++){
        if(IsPallindrome(idx, i, s) || idx == i){
            path.push_back(s.substr(idx, i-idx+1));
            PallindromePartitioning(i+1, s, path, res);
            path.pop_back();
        }
    }
}

int main(){
    string s = "abaa";
    vector<string>path;
    vector<vector<string>>res;
    PallindromePartitioning(0, s, path, res);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
         cout<<endl;
    }
}