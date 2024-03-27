#include<bits/stdc++.h>
using namespace std;

bool isValid(string s, int idx){
    if(idx > s.size()/2){
        return true;
    }
    if(s[idx] != s[s.size()-idx-1]){
        return false;
    }
    return isValid(s, idx+1);
}
bool isPalindrome(string s) {
    string result;
    for (char c : s) {
        result += std::tolower(c);
    }
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    cout<<result;
    return isValid(result, 0);
}

int main(){
    cout<<isPalindrome(" ");
}