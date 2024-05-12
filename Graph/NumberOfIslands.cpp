#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& grid){
    vis[row][col] = 1;
    queue<pair<int,int>>que;
    int n = grid.size();
    int m = grid[0].size();

    que.push(make_pair(row, col));

    while(!que.empty()){
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Cardinal directions

        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol] == '1') {
                que.push({newRow, newCol});
                vis[newRow][newCol] = 1;
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n, vector<int>(m, 0));
    int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '1'){
                count++;
                bfs(i, j, vis, grid);
            }
        }
    } 
    return count;     
}

int main(){
     
}

// sc - order of n square
// tc - o(n square) 