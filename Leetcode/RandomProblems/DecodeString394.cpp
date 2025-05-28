#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<char>st;
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i] == ']'){
            string str = "";
            while(!st.empty() && (st.top() >= 'a' && st.top() <= 'z')){
                str = st.top() + str;
                st.pop();
            }
            string intval = "";
            if(!st.empty() && st.top() == '['){
                st.pop();
                
                while(!st.empty() && (!(st.top() >= 'a' && st.top() <= 'z')) && st.top() != ']'&& st.top() != '['){
                    intval = st.top() + intval;
                    st.pop();
                }
                
            }

            int iterator = intval.size() == 0 ? 1 : stoi(intval);

            for(int j=0; j < iterator; j++){
                for(int val = 0; val<str.size(); val++){
                    st.push(str[val]);
                }
            }
        }
        else{
            st.push(s[i]);
        }
    }

    string ans = "";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main(){
    string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    cout<<decodeString(s);
}