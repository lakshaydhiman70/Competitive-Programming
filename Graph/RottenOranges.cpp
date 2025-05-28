#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int,int>, int>> que;
    int first = 0;
    int ans = 0;

    vector<pair<int,int>>difference = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    for(int i=0;i<n;i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 2){
                que.push({{i, j},0});
            }
            else if(grid[i][j] == 1){
                first++;
            }
        }
    }

    while(!que.empty()){
        auto frontele = que.front();
        que.pop();
        int row = frontele.first.first;
        int col = frontele.first.second;

        int time = frontele.second;
        ans = time;

        for(auto diff : difference){
            int newRow = row + diff.first;
            int newCol = col + diff.second;

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                first--;
                que.push({{newRow, newCol}, time + 1});
                grid[newRow][newCol] = 2;
            }
        }
    }
}

int main(){

}