#include<bits/stdc++.h>
using namespace std;

//We shall use the range based solution.
bool checkValidString(string s) {
    int lo = 0, hi = 0;
    for (char c : s) {
        if (c == '(') {
            lo++;
            hi++;
        } else if (c == ')') {
            lo--;
            hi--;
        } else { // '*'
            lo--;    // '*' as ')'
            hi++;    // '*' as '('
        }
        if (hi < 0) return false; // too many closing
        lo = max(lo, 0); // lo can't be negative
    }
    return lo == 0;
}

//This recursive solution is giving TLE.
bool solve(int i, string s, int ct){
    if(i >= s.size()){
        return ct == 0;
    }

    if(s[i] == '('){
        return solve(i + 1, s, ct + 1);
    }
    else if(s[i] == ')'){
        return solve(i + 1, s, ct - 1);
    }
    else{
        s[i] = '(';
        auto call1 = solve(i + 1, s, ct + 1);
        s[i] = ')';
        auto call2 = solve(i + 1, s, ct - 1);
        s[i] = '*';
        auto call3 = solve(i + 1, s, ct);

        return call1 || call2 || call3;
    }
}

bool checkValidString(string s) {
    return solve(0, s, 0);
}

int main(){
    cout<<checkValidString("())");
}