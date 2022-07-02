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

bool isSameBT(Node* root1, Node* root2){
    if(root1 == NULL || root2 == NULL)
        return root1==root2;

    return (root1->data == root2->data) && isSameBT(root1->left, root2->left) && isSameBT(root1->right, root2->right);
}


int main(){

    Node* root1 = new Node(20);
    root1->left = new Node(8);
    root1->right = new Node(22);
    root1->right->right = new Node(37);
    root1->right->right->right = new Node(48);
    root1->left->left = new Node(4);
    root1->left->right = new Node(12);
    root1->left->right->left = new Node(10);
    root1->left->right->right = new Node(14);

    Node* root2 = new Node(20);
    root2->left = new Node(8);
    root2->right = new Node(28);
    root2->right->right = new Node(37);
    root2->right->right->right = new Node(48);
    root2->left->left = new Node(4);
    root2->left->right = new Node(12);
    root2->left->right->left = new Node(10);
    root2->left->right->right = new Node(14);

    cout << isSameBT(root1,root2);


}