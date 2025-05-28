#include<bits/stdc++.h>
using namespace std;
/*
 GFG problem link: https://www.geeksforgeeks.org/problems/word-ladder-ii/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder-ii
*/
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string>st(wordList.begin(), wordList.end());
    queue<vector<string>>que;
    que.push({beginWord});
    vector<string>usedOnLevel;
    usedOnLevel.push_back(beginWord);

    int level = 0;

    vector<vector<string>>ans;
    while (!que.empty()){
        auto vec = que.front();
        que.pop();

        if(vec.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();

        if(word == endWord){
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.push_back(vec);
            }
        }        

        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    que.push(vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    
    return ans;
}

int main(){

}