#include <bits/stdc++.h>
using namespace std;

bool isvalid(int row, int col, int n, vector<string>& board) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void nqueens(int n, int col, vector<string>& board, int& ans) {
    if (col == n) {
        ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (board[i][col] == '.' && isvalid(i, col, n, board)) {
            board[i][col] = 'Q';
            nqueens(n, col + 1, board, ans);
            board[i][col] = '.';
        }
    }
}

int main() {
    int n = 8;

    unordered_set<int>set;
    
    // vector<string> board = {
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "........",
    //     "....*..."
    // };


    int ans = 0;

    vector<string>board(n);
    
    for(int i=0; i<n; i++){
        cin>>board[i];
    }

    nqueens(n, 0, board, ans);
    cout<<ans<<endl;
}
