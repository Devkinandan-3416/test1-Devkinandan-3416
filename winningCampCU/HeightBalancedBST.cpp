#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

class BST{
    public:
        void dfs(int newVal, Node* node) {
            if(!node->left || !node->right) return;
            Node* newNode = new Node(newVal);
            if(newVal < node->val) {
                dfs(newVal, node->left);
                node->left->val = newVal;
            } else {
                dfs(newVal, node->right);
                node->right->val = newVal;
            }
        }

        void display(Node* root) {
            if(!root) {
                return;
            }
            display(root->left);
            cout<<root->val;
            display(root->right);
        }
};

int main() {
    int n;
    cout<<"Enter Array elements : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Node* root = new Node(arr[0]);

    BST bst;
    for(int i=1; i<n; i++) {
        Node* newNode = new Node(arr[i]);
        bst.dfs(arr[i], root);
    }

    bst.display(root);
}