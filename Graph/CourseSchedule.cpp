#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Create the adjacency list for the graph representation
    vector<vector<int>> graph(numCourses);
    // In-degrees of each course
    vector<int> in_degree(numCourses, 0);
    
    // Build the graph and compute in-degrees
    for (const auto& pair : prerequisites) {
        graph[pair[1]].push_back(pair[0]);
        in_degree[pair[0]]++;
    }
    
    // Queue for BFS
    queue<int> q;
    
    // Add all courses with in-degree 0 to the queue
    for (int i = 0; i < numCourses; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    // Count of courses that have been processed
    int processed_courses = 0;
    
    // Process the queue
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        processed_courses++;
        
        // Reduce the in-degree of each neighbor
        for (int neighbor : graph[course]) {
            in_degree[neighbor]--;
            // If in-degree becomes 0, add it to the queue
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // If the number of processed courses is equal to numCourses, there is no cycle
    return processed_courses == numCourses;
}

int main(){

}