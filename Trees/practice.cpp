#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void preorder(Node* root){
    if(root == nullptr)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Inorder(Node* root){
	if(root == nullptr)return;
	
	Inorder(root -> left);
	cout<<root->data<<" ";
	Inorder(root -> right);
}

void postorder(Node* root){
	if(root == nullptr)return;
	
	postorder(root -> left);
	postorder(root -> right);
	cout<<root->data<<" ";
}

void iterativePreorder(Node* root){
	if (root == nullptr) return;
	stack<Node*> st;
	st.push(root);

	while (!st.empty()) {
		Node* curr = st.top();
		st.pop();
		cout << curr->data << " ";
		
		if(curr->right != nullptr){
			st.push(curr->right);
		}
		if(curr->left != nullptr){
			st.push(curr->left);
		}
	}
}

void iterativeInorder(Node* root){
	if (root == nullptr) return;
	stack<Node*> st;
	Node* curr = root;

	while (!st.empty() || curr != nullptr) {
		if (curr != nullptr) {
			st.push(curr);
			curr = curr->left;
		} else {
			curr = st.top();
			st.pop();
			cout << curr->data << " ";
			curr = curr->right;
		}
	}
}

void iterativePostorder(Node* root){
	if (root == nullptr) return;
	stack<Node*> st1, st2;
	st1.push(root);

	while (!st1.empty()) {
		Node* curr = st1.top();
		st1.pop();
		st2.push(curr);

		if (curr->left != nullptr) {
			st1.push(curr->left);
		}
		if (curr->right != nullptr) {
			st1.push(curr->right);
		}
	}

	while (!st2.empty()) {
		Node* curr = st2.top();
		st2.pop();
		cout << curr->data << " ";
	}
}

int height(Node* root){
	if(!root){
		return 0;
	}
	
	int left = height(root -> left);
	int right = height(root -> right);
	
	return max(left, right) + 1;
}

bool isBalanced(Node* root){
	if(!root){
		return true;
	}
	
	int left = 0, right = 0;
	
	if(abs(height(root->left) - height(root->right)) > 1){
		return false;
	}
	
	return isBalanced(root -> left) && isBalanced(root -> right);
}

int main(){

    // -------- Balanced Tree --------
    /*
            1
          /   \
         2     3
        / \   /
       4   5 6
    */

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);

    cout << "Tree 1 Balanced? ";
    cout << (isBalanced(root1) ? "Yes" : "No") << endl;


    // -------- Unbalanced Tree --------
    /*
            1
           /
          2
         /
        3
       /
      4
    */

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    root2->left->left->left = new Node(4);

    cout << "Tree 2 Balanced? ";
    cout << (isBalanced(root2) ? "Yes" : "No") << endl;

    return 0;
}