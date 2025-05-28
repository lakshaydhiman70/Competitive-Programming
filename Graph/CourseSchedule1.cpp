#include<bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>>& prerequisites) {

    vector<vector<int>> graph(n);

    for (const auto& pair : prerequisites) {
        graph[pair[0]].push_back(pair[1]);
    }

    vector<int>indegree(n);

    for(int i=0;i<n;i++){
        for(auto it: graph[i]){
            indegree[it]++;
        }
    }

    queue<int>que;
    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            que.push(i);
        }
    }

    int count = 0;

    while (!que.empty()){
        auto front = que.front();
        count++;
        for(auto edge: graph[front]){
            indegree[edge]--;
            if(indegree[edge] == 0){
                que.push(edge);
            }
        }
    }
    return n != count;
}

int main(){

}