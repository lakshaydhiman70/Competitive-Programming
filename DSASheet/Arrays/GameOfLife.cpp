#include<bits/stdc++.h>
using namespace std;

/*
    1. Any live cell less then 2 live cells dies

    2. Any live cell greater then 3 live neighbours dies with over population.

    3. A dead cell will live if it's having 3 live neightbours

*/

void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> tempBoard = board;

    vector<pair<int,int>> directions = {{1, 1}, {-1, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int onect = 0;
            for(auto it: directions){
                int newrow = i + it.first;
                int newcol = j + it.second;

                if(newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && board[newrow][newcol] == 1){
                    onect++;
                }
            }
            if(board[i][j] == 1 && onect < 2){
                tempBoard[i][j] = 0;
            }
            else if(board[i][j] == 1 && onect > 3){
                tempBoard[i][j] = 0;
            }
            else if(board[i][j] == 0 && onect == 3){
                tempBoard[i][j] = 1;
            }
        }
    }
}

int numPairsDivisibleBy60(vector<int>& time) {
    int n = time.size();
    unordered_set<int> tempset(time.begin(), time.end());
    int count = 0;
    for(int i=0;i<n;i++){
        int val = (time[i] * 60) - time[i];
        if(tempset.find(val) != tempset.end()){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int>time = {30,20,150,100,40};

    /*
        20, 30, 40, 100, 150;
        
    */
    cout<<numPairsDivisibleBy60(time);
}