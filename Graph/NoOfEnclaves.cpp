#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis,
        vector<pair<int,int>>& distances){
    vis[row][col] = 1;
    
    for(auto dist : distances){
        int nrow = row + dist.first;
        int ncol = col + dist.second;

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, n, m, grid, vis, distances);
        }
    }
    
}

int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<pair<int,int>> distances = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, n, m, grid, vis, distances);
                }
            }
        }
    }

    int count = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == 1){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<vector<int>> grid = {{0,1,1,0}
                               ,{0,0,1,0}
                               ,{0,1,0,0}
                               ,{0,0,0,0}};

    cout<<numEnclaves(grid);
}