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

vector<vector<int>> zigzagLOT(Node* root){
    vector<vector<int>> v;
    if(root == NULL) return v;

    queue<Node*> q;
    q.push(root);
    bool left_right = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> tmp(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            int index = left_right ? i : size-1-i;
            tmp[index] = temp->data;
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        left_right = !left_right;
        v.push_back(tmp);
    }

    return v;
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

    vector<vector<int>> res;

    res = zigzagLOT(root);

    for(auto vec : res){
        for(auto i : vec){
            cout << i << " ";
        }
    }


}