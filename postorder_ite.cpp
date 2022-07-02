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


void postorder(Node* root){
    if(root == NULL) return ;
    stack<Node*> s1;
    stack<int> s2;
    s1.push(root);

    while(!s1.empty()){
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp->data);
        if(temp->left != NULL) s1.push(temp->left);
        if(temp->right != NULL) s1.push(temp->right);
    }

    while(!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
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

    postorder(root);


}