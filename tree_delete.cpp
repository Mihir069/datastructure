#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    int key;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
// Node *search(Node *root,int key){
//     if(root->data == key){
//         return root;
//     }
//     else if(root->data > key){
//         return search(root->left,key);
//     }
//     else{
//         return search(root->right,key);
//     }
// }
Node *inorderSucc(Node *root){
    Node *current = root;
    while(current && current->left != NULL){
        current=current->left;
    }
    return current;
}
Node *deletebst(Node *root,int key){
    if(key<root->data){
        root->left = deletebst(root->left,key);
    }
    else if(key>root->data){
        root->right = deletebst(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deletebst(root->right,temp->key);
    }
    return root;
}
void inorder(Node *root){
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
    
    // if(search(root,1)==NULL){
    //     cout<<"No key found";
    // }
    // else{
    //     cout<<"key exist";
    // }
    root = deletebst(root,5);
    inorder(root);
    return 0;
}