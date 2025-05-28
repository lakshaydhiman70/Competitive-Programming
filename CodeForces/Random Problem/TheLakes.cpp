#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, int &count, 
            vector<pair<int, int>> &directions, vector<vector<int>> &vis, 
            vector<vector<int>> &path) {
    vis[row][col] = 1;
    count += path[row][col];

    for (auto val : directions) {
        int nrow = row + val.first;
        int ncol = col + val.second;

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            !vis[nrow][ncol] && path[nrow][ncol] > 0) {
            dfs(nrow, ncol, n, m, count, directions, vis, path);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> path[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && path[i][j] > 0) {
                int count = 0;
                dfs(i, j, n, m, count, directions, vis, path);
                ans = max(ans, count);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
