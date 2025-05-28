#include<bits/stdc++.h>
using namespace std;

bool maxSubstringLength(string s, int k) {
    unordered_map<int,int>first, last;
    int n = s.size();

    //fill the array with first and last occurances of the characters.
    for(int i=0; i < n; i++){
        if(first.find(s[i]) == first.end()){
            first[s[i]] = i;
        }
        last[s[i]] = i;
    }

    for(int i=0;i<n;i++){
        cout<<s[i] <<" "<<first[s[i]]<<" "<<last[s[i]]<<endl;
    }
}

int main(){
    string s = "abcdbaefab";
    int k = 2;
    cout<<maxSubstringLength(s, k);
}