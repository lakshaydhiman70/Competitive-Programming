#include<bits/stdc++.h>
using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();        
    int n = m ? board[0].size() : 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int count = 0;
            for(int k = max(i-1, 0); k < min(i+2, m); k++){
                for(int l = max(j-1, 0); l<min(j+2, n); l++){
                    count += board[k][l] & 1;
                }
                if (count == 3 || count - board[i][j] == 3){
                    board[i][j] |= 2;
                }
            }
        }
    }
    
    for (int i=0; i<m; ++i){
        for (int j=0; j<n; ++j){
            board[i][j] >>= 1;
        }
    }         
}

int main(){

}