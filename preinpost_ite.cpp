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


vector<vector<int>> postorder(Node* root){
    vector<vector<int>> res;
    if(root == NULL) return res;
    vector<int> pre, in ,post;
    stack<pair<Node*,int>> s;

    s.push({root,1});


    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left!=NULL) s.push({it.first->left,1});
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right!=NULL) s.push({it.first->right,1});
        }else{
            post.push_back(it.first->data);
        }
    }

    res.push_back(pre);
    res.push_back(in);
    res.push_back(post);

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

    vector<vector<int>> result;


    result = postorder(root);

    for(auto i : result){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

}