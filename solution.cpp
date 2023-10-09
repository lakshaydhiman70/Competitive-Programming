#include <bits/stdc++.h>
using namespace std;

string reverseStringWordWise(string s)
{
    int n=s.size();
    int i=n-1;
    string tempStr="";
    while(i>=0){
        int j=i;
        bool isSpaceNeeded = false;
        while(s[j]!=' ' && j>=0){
            j--;
        }
        // cout<<j<<" "<<i<<"\n";
        for(int k=j+1;k<=i;k++){
            tempStr+=s[k];
        }
        if(s[j]==' ' && j>=0)tempStr+=' ';
        i=j-1;
    }
    //  cout<<s.substr(5,8);
    return tempStr;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}
//suggested code is below
// #include <iostream>
// #include <vector>
// using namespace std;

// string reverseStringWordWise(string input)
// {
//     vector<string> words;
//     int n = input.size();
//     string word;
//     // Extract each word
//     for (int i = 0; i < n; i++)
//     {
//         if (input[i] == ' ')
//         {
//             words.push_back(word);
//             word = "";
//         }
//         else
//         {
//             word.push_back(input[i]);
//         }
//     }
//     words.push_back(word);
    
//     // Reverse the words in the sentence
//     int i = 0, j = words.size() - 1;
//     while (i < j)
//     {
//         swap(words[i], words[j]);
//         i++;
//         j--;
//     }

//     // Append back the words
//     string ans;
//     for (int i = 0; i < words.size(); i++)
//     {
//         ans.append(words[i]);
//         ans.push_back(' ');
//     }
//     return ans;
// }

// int main()
// {
//     string s;
//     getline(cin, s);
//     string ans = reverseStringWordWise(s);
//     cout << ans << endl;
// }