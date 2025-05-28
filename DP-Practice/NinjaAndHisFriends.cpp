#include<bits/stdc++.h>
using namespace std;

int solve(int i, int j, int i2, int j2, int n, int m, vector<vector<int>> &mat) {
    
    if(i < 0 || j < 0 || i2 < 0 || j2 < 0 || i >= n || j >= m || j2 >= m){
        return -1e9;
    }
    
    if(i == n-1){
        if(j == j2)return mat[i][j];
        else return mat[i][j] + mat[i2][j2];
    }

    int mx = INT_MIN;
    int ans = mat[i][j];
    for(int di = -1; di<=1; di++){
        for(int dj = -1; dj <= 1; dj++){
            if(di == dj){
                ans = mat[i][j] + solve(i, j + di, i2, j2 + dj, n, m, mat);
            }
            else{
                ans = mat[i][j] + mat[i2][j2] + solve(i, j + di, i2, j2 + dj, n, m, mat);
            }
            mx = max(mx, ans);
        }
    }

    return mx;
}

int maximumChocolates(int r, int c, vector<vector<int>> &mat) {
    return solve(0, 0, 0, c-1, r, c, mat);
}

int main(){
    /*
        3 4
        2 3 1 2
        3 4 2 2
        5 6 3 5
    */

   int n = 3, m = 4;
   vector<vector<int>>mat = {{2, 3, 1, 2},
                             {3, 4, 2, 2},
                             {5, 6, 3, 5}};

    cout<<maximumChocolates(n, m, mat);
}