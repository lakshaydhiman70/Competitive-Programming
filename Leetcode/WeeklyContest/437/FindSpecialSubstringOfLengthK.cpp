#include<bits/stdc++.h>
using namespace std;

bool isValid(int start, int end, string s){
    int n = s.size();
    
    if(start >= n || end >= n){
       return false; 
    }

    if(start - 1 >= 0 && s[start - 1] == s[start]){
        return false;
    }

    if(end + 1 < n && s[end + 1] == s[end]){
        return false;
    }
    char var = s[start];
    for(int i = start; i <= end; i++){
        if(s[i] != var)return false;
    }

    return true;
}

bool hasSpecialSubstring(string s, int k) {
    int i = 0, j = k - 1;
    int n = s.size();
    while(j<n){
        if(isValid(i, j, s))return true;
        i++;
        j++;
    }
    return false;
}

int main(){
    bool res = hasSpecialSubstring("abs", 2);
    cout<<res;
}