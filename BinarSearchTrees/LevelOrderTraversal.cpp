#include <bits/stdc++.h>
using namespace std;

struct Node {
    // Defining value of the node.
    int data;

    // Left reference ptr to the node.
    struct Node* left;

    // Right reference ptr to the node.
    struct Node* right;

    // Method to initialize the above values.
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> levelOrdertTraversal(Node* root){
    vector<vector<int>>ans;
    if(root == NULL)return ans;
    queue<Node*> que;
    que.push(root);

    while(!que.empty()){
        int size = que.size();
        vector<int>level;
        for(int i = 0; i<size; i++){
            Node* frontnode = que.front();
            que.pop();
            if(frontnode->left != NULL) que.push(frontnode->left); 
            if(frontnode->right != NULL) que.push(frontnode->right); 
            level.push_back(frontnode->data); 
        }
        ans.push_back(level);
    }

    return ans;
}

int main() {
    // Creating a new node by using dynamic allocation.
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    auto ans = levelOrdertTraversal(root);

    for(auto res: ans){
        for(auto value: res){
            cout<<value<<" ";
        }
        cout<<endl;
    }

    return 0;
}
