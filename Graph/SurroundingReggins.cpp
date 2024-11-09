#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& board,
         vector<pair<int,int>>& directions){

    vis[row][col] = 1;

    for(auto dir: directions){
        int nrow = row + dir.first;
        int ncol = col + dir.second;

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
            dfs(nrow, ncol, n, m, vis, board, directions);
        }
    }
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<pair<int,int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if(board[i][j] == 'O' && !vis[i][j]){
                    dfs(i, j, n,  m, vis, board, directions);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};

    
    solve(board);

    for(auto res : board){
        for(auto val : res){
            cout<<val<<" ";
        }
        cout<<endl;
    }
}