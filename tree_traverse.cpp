#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int var){
        data = var;
        left = NULL;
        right = NULL;
    }
};
void preorder(class Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(class Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void inorder(class Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node *root = new Node(4);
    root -> left = new Node(3);
    root->right= new Node(5);
    root ->left->left = new Node(2);
    root->right->left =new Node(6);
    cout<<"\npreorder tree :";
    preorder(root);
    cout<<"\npostorder tree :";
    postorder(root);
    cout<<"\ninorder tree :";
    inorder(root);
    return 0;
}