#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> val1, pair<int,int>val2){
    return val1.second > val2.second;
}

vector<int> jobSequencing(vector<int> &d, vector<int> &p) {
    vector<pair<int,int>>jobs;
    int n = d.size(), m = 0;

    for(int i=0; i<n; i++){
        m = max(m, d[i]);
        jobs.push_back({d[i], p[i]});
    }

    sort(jobs.begin(), jobs.end());

    vector<int>dp(m + 1);


    
}

int main(){

}