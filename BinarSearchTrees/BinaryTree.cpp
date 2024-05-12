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

/// @brief root -> left -> right
/// @param root 
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

/// @brief left -> root -> right
/// @param root 
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

/// @brief left -> right -> root
/// @param root 
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0; // Add a return statement
}


