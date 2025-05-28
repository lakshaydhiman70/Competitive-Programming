#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    unordered_set<string>st(wordList.begin(), wordList.end());

    queue<pair<string, int>>que;
    que.push({startWord, 1});
    st.erase(startWord);

    while(!que.empty()){
        string currWord = que.front().first;
        int currWordCt = que.front().second;
        que.pop();
        if(currWord == targetWord)return currWordCt;
        for(int i=0;i<currWord.length();i++){
            char originalWord = currWord[i];
            for(char c = 'a'; c<='z'; c++){
                currWord[i] = c;
                if(st.find(currWord) != st.end()){
                    st.erase(currWord);
                    que.push({currWord, currWordCt + 1});
                }
            }
            currWord[i] = originalWord;
        }
    }
    return 0;
}

int main(){
    vector<string>wordList = {"des","der","dfr","dgt","dfs"};
    string startWord = "der";
    string targetWord= "dfs";
    cout<<wordLadderLength(startWord, targetWord, wordList);
}