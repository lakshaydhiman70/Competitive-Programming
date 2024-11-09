#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return mat;
    int m = mat[0].size();

    queue<pair<int, int>> que;
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX)); // Initialize distances with a large number
    vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize visited matrix

    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    // Initialize queue with all 0s and their distances as 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                que.push({i, j});
                ans[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    // Perform BFS
    while (!que.empty()) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();

        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !vis[newRow][newCol]) {
                vis[newRow][newCol] = 1;
                ans[newRow][newCol] = ans[row][col] + 1;
                que.push({newRow, newCol});
            }
        }
    }
    return ans;
}

int main(){

}