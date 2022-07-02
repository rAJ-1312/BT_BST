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

int maxPathSum(Node* root, int &maxi){
    if( root == NULL) return 0;

    int lh = max(0,maxPathSum(root->left,maxi));
    int rh = max(0,maxPathSum(root->right,maxi));

    maxi = max(maxi, lh+rh+root->data);

    return max(lh,rh) + root->data;
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

    int maxi = INT_MIN;
    maxPathSum(root,maxi);

   cout << maxi;


}