#include<bits/stdc++.h>
using namespace std;

void ShortestPathUsingBFS(){

}

int main(){
    int n = 9;
    vector<vector<pair<int,int>>>adj(n);

    adj[0].push_back({1, 1});
    adj[0].push_back({3, 1});
    adj[1].push_back({1, 1});
    adj[2].push_back({1, 1});
    adj[3].push_back({0, 1});
    adj[3].push_back({1, 1});
    adj[3].push_back({4, 1});
    adj[4].push_back({1, 1});
    adj[5].push_back({4, 1});
    adj[5].push_back({6, 1});
    adj[6].push_back({5, 1});
    adj[6].push_back({2, 1});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 1});
    adj[7].push_back({8, 1});
    adj[7].push_back({6, 1});
    adj[8].push_back({7, 1});
    adj[8].push_back({6, 1});
}