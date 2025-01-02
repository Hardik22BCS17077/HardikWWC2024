#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};

void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}


int main()
{
    Node* root=new Node(10);
    root->left=new Node(20); 
    root->left->left=new Node(15);
    root->left->right=new Node(25);
    root->right=new Node(30);
    root->right->right=new Node(35);
    root->right->right->right=new Node(40);
    cout<<"\nPostorder: ";
    postorder(root);
    return 0;
}
