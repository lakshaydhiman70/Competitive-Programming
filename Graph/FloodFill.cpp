#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int iniColor, int newColor,
         vector<pair<int,int>>directions){
    ans[row][col] = newColor;
    
    int n = image.size();
    int m = image[0].size();

    for (auto dir : directions){
        int newRow = row + dir.first;
        int newCol = col + dir.second;
        
        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
            && image[newRow][newCol] == iniColor){
                dfs(newRow, newCol, ans, image, iniColor, newColor, directions);
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Cardinal directions
    return ans;
}

int main(){
    
}