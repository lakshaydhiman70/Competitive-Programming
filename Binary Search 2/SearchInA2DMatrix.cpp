#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = n * m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int i = mid / m;
        int j = mid % m;

        if (mat[i][j] == target) {
            return true;
        } else if (mat[i][j] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return false;
}


int main(){
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 8;
    cout<<searchMatrix(mat, target);
}