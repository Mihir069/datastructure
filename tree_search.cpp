#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *search(Node *root,int key){
    if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
int main(){
    Node *root = new Node(4);
    root -> left = new Node(3);
    root->right= new Node(5);
    root ->left->left = new Node(2);
    root->right->left =new Node(6);
    
    if(search(root,1)==NULL){
        cout<<"No key found";
    }
    else{
        cout<<"key exist";
    }
    return 0;
}