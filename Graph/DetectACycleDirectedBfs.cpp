#include<bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<vector<int>>& adj){
    vector<int>indegree(n, 0);
    for(int i=0;i<n;i++){
        for(auto val: adj[i]){
            indegree[val]++;
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
        int front = que.front();
        que.pop();
        count++;

        for(auto edge: adj[front]){
            indegree[edge]--;
            if(indegree[edge] == 0){
                que.push(edge);
            }
        }
    }

    return count != n;
}

int main(){
    int n = 7;
    vector<vector<int>>graph(n, vector<int>());
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(5);
    graph[5].push_back(6);

    if (bfs(n, graph) == true) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
}


//  Kahn's algorithm is a well-known method for detecting cycles in a directed graph. 
// It is also used for topological sorting. 
// The algorithm operates by iteratively removing nodes with no incoming edges and updating the graph. 
// If, at the end of this process, there are still nodes left in the graph, 
// it indicates the presence of a cycle. 