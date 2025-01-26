#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>>&mat){
    if(j<0 || i > n ||j>=mat[i].size()){
        return 0;
    }

    if(i == n-1){
        return mat[i][j];
    }
    
    int down = solve(i+1, j, n, mat);
    int downleft = solve(i+1, j-1, n, mat);
    int downright = solve(i+1, j+1, n, mat);

    return mat[i][j] + max(down, max(downleft, downright));
}

int getMaxPathSum(vector<vector<int>> &mat){
    int n = mat.size();

    int ans = INT_MIN;

    for(int i=0;i<mat[0].size();i++){
        ans = max(ans, solve(0, i, n, mat));
    }

    return ans;
}

int main(){
    vector<vector<int>>mat = {{1, 2, 10, 4}, 
                              {100, 3, 2, 1},
                              {1, 1, 20, 2},
                              {1, 2, 2, 1}};
    int n = mat.size();
    cout<<getMaxPathSum(mat);
}