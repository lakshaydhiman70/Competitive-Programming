#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix[0].size();

    for(int i=0; i<n; i++){
        for(int j = i; j < n; j++){
            int temp = matrix[i][j];
            int temp2 = matrix[j][i];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());    
    }
}

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    for(auto res: matrix){
        for(auto ele: res){
            cout << ele << " ";
        }
        cout << endl;
    }
}