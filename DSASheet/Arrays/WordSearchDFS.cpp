#include<bits/stdc++.h>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    unordered_map<char, int> tally;
    for (char c : word)
        tally[c]++;
    if (tally[word.front()] > tally[word.back()])
        reverse(word.begin(), word.end());
    int pos = 1;
    const int len_word = word.length();
    
    auto dfs = [&](int i, int j) -> bool {
        if (pos == len_word)
            return true;
        char letter = word[pos];
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [a, b] : dirs) {
            int ii = i + a, jj = j + b;
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && board[ii][jj] == letter) {
                pos++;
                char temp = board[ii][jj];
                board[ii][jj] = '\0';
                if (dfs(ii, jj))
                    return true;
                pos--;
                board[ii][jj] = temp;
            }
        }
        return false;
    };

    char f = word.front();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char letter = board[i][j];
            if (letter == f) {
                board[i][j] = '\0';
                if (dfs(i, j))
                    return true;
                board[i][j] = letter;
            }
        }
    }
    return false;
}

int main(){
    
}