#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<int>>& mat, int n){
    if(i == n-1){
        return mat[i][j];
    }

    int down = solve(i + 1, j, mat, n);
    int diagonal = solve(i + 1, j + 1, mat, n);

    return mat[i][j] + min(down, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){

    return solve(0, 0, triangle, n);
}

int main(){
    vector<vector<int>>mat = {{1}, 
                              {2, 3},
                              {3, 6, 7},
                              {8, 9, 6, 10}};
    int n = mat.size();
    // solve(mat, n, 1);
}