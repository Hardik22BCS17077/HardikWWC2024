/*Inorder Traversal */
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

//Depth First
void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
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
    //root->right->right->left=new Node(45);
    cout<<"Depth First:\nInorder: ";
    inorder(root);
}
