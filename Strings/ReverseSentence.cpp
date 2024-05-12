#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    int i=n-1,j=n-1;
    string ans = "";
    // while(j>=0 && s[j] == ' ')j--;
    // i=j;
    while(i>=0 && i>=0){
        //eliminating the spaces form the end
        while(j>=0 && s[j] == ' ')j--;

        // //making J to stay at the end of the word and pushing i to the start of the word
        while(i>=0 && s[i] != ' ')i--;
        // i+=1; //incrementing the index as we are on the space
        cout<<i+1<<" "<<j+1<<endl;
        ans += s.substr (i+1, j+1); //picking the word from i to j
        ans += "-";
        cout<<s.substr (i+1, j+1)<<endl;

        while(j>=0 && s[j] != ' ')j--;
        while(i>=0 && s[i] == ' ')i--;
    }
    return ans;
}

int main(){
    string str = "the sky is blue";
    cout<<reverseWords(str)<<endl;
}