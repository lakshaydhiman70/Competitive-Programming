#include<bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>> &mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int row = 0, col = m-1;

    while(col >= 0 && row < n){

        if(mat[row][col] == target){
            return true;
        }
        else if(mat[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>mat = { {1, 3, 7}, {10, 12, 15}, {19, 20, 21} };
    cout<<searchElement(mat, 12);
}