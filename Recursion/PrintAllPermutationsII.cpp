#include<bits/stdc++.h>
using namespace std;
void swap(vector<int>&vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}
void printVectorOfVectors(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout <<endl;
    }
}
void printAllPermutationsII(int ind, int n, vector<int>&v , vector<int>&vec, vector<vector<int>>&ans,map<int,int>&mp){
    if(ind == n){
        ans.push_back(v);
        return;
    }
    for(int i = ind; i<n ;i++){
        swap(v,i,ind);
        printAllPermutationsII(ind+1, n, v, vec, ans,mp);
        swap(v,i,ind);
    }
    
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>vec;
    map<int,int>mp;
    vector<vector<int>>ans;
    printAllPermutationsII( 0, n, v, vec, ans,mp);
    printVectorOfVectors(ans);
}