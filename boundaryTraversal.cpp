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

bool isLeaf(Node* root){
    if( root->left == NULL && root->right == NULL ) return true;
    return false;
}

void addleftboundary(Node* root, vector<int> &res){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addleafNodes(Node* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return ;
    }

    if(root->left) addleafNodes(root->left,res);
    if(root->right) addleafNodes(root->right,res);

}

void addrightboundary(Node* root, vector<int> &res){
    vector<int> temp;
    Node* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size() -1 ;i>=0;i--){
        res.push_back(temp[i]);
    }
}





vector<int> boundaryTraversal(Node* root){
    vector<int> res;
    if(root == NULL) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addleftboundary(root,res);
    addleafNodes(root,res);
    addrightboundary(root,res);

    return res;
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

    vector<int> v = boundaryTraversal(root);

    for(auto i : v){
        cout << i << " ";
    }


}