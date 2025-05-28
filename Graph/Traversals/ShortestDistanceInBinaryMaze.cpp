#include<bits/stdc++.h>
using namespace std;

bool isValidIdx(int r, int c, int n, int m, vector<vector<int>>& grid) {
return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1);
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
const int mod = 1e5;
int n = grid.size(), m = grid[0].size();
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;

vector<vector<int>> dist(n, vector<int>(m, mod));
vector<pair<int, int>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

que.push({0, source});
dist[source.first][source.second] = 0;

while (!que.empty()) {
    auto currDist = que.top().first;
    auto node = que.top().second;
    que.pop();
    int row = node.first, col = node.second;

    if (row == destination.first && col == destination.second)
        return currDist;

    for (auto it : move) {
        int newRow = row + it.first;
        int newCol = col + it.second;

        if (isValidIdx(newRow, newCol, n, m, grid) && currDist + 1 < dist[newRow][newCol]) {
            dist[newRow][newCol] = currDist + 1;
            que.push({dist[newRow][newCol], {newRow, newCol}});
        }
    }
}

return dist[destination.first][destination.second] == mod ? -1 : dist[destination.first][destination.second];
}


int main(){
vector<vector<int>>grid = {{1, 1, 1, 1},
                            {1, 1, 0, 1},
                            {1, 1, 1, 1},
                            {1, 1, 0, 0},
                            {1, 0, 0, 1}};

cout<<shortestPath(grid, {0, 0}, {3, 3});
}