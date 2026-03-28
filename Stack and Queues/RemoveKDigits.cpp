#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char>st;
    int n = num.size();

    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() > num[i] && k>0){
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while(k>0 && !st.empty()){
        st.pop();
        k--;
    }

    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    int i = 0;
    while (i < ans.size() && ans[i] == '0') i++;
    ans = ans.substr(i);

    return ans.empty() ? "0" : ans;
}


int main(){
    string num = "1432219";
    int k = 3;
    cout<<removeKdigits(num, k);
}