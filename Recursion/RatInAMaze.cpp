//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<bits/stdc++.h>
using namespace std;

void findPathHelper(int i, int j, vector<vector<int>>&maze, int n, vector<string>& ans, string move,vector<vector<int>>&vis){
    if(i>=n-1 && j>=n-1){
        ans.push_back(move);
        return;
    }

    if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i + 1, j, maze, n, ans, move + 'D', vis);
      vis[i][j] = 0;
    }

    //left
    if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j - 1, maze, n, ans, move + 'L', vis);
      vis[i][j] = 0;
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1) {
      vis[i][j] = 1;
      findPathHelper(i, j + 1, maze, n, ans, move + 'R', vis);
      vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1) {
      vis[i][j] = 1;
      findPathHelper(i - 1, j, maze, n, ans, move + 'U', vis);
      vis[i][j] = 0;
    }
}


int main(){
    int n = 4;
    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
    vector<string>ans;

    vector<vector<int>>vis(n,vector<int>(n, 0));

    if(maze[0][0] == 1)findPathHelper(0, 0, maze, n, ans, "D",vis);

    for(auto res: ans){
        cout<<res<<endl;
    }
}