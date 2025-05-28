#include<bits/stdc++.h>
using namespace std;

void initializeMaxHeap(){
    priority_queue<int>max_heap;
    max_heap.push(6);
    max_heap.push(3);
    max_heap.push(7);
    max_heap.push(9);

    //9, 7, 6, 3
    cout<<"Max-Heap: ";
    while(!max_heap.empty()){
        cout<<max_heap.top()<<" ";
        max_heap.pop();
    }
    cout<<endl;
}

void initializeMinHeap(){
    priority_queue<int, vector<int>, greater<int>>min_heap;

    min_heap.push(8);
    min_heap.push(1);
    min_heap.push(4);
    min_heap.push(16);
    min_heap.push(64);

    cout<<"Min-Heap: ";

    while(!min_heap.empty()){
        cout<<min_heap.top()<<" ";
        min_heap.pop();
    }
    cout<<endl;
}

int main() {
    cout << "Initializing Max-Heap..." << endl;
    initializeMaxHeap();

    cout << "Initializing Min-Heap..." << endl;
    initializeMinHeap();

    return 0;
}