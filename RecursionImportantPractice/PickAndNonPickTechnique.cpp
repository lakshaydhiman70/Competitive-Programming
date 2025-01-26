#include<bits/stdc++.h>
using namespace std;


/*
    what are all the subsequences of an array: [3, 1, 2]
    what is a subsequence means: A contiguous or non contogus sequence which follows the order

    Subsequences: [], [3], [1], [2], [3, 1], [3, 2], [1, 2], [3, 1, 2];

    [3, 2, 1] is not a subsequence.
*/


void printSubsequences(int ind, vector<int>&inp, vector<int>&ans){
    
    if(ind >= inp.size()){
        for(int i=0; i < ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }

    ans.push_back(inp[ind]);
    printSubsequences(ind + 1, inp, ans);
    ans.pop_back();
    printSubsequences(ind + 1, inp, ans);
}

int main(){
    vector<int>inp = {3, 1, 2};
    vector<int>ans;
    printSubsequences(0, inp, ans);
}