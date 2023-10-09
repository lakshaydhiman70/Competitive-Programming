#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n){
    for(int i=0; i<col; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i=row, j=col; i<n && j>=0; i++, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void NQueens(int col, vector<string>& board, vector<vector<string>>& ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            NQueens(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 20;
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    NQueens(0, board, ans, n);

    for (auto res : ans) {
        for (auto row : res) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
