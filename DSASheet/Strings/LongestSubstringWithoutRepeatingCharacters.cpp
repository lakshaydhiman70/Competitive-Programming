#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int mxans = 1;
    unordered_set<string>st;
    unordered_set<char>st1;
    for(int i=0;i<n;i++){
        string substr="";
        while(i<n && st1.find(s[i]) == st1.end()){
            st1.insert(s[i]);
            substr+=s[i];
            i++;
        }
        st1.clear();
        if(st.find(substr) == st.end()){
            st.insert(substr);
            int mxlength = substr.length();
            mxans = max(mxlength, mxans);
            cout<<substr<<endl;
        }
        i-=1;
    }
    return mxans;
}

int main(){
    string s = "dvdf";
    lengthOfLongestSubstring(s);
}

