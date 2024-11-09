#include<bits/stdc++.h>
using namespace std;

int main() {
    // Initialize a max-heap priority queue
    priority_queue<int, vector<int>, greater<int>> pq;

    // Push elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Print and remove elements from the priority queue
    while (!pq.empty()) {
        cout << pq.top() << " "; // Output the top element
        pq.pop();                     // Remove the top element
    }

    return 0;
}
