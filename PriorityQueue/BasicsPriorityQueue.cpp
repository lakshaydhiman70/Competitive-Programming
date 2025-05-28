#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;

    priority_queue<int, std::vector<int>, std::greater<int>> pq_min_heap; //min heap.

    // Adding elements
    pq.push(10);
    pq.push(20);
    pq.push(5);

    // Printing elements in priority order
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
