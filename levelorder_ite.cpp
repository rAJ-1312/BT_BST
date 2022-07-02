#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void levelorder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    Node* temp = root;

    while(temp){
        cout << temp->data << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
        temp = q.front();
        q.pop();
    }

}

int main(){

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(37);
    root->right->right->right = new Node(48);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    levelorder(root);


}