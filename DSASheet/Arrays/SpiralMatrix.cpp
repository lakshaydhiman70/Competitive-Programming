#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int>ans;
    int leftptr = 0, rightptr = m-1, topptr = 0, bottomptr = n-1;
    while(topptr <= bottomptr && leftptr <= rightptr){
        for(int i = leftptr; i<=rightptr; i++){
            ans.push_back(matrix[topptr][i]);
        }
        topptr++;

        for(int i = topptr; i<=bottomptr; i++){
            ans.push_back(matrix[i][rightptr]);
        }

        rightptr--;

        if(topptr <= bottomptr){
            for(int i = rightptr; i>=leftptr; i--){
                ans.push_back(matrix[bottomptr][i]);
            }
            bottomptr--;
        }
        if(leftptr <= rightptr){
            for(int i = bottomptr; i>= topptr; i--){
                ans.push_back(matrix[i][leftptr]);
            }
            leftptr++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8}, {9, 10, 11, 12}};
    vector<int> ans = spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}