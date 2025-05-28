#include<bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string,int>>que;
    que.push({startWord, 1});
    unordered_set<string>set (wordList.begin(), wordList.end());

    set.erase(startWord);

    while(!que.empty()){
        string word = que.front().first;
        int count = que.front().second;
        que.pop();

        if(word == targetWord){
            return count;
        }

        for(int i=0;i<word.size();i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;

                if(set.find(word) != set.end()){
                    set.erase(word);
                    que.push({word, count + 1 });
                }
            }
            word[i] = original;
        }
    }
    
    return 0;
}

int main(){
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    int ans = wordLadderLength(startWord, targetWord, wordList);
 
    cout << ans;
}